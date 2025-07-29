/*******************************************************************************
 * 文件名称: method
 * 项目名称: IL2CppReflector
 * 创建时间: 25-7-25
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

#include "IL2CppReflector/method.hpp"

#include "IL2CppReflector/api/method.hpp"
#include "IL2CppReflector/api/type.hpp"

#include "IL2CppReflector/logger.hpp"
#include "IL2CppReflector/struct.hpp"

void IL2CppReflector::Method::SetInstance(void* Instance) {
    ILRL_LOG_DEBUG("[Method::SetInstance] Setting instance to:", Instance);
    _instance = Instance;
    ILRL_LOG_TRACE("[Method::SetInstance] Instance set successfully");
}

bool IL2CppReflector::Method::IsGeneric() const {
    if (!_method) {
        ILRL_LOG_WARN("[Method::IsGeneric] Called on null method pointer");
        return false;
    }
    bool result = Il2CppAPI::il2cpp_method_is_generic(_method);
    ILRL_LOG_DEBUG("[Method::IsGeneric] Method is generic:", _method, "Result:", result);
    return result;
}

bool IL2CppReflector::Method::IsInflated() const {
    if (!_method) {
        ILRL_LOG_WARN("[Method::IsInflated] Called on null method pointer");
        return false;
    }
    bool result = Il2CppAPI::il2cpp_method_is_inflated(_method);
    ILRL_LOG_DEBUG("[Method::IsInflated] Method is inflated:", _method, "Result:", result);
    return result;
}

bool IL2CppReflector::Method::IsInstance() const {
    if (!_method) {
        ILRL_LOG_WARN("[Method::IsInstance] Called on null method pointer");
        return false;
    }
    bool result = Il2CppAPI::il2cpp_method_is_instance(_method);
    ILRL_LOG_DEBUG("[Method::IsInstance] Method is instance method: ", _method, " Result: ", result);
    return result;
}

std::string IL2CppReflector::Method::GetReturnType() const {
    if (!_method) {
        ILRL_LOG_ERROR("[Method::GetReturnType] Called on null method pointer");
        return "null";
    }

    void* returnType = Il2CppAPI::il2cpp_method_get_return_type(_method);
    if (!returnType) {
        ILRL_LOG_ERROR("[Method::GetReturnType] Failed to get return type for method:", _method);
        return "unknown";
    }

    const char* typeName = Il2CppAPI::il2cpp_type_get_name(returnType);
    if (!typeName) {
        ILRL_LOG_ERROR("[Method::GetReturnType] Failed to get type name for return type:", returnType);
        return "unnamed";
    }

    ILRL_LOG_DEBUG("[Method::GetReturnType] Method return type:", _method, "Type:", typeName);
    return typeName;
}

void* IL2CppReflector::Method::GetMethodPointer() const {
    if (!_method) {
        ILRL_LOG_ERROR("[Method::GetMethodPointer] Called on null method pointer");
        return nullptr;
    }

    void* result = *static_cast<void**>(_method);
    ILRL_LOG_DEBUG("[Method::GetMethodPointer] Method: ",
                   Il2CppAPI::il2cpp_method_get_name(_method), " Pointer: ", result);
    return result;
}

void* IL2CppReflector::Method::GetMethodInfo() const {
    ILRL_LOG_DEBUG("[Method::GetMethodInfo] Returning raw method info:", _method);
    return _method;
}

IL2CppReflector::Method IL2CppReflector::Method::GetGeneric(const std::vector<void*>& templateTypes) const {
    if (!_method) {
        ILRL_LOG_ERROR("[Method::GetGeneric] Called on null method pointer");
        return *this;
    }

    if (!IsGeneric()) {
        ILRL_LOG_ERROR("[Method::GetGeneric] Method is not generic:", _method);
        return *this;
    }

    ILRL_LOG_DEBUG("[Method::GetGeneric] Creating generic method:",
                  _method, "Type arguments count:", templateTypes.size());

    void* MethodClass = Il2CppAPI::il2cpp_method_get_declaring_type(_method);
    if (!MethodClass) {
        ILRL_LOG_ERROR("[Method::GetGeneric] Failed to get declaring type for method:", _method);
        return *this;
    }

    void* reflectionMethod = Il2CppAPI::il2cpp_method_get_object(_method, MethodClass);
    if (!reflectionMethod) {
        ILRL_LOG_ERROR("[Method::GetGeneric] Failed to get method object for method:", _method);
        return *this;
    }

    const auto args = UnityStruct::array<void*>::create(templateTypes);
    if (!args) {
        ILRL_LOG_ERROR("[Method::GetGeneric] Failed to create type arguments array");
        return *this;
    }

    MakeGenericMethod_impl.SetInstance(reflectionMethod);
    const auto genericMethod = MakeGenericMethod_impl.Invoke<void*>(args.get());
    if (!genericMethod) {
        ILRL_LOG_ERROR("[Method::GetGeneric] MakeGenericMethod invocation failed");
        return *this;
    }

    void* concreteMethod = Il2CppAPI::il2cpp_method_get_from_reflection(genericMethod);
    if (!concreteMethod) {
        ILRL_LOG_ERROR("[Method::GetGeneric] Failed to get concrete method from reflection");
        return *this;
    }

    ILRL_LOG_DEBUG("[Method::GetGeneric] Successfully created generic method instance:", concreteMethod);
    return Method(concreteMethod);
}