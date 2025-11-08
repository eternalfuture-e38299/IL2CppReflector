/*******************************************************************************
 * 文件名称: field
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

#pragma once
#include "logger.hpp"
#include "api/field.hpp"

namespace IL2CppReflector {

    class Field {
        protected:
            void *_field;
            void *_instance;

        public:
            Field() = default;

            explicit Field(void *field): _field(field), _instance(nullptr) {
            }

            [[nodiscard]] bool IsValid() const noexcept { return _field; }

            [[nodiscard]] bool IsStatic() const;

            [[nodiscard]] bool IsConst() const;

            [[nodiscard]] bool IsThreadStatic() const;

            void SetInstance(void *Instance);

            [[nodiscard]] void *GetFieldPtr() const;

            template<typename T>
            T GetValue();

            template<typename T>
            T GetValue(void *Instance);

            template<typename T>
            void SetValue(T value);

            template<typename T>
            void SetValue(void* Instance, T value);
    };
}

template<typename T>
T IL2CppReflector::Field::GetValue() {
    if (!_field) {
        ILRL_LOG_ERROR("[Field::GetValue] Called on null field pointer");
        return T{};
    }

    // Handle special field types
    if (IsConst() || IsThreadStatic()) {
        T val{};
        Il2CppAPI::il2cpp_field_static_get_value(_field, reinterpret_cast<void*>(&val));
        return val;
    }

    // Normal field case
    if (const T* ptr = static_cast<const T*>(GetFieldPtr()); ptr != nullptr)
        return *ptr;

    ILRL_LOG_ERROR("[Field::GetValue] Failed to get field pointer for: ", _field);
    return T{};
}

template<typename T>
T IL2CppReflector::Field::GetValue(void* Instance) {
    SetInstance(Instance);
    return GetValue<T>();
}

template<typename T>
void IL2CppReflector::Field::SetValue(T value) {
    if (!_field) {
        ILRL_LOG_ERROR("[Field::SetValue] Called on null field pointer");
        return;
    }

    if (IsConst()) {
        ILRL_LOG_ERROR("[Field::SetValue] Attempted to set const field:", _field);
        return;
    }

    // Handle thread static fields
    if (IsThreadStatic()) {
        Il2CppAPI::il2cpp_field_static_set_value(_field, &value);
        return;
    }

    // Normal field case
    if (T* ptr = static_cast<T*>(GetFieldPtr()); ptr != nullptr) {
        *ptr = value;
        return;
    }

    ILRL_LOG_ERROR("[Field::SetValue] Failed to get field pointer for: ", _field);
}

template<typename T>
void IL2CppReflector::Field::SetValue(void* Instance, T value) {
    SetInstance(Instance);
    SetValue<T>(value);
}