/*******************************************************************************
 * 文件名称: il2cpp_reflector
 * 项目名称: IL2CppReflector
 * 创建时间: 25-7-23
 * 作者: EternalFuture゙
 * Github: https://github.com/2079541547
 * 版权声明: Copyright © 2025 EternalFuture. All rights reserved.
 *
 * MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *******************************************************************************/

#include "IL2CppReflector/il2cpp_reflector.hpp"

#include "IL2CppReflector/class.hpp"
#include "IL2CppReflector/logger.hpp"
#include "IL2CppReflector/method.hpp"
#include "IL2CppReflector/api/api_ptr.hpp"
#include "IL2CppReflector/type.hpp"

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

static bool is_inited_sym = false;

void IL2CppReflector::HookWrapper::SetHookFun(hookFunc hook_func, unHookFunc un_hook_func) {
    ILRL_LOG_DEBUG("[HookWrapper::SetHookFun] Setting hook functions");
    Hook = hook_func;
    UnHook = un_hook_func;

    if (!Hook || !UnHook) {
        ILRL_LOG_WARN("[HookWrapper::SetHookFun] One or both hook functions are null");
    }
}

bool IL2CppReflector::HookWrapper::DoHook(const Info& info) {
    if (!Hook) {
        ILRL_LOG_ERROR("[HookWrapper::DoHook] Hook function not set");
        return false;
    }

    ILRL_LOG_DEBUG("[HookWrapper::DoHook] Attempting to hook at address:", info.address);
    const bool result = Hook(info);

    if (result) {
        ILRL_LOG_DEBUG("[HookWrapper::DoHook] Successfully hooked at address:", info.address);
    } else {
        ILRL_LOG_ERROR("[HookWrapper::DoHook] Failed to hook at address:", info.address);
    }

    return result;
}

bool IL2CppReflector::HookWrapper::DoUnHook(void* address) {
    if (!UnHook) {
        ILRL_LOG_ERROR("[HookWrapper::DoUnHook] Unhook function not set");
        return false;
    }

    ILRL_LOG_DEBUG("[HookWrapper::DoUnHook] Attempting to unhook at address:", address);
    const bool result = UnHook(address);

    if (result) {
        ILRL_LOG_DEBUG("[HookWrapper::DoUnHook] Successfully unhooked at address:", address);
    } else {
        ILRL_LOG_ERROR("[HookWrapper::DoUnHook] Failed to unhook at address:", address);
    }

    return result;
}

void IL2CppReflector::AddOnLoadedEvent(const std::function<void()>& even) {
    if (!even) {
        ILRL_LOG_WARN("[AddOnLoadedEvent] Attempted to add null event function");
        return;
    }

    ILRL_LOG_DEBUG("[AddOnLoadedEvent] Adding new on-loaded event");
    OnLoadedEvents.push_back(even);

    ILRL_LOG_TRACE("[AddOnLoadedEvent] Total events registered:", OnLoadedEvents.size());
}

int IL2CppReflector::hook_il2cpp_init(const char* domain_name) {
    ILRL_LOG_DEBUG("[hook_il2cpp_init] IL2CPP initialization started, domain:", domain_name);

    const auto r = old_il2cpp_init(domain_name);

    if (!HookWrapper::DoUnHook(reinterpret_cast<void*>(Il2CppAPI::il2cpp_init))) ILRL_LOG_WARN("Unhooking failed: ", reinterpret_cast<void*>(Il2CppAPI::il2cpp_init));

    // Type system initialization
    if (!init_type()) {
        ILRL_LOG_ERROR("[hook_il2cpp_init] Type initialization failed");
    } else {
        ILRL_LOG_DEBUG("[hook_il2cpp_init] Type initialization successful");
    }

    // Reflection system initialization
    if (!init_ref()) {
        ILRL_LOG_ERROR("[hook_il2cpp_init] Reflection initialization failed");
    } else {
        ILRL_LOG_DEBUG("[hook_il2cpp_init] Reflection initialization successful");
    }

    // Execute registered events
    ILRL_LOG_DEBUG("[hook_il2cpp_init] Executing", OnLoadedEvents.size(), "v");
    for (const auto& on_loaded_event : OnLoadedEvents) {
        try {
            on_loaded_event();
        } catch (const std::exception& e) {
            ILRL_LOG_ERROR("[hook_il2cpp_init] Event handler threw exception:", e.what());
        } catch (...) {
            ILRL_LOG_ERROR("[hook_il2cpp_init] Event handler threw unknown exception");
        }
    }

    ILRL_LOG_DEBUG("[hook_il2cpp_init] IL2CPP initialization completed, return value:", r);
    return r;
}

bool IL2CppReflector::init_from_handle(void* handle) {
    ILRL_LOG_DEBUG("Initializing IL2CppReflector from handle: ", handle);

    if (!init_sym(handle)) {
        ILRL_LOG_ERROR("Symbol initialization failed");
        return false;
    }

    if (!HookWrapper::DoHook({ reinterpret_cast<void*>(Il2CppAPI::il2cpp_init),
        reinterpret_cast<void*>(hook_il2cpp_init),
        reinterpret_cast<void**>(&old_il2cpp_init)})) {
        ILRL_LOG_ERROR("Hook il2cpp_init failed");
        return false;
    }


    ILRL_LOG_INFO("IL2CppReflector initialized successfully");
    return true;
}

bool IL2CppReflector::init_sym(void* handle) {
    ILRL_LOG_DEBUG("Starting symbol initialization");

    if (!handle) {
        ILRL_LOG_ERROR("Invalid handle provided (nullptr)");
        return false;
    }

    bool anySymbolFound = false;
    size_t foundCount = 0;
    size_t totalSymbols = Il2CppAPI::api_ptr.size();

    for (auto [symbolName, symbolPointer] : Il2CppAPI::api_ptr) {
        void* sym_ptr = nullptr;

#ifdef _WIN32
        ILRL_LOG_DEBUG("Looking up symbol '", symbolName,"' using GetProcAddress");
        sym_ptr = GetProcAddress(static_cast<HMODULE>(handle), symbolName);
#else
        sym_ptr = dlsym(handle, symbolName);
#endif

        if (sym_ptr) {
            *symbolPointer = sym_ptr;
            foundCount++;
            anySymbolFound = true;
        } else {
            ILRL_LOG_WARN("Failed to find symbol: ", symbolName);

#ifdef _WIN32
            DWORD error = GetLastError();
            if (error != 0) {
                ILRL_LOG_ERROR("Windows API error code: ", error);
            }
#else
            if (const char* dlerror_msg = dlerror()) {
                ILRL_LOG_ERROR("dlerror: ", dlerror_msg);
            }
#endif
        }
    }

    if (!anySymbolFound) {
        ILRL_LOG_ERROR("No symbols were found in the provided handle");
        return false;
    }

    ILRL_LOG_INFO("Symbol initialization completed. Found ", foundCount, "/", totalSymbols, " symbols (", (foundCount * 100.0) / totalSymbols, ")");

    is_inited_sym = true;
    return true;
}

bool IL2CppReflector::init_ref() {
    ILRL_LOG_DEBUG("Starting reflection initialization");

    if (!is_inited_sym) {
        ILRL_LOG_ERROR("Cannot initialize reflection - symbols not initialized");
        return false;
    }

    ILRL_LOG_DEBUG("Getting corlib image");
    const auto image = Il2CppAPI::il2cpp_get_corlib();
    if (!image) {
        ILRL_LOG_ERROR("Failed to get corlib image");
        return false;
    }

    ILRL_LOG_DEBUG("Initializing MakeGenericMethod_impl");
    MakeGenericMethod_impl = Class("System.Reflection", "RuntimeMethodInfo", image).GetMethod("MakeGenericMethod_impl");
    if (!MakeGenericMethod_impl.IsValid()) {
        ILRL_LOG_DEBUG("RuntimeMethodInfo.MakeGenericMethod_impl not found, trying MonoMethod");

        MakeGenericMethod_impl = Class("System.Reflection", "MonoMethod", image).GetMethod("MakeGenericMethod_impl");
    }

    if (!MakeGenericMethod_impl.IsValid()) {
        ILRL_LOG_ERROR("Failed to initialize MakeGenericMethod_impl");
        return false;
    }

    ILRL_LOG_DEBUG("Initializing MakeGenericType");
    MakeGenericType = Class("System", "RuntimeType", image).GetMethod("MakeGenericType", 2);
    if (!MakeGenericType.IsValid()) {
        ILRL_LOG_ERROR("Failed to initialize MakeGenericType");
        return false;
    }

    ILRL_LOG_INFO("Reflection initialized successfully");
    return true;
}

bool IL2CppReflector::init_type() {
    ILRL_LOG_DEBUG("Starting type initialization");

    if (!is_inited_sym) {
        ILRL_LOG_ERROR("Cannot initialize types - symbols not initialized");
        return false;
    }

    ILRL_LOG_DEBUG("Getting corlib image");
    const auto image = Il2CppAPI::il2cpp_get_corlib();
    if (!image) {
        ILRL_LOG_ERROR("Failed to get corlib image");
        return false;
    }

    constexpr auto system_namespace = "System";
    ILRL_LOG_INFO("Initializing basic types from namespace: ", system_namespace);

    // Initialize basic types with detailed logging
#define INIT_TYPE(type_name) \
    do { \
        Type::type_name = Type::GetType(image, system_namespace, #type_name); \
        if (!Type::type_name) { \
            ILRL_LOG_WARN("Failed to initialize type: System.", #type_name); \
        } else { \
            ILRL_LOG_DEBUG("Initialized type: System.", #type_name, " at ", Type::type_name); \
        } \
    } while(0)

    INIT_TYPE(Void);
    INIT_TYPE(Boolean);
    INIT_TYPE(Byte);
    INIT_TYPE(SByte);
    INIT_TYPE(Int16);
    INIT_TYPE(UInt16);
    INIT_TYPE(Int32);
    INIT_TYPE(UInt32);
    INIT_TYPE(IntPtr);
    INIT_TYPE(UIntPtr);
    INIT_TYPE(Int64);
    INIT_TYPE(UInt64);
    INIT_TYPE(Single);
    INIT_TYPE(Double);
    INIT_TYPE(Decimal);
    INIT_TYPE(String);
    INIT_TYPE(Object);

    ILRL_LOG_INFO("Type initialization completed");
    return true;
}