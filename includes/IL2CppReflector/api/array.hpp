/*******************************************************************************
 * 文件名称: array
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
    * @brief 获取数组类
    * @param element_class 数组元素类(原始类型: Il2CppClass*)
    * @param rank 数组维度
    * @return 数组类指针(原始类型: Il2CppClass*)
    */
    DEFINE_IL2CPP_API(void*, il2cpp_array_class_get, void* element_class, uint32_t rank)

    /**
     * @brief 获取数组长度
     * @param array 数组对象(原始类型: Il2CppArray*)
     * @return 数组元素数量
     */
    DEFINE_IL2CPP_API(uint32_t, il2cpp_array_length, void* array)

    /**
     * @brief 获取数组字节长度
     * @param array 数组对象(原始类型: Il2CppArray*)
     * @return 字节长度
     */
    DEFINE_IL2CPP_API(uint32_t, il2cpp_array_get_byte_length, void* array)

    /**
     * @brief 创建新数组
     * @param elementTypeInfo 元素类型信息(原始类型: Il2CppClass*)
     * @param length 数组长度
     * @return 数组对象(原始类型: Il2CppArray*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_array_new, void* elementTypeInfo, uintptr_t length)

    /**
     * @brief 创建特定类型数组
     * @param arrayTypeInfo 数组类型信息(原始类型: Il2CppClass*)
     * @param length 数组长度
     * @return 数组对象(原始类型: Il2CppArray*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_array_new_specific, void* arrayTypeInfo, uintptr_t length)

    /**
     * @brief 创建多维数组
     * @param array_class 数组类(原始类型: Il2CppClass*)
     * @param lengths 各维度长度数组
     * @param lower_bounds 各维度下界数组
     * @return 数组对象(原始类型: Il2CppArray*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_array_new_full,
                      void* array_class, uintptr_t* lengths, uintptr_t* lower_bounds)

    /**
     * @brief 获取有界数组类
     * @param element_class 元素类(原始类型: Il2CppClass*)
     * @param rank 数组维度
     * @param bounded 是否是有界数组
     * @return 数组类指针(原始类型: Il2CppClass*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_bounded_array_class_get,
                      void* element_class, uint32_t rank, bool bounded)

    /**
     * @brief 获取数组元素大小
     * @param array_class 数组类(原始类型: const Il2CppClass*)
     * @return 单个元素大小(字节)
     */
    DEFINE_IL2CPP_API(int, il2cpp_array_element_size, const void* array_class)
}
