/*******************************************************************************
 * 文件名称: method
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

#include <cstdint>

#include "api_define.hpp"

namespace Il2CppAPI {
    /**
     * @brief 获取方法返回类型
     * @param method 方法信息指针(原始类型: const MethodInfo*)
     * @return 类型指针(原始类型: const Il2CppType*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_method_get_return_type, const void* method)

    /**
     * @brief 获取方法声明类
     * @param method 方法信息指针(原始类型: const MethodInfo*)
     * @return 类指针(原始类型: Il2CppClass*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_method_get_declaring_type, const void* method)

    /**
     * @brief 获取方法名称
     * @param method 方法信息指针(原始类型: const MethodInfo*)
     * @return 方法名称字符串
     */
    DEFINE_IL2CPP_API(const char*, il2cpp_method_get_name, const void* method)

    /**
     * @brief 从反射方法获取方法信息
     * @param method 反射方法对象(原始类型: const Il2CppReflectionMethod*)
     * @return 方法信息指针(原始类型: const MethodInfo*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_method_get_from_reflection, const void* method)

    /**
     * @brief 获取方法的反射对象
     * @param method 方法信息指针(原始类型: const MethodInfo*)
     * @param refclass 反射类(原始类型: Il2CppClass*)
     * @return 反射方法对象(原始类型: Il2CppReflectionMethod*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_method_get_object, const void* method, void* refclass)

    /**
     * @brief 检查方法是否为泛型方法
     * @param method 方法信息指针(原始类型: const MethodInfo*)
     * @return 是否为泛型方法
     */
    DEFINE_IL2CPP_API(bool, il2cpp_method_is_generic, const void* method)

    /**
     * @brief 检查方法是否为展开的泛型方法
     * @param method 方法信息指针(原始类型: const MethodInfo*)
     * @return 是否为展开的泛型方法
     */
    DEFINE_IL2CPP_API(bool, il2cpp_method_is_inflated, const void* method)

    /**
     * @brief 检查方法是否为实例方法
     * @param method 方法信息指针(原始类型: const MethodInfo*)
     * @return 是否为实例方法
     */
    DEFINE_IL2CPP_API(bool, il2cpp_method_is_instance, const void* method)

    /**
     * @brief 获取方法参数数量
     * @param method 方法信息指针(原始类型: const MethodInfo*)
     * @return 参数数量
     */
    DEFINE_IL2CPP_API(uint32_t, il2cpp_method_get_param_count, const void* method)

    /**
     * @brief 获取方法参数类型
     * @param method 方法信息指针(原始类型: const MethodInfo*)
     * @param index 参数索引
     * @return 类型指针(原始类型: const Il2CppType*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_method_get_param, const void* method, uint32_t index)

    /**
     * @brief 获取方法所属类
     * @param method 方法信息指针(原始类型: const MethodInfo*)
     * @return 类指针(原始类型: Il2CppClass*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_method_get_class, const void* method)

    /**
     * @brief 检查方法是否有指定特性
     * @param method 方法信息指针(原始类型: const MethodInfo*)
     * @param attr_class 特性类(原始类型: Il2CppClass*)
     * @return 是否具有该特性
     */
    DEFINE_IL2CPP_API(bool, il2cpp_method_has_attribute, const void* method, void* attr_class)

    /**
     * @brief 获取方法标志
     * @param method 方法信息指针(原始类型: const MethodInfo*)
     * @param iflags [out] 实现标志
     * @return 方法标志
     */
    DEFINE_IL2CPP_API(uint32_t, il2cpp_method_get_flags, const void* method, uint32_t* iflags)

    /**
     * @brief 获取方法Token
     * @param method 方法信息指针(原始类型: const MethodInfo*)
     * @return 方法Token
     */
    DEFINE_IL2CPP_API(uint32_t, il2cpp_method_get_token, const void* method)

    /**
     * @brief 获取方法参数名称
     * @param method 方法信息指针(原始类型: const MethodInfo*)
     * @param index 参数索引
     * @return 参数名称字符串
     */
    DEFINE_IL2CPP_API(const char*, il2cpp_method_get_param_name, const void* method, uint32_t index)
}
