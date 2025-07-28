/*******************************************************************************
 * 文件名称: field
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

#include "api_define.hpp"
#include <cstddef>

namespace Il2CppAPI {
    /**
     * @brief 获取字段标志
     * @param field 字段信息指针(原始类型: FieldInfo*)
     * @return 字段标志位
     */
    DEFINE_IL2CPP_API(int, il2cpp_field_get_flags, void* field)

    /**
     * @brief 获取字段名称
     * @param field 字段信息指针(原始类型: FieldInfo*)
     * @return 字段名称字符串
     */
    DEFINE_IL2CPP_API(const char*, il2cpp_field_get_name, void* field)

    /**
     * @brief 获取字段所属类
     * @param field 字段信息指针(原始类型: FieldInfo*)
     * @return 所属类指针(原始类型: Il2CppClass*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_field_get_parent, void* field)

    /**
     * @brief 获取字段偏移量
     * @param field 字段信息指针(原始类型: FieldInfo*)
     * @return 字段偏移量(字节)
     */
    DEFINE_IL2CPP_API(size_t, il2cpp_field_get_offset, void* field)

    /**
     * @brief 获取字段类型
     * @param field 字段信息指针(原始类型: FieldInfo*)
     * @return 类型指针(原始类型: const Il2CppType*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_field_get_type, void* field)

    /**
     * @brief 获取字段值
     * @param obj 对象实例(原始类型: Il2CppObject*)
     * @param field 字段信息指针(原始类型: FieldInfo*)
     * @param value [out] 输出值缓冲区
     */
    DEFINE_IL2CPP_API(void, il2cpp_field_get_value,
                      void* obj, void* field, void* value)

    /**
     * @brief 获取字段值作为对象
     * @param field 字段信息指针(原始类型: FieldInfo*)
     * @param obj 对象实例(原始类型: Il2CppObject*)
     * @return 字段值对象(原始类型: Il2CppObject*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_field_get_value_object,
                      void* field, void* obj)

    /**
     * @brief 检查字段是否有指定特性
     * @param field 字段信息指针(原始类型: FieldInfo*)
     * @param attr_class 特性类(原始类型: Il2CppClass*)
     * @return 是否具有该特性
     */
    DEFINE_IL2CPP_API(bool, il2cpp_field_has_attribute,
                      void* field, void* attr_class)

    /**
     * @brief 设置字段值
     * @param obj 对象实例(原始类型: Il2CppObject*)
     * @param field 字段信息指针(原始类型: FieldInfo*)
     * @param value 要设置的值
     */
    DEFINE_IL2CPP_API(void, il2cpp_field_set_value,
                      void* obj, void* field, void* value)

    /**
     * @brief 获取静态字段值
     * @param field 字段信息指针(原始类型: FieldInfo*)
     * @param value [out] 输出值缓冲区
     */
    DEFINE_IL2CPP_API(void, il2cpp_field_static_get_value,
                      void* field, void* value)

    /**
     * @brief 设置静态字段值
     * @param field 字段信息指针(原始类型: FieldInfo*)
     * @param value 要设置的值
     */
    DEFINE_IL2CPP_API(void, il2cpp_field_static_set_value,
                      void* field, void* value)

    /**
     * @brief 设置字段对象值
     * @param instance 对象实例(原始类型: Il2CppObject*)
     * @param field 字段信息指针(原始类型: FieldInfo*)
     * @param value 要设置的对象值(原始类型: Il2CppObject*)
     */
    DEFINE_IL2CPP_API(void, il2cpp_field_set_value_object,
                      void* instance, void* field, void* value)

    /**
     * @brief 检查字段是否为字面量常量
     * @param field 字段信息指针(原始类型: FieldInfo*)
     * @return 是否为字面量常量
     */
    DEFINE_IL2CPP_API(bool, il2cpp_field_is_literal, void* field)
}
