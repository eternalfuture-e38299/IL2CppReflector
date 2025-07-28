/*******************************************************************************
 * 文件名称: field
 * 项目名称: TEFModLoader
 * 创建时间: 25-7-24
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

#include "IL2CppReflector/field.hpp"

#include "IL2CppReflector/api/field.hpp"
#include "IL2CppReflector/api/type.hpp"

#include "IL2CppReflector/logger.hpp"
#include "IL2CppReflector/api/class.hpp"

bool IL2CppReflector::Field::IsStatic() const {
    if (!_field) {
        ILRL_LOG_ERROR("[Field::IsStatic] Called on null field pointer");
        return false;
    }

    const auto type = Il2CppAPI::il2cpp_field_get_type(_field);
    if (!type) {
        ILRL_LOG_ERROR("[Field::IsStatic] Failed to get field type for field:", _field);
        return false;
    }

    bool result = (Il2CppAPI::il2cpp_type_get_attrs(type) & 0x0010) != 0 && !IsThreadStatic();
    ILRL_LOG_DEBUG("[Field::IsStatic] Field is static:", _field, "Result:", result);
    return result;
}

bool IL2CppReflector::Field::IsConst() const {
    if (!_field) {
        ILRL_LOG_ERROR("[Field::IsConst] Called on null field pointer");
        return false;
    }

    const auto type = Il2CppAPI::il2cpp_field_get_type(_field);
    if (!type) {
        ILRL_LOG_ERROR("[Field::IsConst] Failed to get field type for field:", _field);
        return false;
    }

    bool result = (Il2CppAPI::il2cpp_type_get_attrs(type) & 0x0040) != 0;
    ILRL_LOG_DEBUG("[Field::IsConst] Field is const:", _field, "Result:", result);
    return result;
}

bool IL2CppReflector::Field::IsThreadStatic() const {
    if (!_field) {
        ILRL_LOG_ERROR("[Field::IsThreadStatic] Called on null field pointer");
        return false;
    }

    bool result = Il2CppAPI::il2cpp_field_get_offset(_field) == -1;
    ILRL_LOG_DEBUG("[Field::IsThreadStatic] Field is thread static:", _field, "Result:", result);
    return result;
}

void IL2CppReflector::Field::SetInstance(void* Instance) {
    if (!Instance) {
        ILRL_LOG_WARN("[Field::SetInstance] Attempted to set null instance");
        return;
    }

    _instance = Instance;
    ILRL_LOG_DEBUG("[Field::SetInstance] Instance set to:", Instance, "for field:", _field);
}

void* IL2CppReflector::Field::GetFieldPtr() const {
    if (!_field) {
        ILRL_LOG_ERROR("[Field::GetFieldPtr] Called on null field pointer");
        return nullptr;
    }

    if (IsConst()) {
        ILRL_LOG_ERROR("[Field::GetFieldPtr] Cannot get pointer for const field:", _field);
        return nullptr;
    }

    if (IsThreadStatic()) {
        ILRL_LOG_ERROR("[Field::GetFieldPtr] Cannot get pointer for thread static field:", _field);
        return nullptr;
    }

    const auto offset = Il2CppAPI::il2cpp_field_get_offset(_field);
    const auto p_class = Il2CppAPI::il2cpp_field_get_parent(_field);

    if (!p_class) {
        ILRL_LOG_ERROR("[Field::GetFieldPtr] Failed to get parent class for field:", _field);
        return nullptr;
    }

    if (IsStatic()) {
        void* staticData = Il2CppAPI::il2cpp_class_get_static_field_data(p_class);
        if (!staticData) {
            ILRL_LOG_ERROR("[Field::GetFieldPtr] Failed to get static field data for class:", p_class);
            return nullptr;
        }

        auto result = reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(staticData) + offset);
        ILRL_LOG_DEBUG("[Field::GetFieldPtr] Static field pointer:", _field, "Address:", result);
        return result;
    }

    if (!_instance) {
        ILRL_LOG_ERROR("[Field::GetFieldPtr] Instance field called without instance");
        return nullptr;
    }

    const bool isValueType = Il2CppAPI::il2cpp_type_get_type(p_class) == 0x11;
    const uintptr_t addr = reinterpret_cast<uintptr_t>(_instance) + offset - (isValueType ? sizeof(void*) : 0x0);
    auto result = reinterpret_cast<void*>(addr);

    ILRL_LOG_DEBUG("[Field::GetFieldPtr] Instance field pointer:", _field,
                  "Instance:", _instance, "Address:", result, "IsValueType:", isValueType);
    return result;
}