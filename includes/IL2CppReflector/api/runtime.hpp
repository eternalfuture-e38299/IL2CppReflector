/*******************************************************************************
 * 文件名称: runtime
 * 项目名称: IL2CppReflector
 * 创建时间: 25-7-22
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
#include "api_define.hpp"

namespace Il2CppAPI {
    /**
     * @brief 运行时方法调用
     * @param method 方法信息指针(原始类型: const MethodInfo*)
     * @param obj 对象实例
     * @param params 参数数组
     * @param exc [out] 异常对象(原始类型: Il2CppException**)
     * @return 调用结果(原始类型: Il2CppObject*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_runtime_invoke,
                      void* method, void* obj, void** params, void** exc)

    /**
     * @brief 运行时方法调用(带参数转换)
     * @param method 方法信息指针(原始类型: const MethodInfo*)
     * @param obj 对象实例
     * @param params 参数对象数组(原始类型: Il2CppObject**)
     * @param paramCount 参数数量
     * @param exc [out] 异常对象(原始类型: Il2CppException**)
     * @return 调用结果(原始类型: Il2CppObject*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_runtime_invoke_convert_args,
                      void* method, void* obj, void** params,
                      int paramCount, void** exc)

    /**
     * @brief 初始化类
     * @param klass 类指针(原始类型: Il2CppClass*)
     */
    DEFINE_IL2CPP_API(void, il2cpp_runtime_class_init, void* klass)

    /**
     * @brief 初始化对象
     * @param obj 对象指针(原始类型: Il2CppObject*)
     */
    DEFINE_IL2CPP_API(void, il2cpp_runtime_object_init, void* obj)

    /**
     * @brief 初始化对象(带异常处理)
     * @param obj 对象指针(原始类型: Il2CppObject*)
     * @param exc [out] 异常对象(原始类型: Il2CppException**)
     */
    DEFINE_IL2CPP_API(void, il2cpp_runtime_object_init_exception,
                      void* obj, void** exc)

    /**
     * @brief 设置未处理异常策略
     * @param value 策略值(原始类型: Il2CppRuntimeUnhandledExceptionPolicy)
     */
    DEFINE_IL2CPP_API(void, il2cpp_runtime_unhandled_exception_policy_set, int value)
}
