/*******************************************************************************
 * 文件名称: type
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
     * @brief 获取类型的反射对象
     * @param type 类型指针(原始类型: const Il2CppType*)
     * @return 反射对象(原始类型: Il2CppObject*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_type_get_object, const void* type)

    /**
     * @brief 获取类型种类
     * @param type 类型指针(原始类型: const Il2CppType*)
     * @return 类型枚举值
     */
    DEFINE_IL2CPP_API(int, il2cpp_type_get_type, const void* type)

    /**
     * @brief 获取类型对应的类或元素类(对于数组)
     * @param type 类型指针(原始类型: const Il2CppType*)
     * @return 类指针(原始类型: Il2CppClass*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_type_get_class_or_element_class, const void* type)

    /**
     * @brief 获取类型名称
     * @param type 类型指针(原始类型: const Il2CppType*)
     * @return 类型名称字符串(需要调用者释放)
     */
    DEFINE_IL2CPP_API(char*, il2cpp_type_get_name, const void* type)

    /**
     * @brief 检查类型是否为引用类型
     * @param type 类型指针(原始类型: const Il2CppType*)
     * @return 是否为引用类型
     */
    DEFINE_IL2CPP_API(bool, il2cpp_type_is_byref, const void* type)

    /**
     * @brief 获取类型属性标志
     * @param type 类型指针(原始类型: const Il2CppType*)
     * @return 属性标志位
     */
    DEFINE_IL2CPP_API(uint32_t, il2cpp_type_get_attrs, const void* type)

    /**
     * @brief 比较两个类型是否相等
     * @param type 类型指针(原始类型: const Il2CppType*)
     * @param otherType 另一个类型指针(原始类型: const Il2CppType*)
     * @return 是否相等
     */
    DEFINE_IL2CPP_API(bool, il2cpp_type_equals, const void* type, const void* otherType)

    /**
     * @brief 获取类型的程序集限定名称
     * @param type 类型指针(原始类型: const Il2CppType*)
     * @return 程序集限定名称字符串(需要调用者释放)
     */
    DEFINE_IL2CPP_API(char*, il2cpp_type_get_assembly_qualified_name, const void* type)

    /**
     * @brief 检查类型是否为静态
     * @param type 类型指针(原始类型: const Il2CppType*)
     * @return 是否为静态
     */
    DEFINE_IL2CPP_API(bool, il2cpp_type_is_static, const void* type)

    /**
     * @brief 检查类型是否为指针类型
     * @param type 类型指针(原始类型: const Il2CppType*)
     * @return 是否为指针类型
     */
    DEFINE_IL2CPP_API(bool, il2cpp_type_is_pointer_type, const void* type)
}
