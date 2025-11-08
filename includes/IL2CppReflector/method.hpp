/*******************************************************************************
 * 文件名称: method
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

#include <string>
#include <vector>
#include "class.hpp"
#include "logger.hpp"
#include "api/method.hpp"

namespace IL2CppReflector {

    class Method {
        protected:
            void *_method;
            void *_instance;

        public:
            Method() = default;

            explicit Method(void *method): _method(method), _instance(nullptr) {
            }

            void SetInstance(void *Instance);

            [[nodiscard]] bool IsGeneric() const;

            [[nodiscard]] bool IsInflated() const;

            [[nodiscard]] bool IsInstance() const;

            [[nodiscard]] bool IsValid() const noexcept { return _method; }

            [[nodiscard]] std::string GetReturnType() const;

            [[nodiscard]] void *GetMethodPointer() const;

            [[nodiscard]] void *GetMethodInfo() const;

            [[nodiscard]] Method GetGeneric(const std::vector<void *> &templateTypes) const;

            template<typename Ret, typename... Args>
            Ret Invoke(Args... args) {
                if (!_method) {
                    ILRL_LOG_ERROR("[Method::Invoke] Called on null method pointer");
                    if constexpr (std::is_pointer_v<Ret>) {
                        return nullptr;
                    } else {
                        return Ret();
                    }
                }

                const size_t expectedArgs = Il2CppAPI::il2cpp_method_get_param_count(_method);
                const size_t actualArgs = sizeof...(Args);
                const bool paramMatch = (expectedArgs == actualArgs);

                if (!paramMatch) {
                    ILRL_LOG_WARN("[Method::Invoke] Parameter count mismatch. Expected: ",
                                 expectedArgs, " Actual: ", actualArgs);
                }

                if (IsInstance()) {
                    if (!_instance) {
                        ILRL_LOG_ERROR("[Method::Invoke] Instance method called without instance");
                        if constexpr (std::is_pointer_v<Ret>) {
                            return nullptr;
                        } else {
                            return Ret();
                        }
                    }

                    if (paramMatch) {
                        return reinterpret_cast<Ret(*)(void*, Args..., void*)>(GetMethodPointer())(
                            _instance, args..., _method);
                    }

                    return reinterpret_cast<Ret(*)(void*, Args...)>(GetMethodPointer())(
                        _instance, args...);
                }

                if (paramMatch) {
                    return reinterpret_cast<Ret(*)(Args..., void*)>(GetMethodPointer())(
                        args..., _method);
                }

                return reinterpret_cast<Ret(*)(Args...)>(GetMethodPointer())(args...);
            }
    };

    /**
     * @return void* - Il2CppReflectionMethod*
     */
    inline Method MakeGenericMethod_impl;


    /**
     * @return void* - MonoType*
     */
    inline Method MakeGenericType;
}


template<typename ... Args>
void *IL2CppReflector::Class::CreateNewObjectParameters(Args... args) {
    const auto instance = CreateNewInstance();
    if (!instance) {
        ILRL_LOG_ERROR("[Class::CreateNewObjectParameters] Failed to create new instance");
        return nullptr;
    }

    auto ctor = GetMethod(".ctor", sizeof...(Args));
    if (!ctor.IsValid()) {
        ILRL_LOG_ERROR("[Class::CreateNewObjectParameters] Constructor not found");
        return instance;  // Return instance even if construction fails
    }

    ctor.SetInstance(instance);
    ctor.Invoke<void>(args...);

    return instance;
}