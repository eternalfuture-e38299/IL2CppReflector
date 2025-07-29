/*******************************************************************************
 * 文件名称: custom_attributes
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
     * @brief 从类获取自定义特性信息
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @return 自定义特性信息指针(原始类型: Il2CppCustomAttrInfo*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_custom_attrs_from_class, void* klass)

    /**
     * @brief 从方法获取自定义特性信息
     * @param method 方法信息指针(原始类型: const MethodInfo*)
     * @return 自定义特性信息指针(原始类型: Il2CppCustomAttrInfo*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_custom_attrs_from_method, const void* method)

    /**
     * @brief 获取特定类型的自定义特性对象
     * @param ainfo 自定义特性信息指针(原始类型: Il2CppCustomAttrInfo*)
     * @param attr_klass 特性类指针(原始类型: Il2CppClass*)
     * @return 特性对象(原始类型: Il2CppObject*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_custom_attrs_get_attr, void* ainfo, void* attr_klass)

    /**
     * @brief 检查是否具有特定类型的自定义特性
     * @param ainfo 自定义特性信息指针(原始类型: Il2CppCustomAttrInfo*)
     * @param attr_klass 特性类指针(原始类型: Il2CppClass*)
     * @return 是否具有该特性
     */
    DEFINE_IL2CPP_API(bool, il2cpp_custom_attrs_has_attr, void* ainfo, void* attr_klass)

    /**
     * @brief 构造自定义特性数组
     * @param cinfo 自定义特性信息指针(原始类型: Il2CppCustomAttrInfo*)
     * @return 特性数组(原始类型: Il2CppArray*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_custom_attrs_construct, void* cinfo)

    /**
     * @brief 释放自定义特性信息
     * @param ainfo 自定义特性信息指针(原始类型: Il2CppCustomAttrInfo*)
     */
    DEFINE_IL2CPP_API(void, il2cpp_custom_attrs_free, void* ainfo)
}
