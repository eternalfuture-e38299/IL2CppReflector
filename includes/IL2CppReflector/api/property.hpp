/*******************************************************************************
 * 文件名称: property
 * 项目名称: TEFModLoader
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
     * @brief 获取属性标志
     * @param prop 属性信息指针(原始类型: PropertyInfo*)
     * @return 属性标志位
     */
    DEFINE_IL2CPP_API(uint32_t, il2cpp_property_get_flags, void* prop)

    /**
     * @brief 获取属性的get方法
     * @param prop 属性信息指针(原始类型: PropertyInfo*)
     * @return 方法信息指针(原始类型: const MethodInfo*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_property_get_get_method, void* prop)

    /**
     * @brief 获取属性的set方法
     * @param prop 属性信息指针(原始类型: PropertyInfo*)
     * @return 方法信息指针(原始类型: const MethodInfo*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_property_get_set_method, void* prop)

    /**
     * @brief 获取属性名称
     * @param prop 属性信息指针(原始类型: PropertyInfo*)
     * @return 属性名称字符串
     */
    DEFINE_IL2CPP_API(const char*, il2cpp_property_get_name, void* prop)

    /**
     * @brief 获取属性所属类
     * @param prop 属性信息指针(原始类型: PropertyInfo*)
     * @return 类指针(原始类型: Il2CppClass*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_property_get_parent, void* prop)
}
