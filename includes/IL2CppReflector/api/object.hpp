/*******************************************************************************
 * 文件名称: object
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
     * @brief 获取对象的类
     * @param obj 对象指针(原始类型: Il2CppObject*)
     * @return 类指针(原始类型: Il2CppClass*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_object_get_class, void* obj)

    /**
     * @brief 获取对象大小
     * @param obj 对象指针(原始类型: Il2CppObject*)
     * @return 对象大小(字节)
     */
    DEFINE_IL2CPP_API(uint32_t, il2cpp_object_get_size, void* obj)

    /**
     * @brief 获取对象的虚方法
     * @param obj 对象指针(原始类型: Il2CppObject*)
     * @param method 方法信息指针(原始类型: const MethodInfo*)
     * @return 方法信息指针(原始类型: const MethodInfo*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_object_get_virtual_method, void* obj, void* method)

    /**
     * @brief 创建新对象
     * @param klass 类指针(原始类型: const Il2CppClass*)
     * @return 对象指针(原始类型: Il2CppObject*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_object_new, const void* klass)

    /**
     * @brief 拆箱对象
     * @param obj 对象指针(原始类型: Il2CppObject*)
     * @return 值类型数据指针
     */
    DEFINE_IL2CPP_API(void*, il2cpp_object_unbox, void* obj)

    /**
     * @brief 装箱值类型
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @param data 值类型数据指针
     * @return 对象指针(原始类型: Il2CppObject*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_value_box, void* klass, void* data)
}
