/*******************************************************************************
 * 文件名称: class
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
     * @brief 遍历所有已加载的类
     * @param klassReportFunc 回调函数(参数: Il2CppClass* klass, void* userData)
     * @param userData 用户自定义数据
     */
    DEFINE_IL2CPP_API(void, il2cpp_class_for_each,
                      void(*klassReportFunc)(void* klass, void* userData), void* userData)

    /**
     * @brief 获取枚举的基类型
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @return 类型指针(原始类型: const Il2CppType*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_class_enum_basetype, void* klass)

    /**
     * @brief 检查类是否是泛型类型
     * @param klass 类指针(原始类型: const Il2CppClass*)
     * @return 是否为泛型类型
     */
    DEFINE_IL2CPP_API(bool, il2cpp_class_is_generic, const void* klass)

    /**
     * @brief 检查类是否是展开的泛型类型
     * @param klass 类指针(原始类型: const Il2CppClass*)
     * @return 是否为展开的泛型类型
     */
    DEFINE_IL2CPP_API(bool, il2cpp_class_is_inflated, const void* klass)

    /**
     * @brief 检查类型转换是否有效
     * @param klass 目标类(原始类型: Il2CppClass*)
     * @param oklass 源类(原始类型: Il2CppClass*)
     * @return 是否可以转换
     */
    DEFINE_IL2CPP_API(bool, il2cpp_class_is_assignable_from,
                      void* klass, void* oklass)

    /**
     * @brief 检查类继承关系
     * @param klass 子类(原始类型: Il2CppClass*)
     * @param klassc 父类(原始类型: Il2CppClass*)
     * @param check_interfaces 是否检查接口
     * @return 是否为子类
     */
    DEFINE_IL2CPP_API(bool, il2cpp_class_is_subclass_of,
                      void* klass, void* klassc, bool check_interfaces)

    /**
     * @brief 检查类是否有指定父类
     * @param klass 子类(原始类型: Il2CppClass*)
     * @param klassc 父类(原始类型: Il2CppClass*)
     * @return 是否有父类关系
     */
    DEFINE_IL2CPP_API(bool, il2cpp_class_has_parent,
                      void* klass, void* klassc)

    /**
     * @brief 从类型获取类
     * @param type 类型指针(原始类型: const Il2CppType*)
     * @return 类指针(原始类型: Il2CppClass*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_class_from_il2cpp_type, const void* type)

    /**
     * @brief 通过名称获取类
     * @param image 程序集镜像(原始类型: const Il2CppImage*)
     * @param namespaze 命名空间
     * @param name 类名
     * @return 类指针(原始类型: Il2CppClass*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_class_from_name,
                      const void* image, const char* namespaze, const char *name)

    /**
     * @brief 从System.Type获取类
     * @param type 反射类型对象(原始类型: Il2CppReflectionType*)
     * @return 类指针(原始类型: Il2CppClass*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_class_from_system_type, void* type)

    /**
     * @brief 获取数组元素类
     * @param klass 数组类(原始类型: Il2CppClass*)
     * @return 元素类指针(原始类型: Il2CppClass*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_class_get_element_class, void* klass)

    /**
     * @brief 获取类的事件(迭代器方式)
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @param iter 迭代器指针(必须初始化为nullptr)
     * @return 事件信息(原始类型: const EventInfo*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_class_get_events,
                      void* klass, void** iter)

    /**
     * @brief 获取类的字段(迭代器方式)
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @param iter 迭代器指针(必须初始化为nullptr)
     * @return 字段信息(原始类型: FieldInfo*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_class_get_fields,
                      void* klass, void** iter)

    /**
     * @brief 获取嵌套类型(迭代器方式)
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @param iter 迭代器指针(必须初始化为nullptr)
     * @return 嵌套类指针(原始类型: Il2CppClass*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_class_get_nested_types,
                      void* klass, void** iter)

    /**
     * @brief 获取实现的接口(迭代器方式)
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @param iter 迭代器指针(必须初始化为nullptr)
     * @return 接口类指针(原始类型: Il2CppClass*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_class_get_interfaces,
                      void* klass, void** iter)

    /**
     * @brief 获取类的属性(迭代器方式)
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @param iter 迭代器指针(必须初始化为nullptr)
     * @return 属性信息(原始类型: const PropertyInfo*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_class_get_properties,
                      void* klass, void** iter)

    /**
     * @brief 通过名称获取属性
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @param name 属性名
     * @return 属性信息(原始类型: const PropertyInfo*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_class_get_property_from_name,
                      void* klass, const char *name)

    /**
     * @brief 通过名称获取字段
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @param name 字段名
     * @return 字段信息(原始类型: FieldInfo*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_class_get_field_from_name,
                      void* klass, const char *name)

    /**
     * @brief 获取类的方法(迭代器方式)
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @param iter 迭代器指针(必须初始化为nullptr)
     * @return 方法信息(原始类型: const MethodInfo*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_class_get_methods,
                      void* klass, void** iter)

    /**
     * @brief 通过名称获取方法
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @param name 方法名
     * @param argsCount 参数数量
     * @return 方法信息(原始类型: const MethodInfo*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_class_get_method_from_name,
                      void* klass, const char* name, int argsCount)

    /**
     * @brief 获取类名
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @return 类名字符串
     */
    DEFINE_IL2CPP_API(const char*, il2cpp_class_get_name, void* klass)

    /**
     * @brief 分块获取类型名称
     * @param type 类型指针(原始类型: const Il2CppType*)
     * @param chunkReportFunc 回调函数
     * @param userData 用户数据
     */
    DEFINE_IL2CPP_API(void, il2cpp_type_get_name_chunked,
                      const void* type, void(*chunkReportFunc)(void* data, void* userData), void* userData)

    /**
     * @brief 获取命名空间
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @return 命名空间字符串
     */
    DEFINE_IL2CPP_API(const char*, il2cpp_class_get_namespace, void* klass)

    /**
     * @brief 获取父类
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @return 父类指针(原始类型: Il2CppClass*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_class_get_parent, void* klass)

    /**
     * @brief 获取声明类型
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @return 声明类指针(原始类型: Il2CppClass*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_class_get_declaring_type, void* klass)

    /**
     * @brief 获取类实例大小
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @return 实例大小(字节)
     */
    DEFINE_IL2CPP_API(int32_t, il2cpp_class_instance_size, void* klass)

    /**
     * @brief 获取字段数量
     * @param enumKlass 类指针(原始类型: const Il2CppClass*)
     * @return 字段数量
     */
    DEFINE_IL2CPP_API(size_t, il2cpp_class_num_fields, const void* enumKlass)

    /**
     * @brief 检查是否是值类型
     * @param klass 类指针(原始类型: const Il2CppClass*)
     * @return 是否为值类型
     */
    DEFINE_IL2CPP_API(bool, il2cpp_class_is_valuetype, const void* klass)

    /**
     * @brief 获取值类型大小
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @param align [out] 对齐值
     * @return 值类型大小
     */
    DEFINE_IL2CPP_API(int32_t, il2cpp_class_value_size,
                      void* klass, uint32_t * align)

    /**
     * @brief 检查是否可直接内存拷贝
     * @param klass 类指针(原始类型: const Il2CppClass*)
     * @return 是否可直接拷贝
     */
    DEFINE_IL2CPP_API(bool, il2cpp_class_is_blittable, const void* klass)

    /**
     * @brief 获取类标志
     * @param klass 类指针(原始类型: const Il2CppClass*)
     * @return 类标志位
     */
    DEFINE_IL2CPP_API(int, il2cpp_class_get_flags, const void* klass)

    /**
     * @brief 检查是否是抽象类
     * @param klass 类指针(原始类型: const Il2CppClass*)
     * @return 是否为抽象类
     */
    DEFINE_IL2CPP_API(bool, il2cpp_class_is_abstract, const void* klass)

    /**
     * @brief 检查是否是接口
     * @param klass 类指针(原始类型: const Il2CppClass*)
     * @return 是否为接口
     */
    DEFINE_IL2CPP_API(bool, il2cpp_class_is_interface, const void* klass)

    /**
     * @brief 获取数组元素大小
     * @param klass 类指针(原始类型: const Il2CppClass*)
     * @return 元素大小(字节)
     */
    DEFINE_IL2CPP_API(int, il2cpp_class_array_element_size, const void* klass)

    /**
     * @brief 从类型获取类
     * @param type 类型指针(原始类型: const Il2CppType*)
     * @return 类指针(原始类型: Il2CppClass*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_class_from_type, const void* type)

    /**
     * @brief 获取类的类型
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @return 类型指针(原始类型: const Il2CppType*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_class_get_type, void* klass)

    /**
     * @brief 获取类型Token
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @return 类型Token
     */
    DEFINE_IL2CPP_API(uint32_t, il2cpp_class_get_type_token, void* klass)

    /**
     * @brief 检查是否有指定特性
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @param attr_class 特性类(原始类型: Il2CppClass*)
     * @return 是否有该特性
     */
    DEFINE_IL2CPP_API(bool, il2cpp_class_has_attribute,
                      void* klass, void* attr_class)

    /**
     * @brief 检查类是否包含引用
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @return 是否包含引用
     */
    DEFINE_IL2CPP_API(bool, il2cpp_class_has_references, void* klass)

    /**
     * @brief 检查是否是枚举
     * @param klass 类指针(原始类型: const Il2CppClass*)
     * @return 是否为枚举
     */
    DEFINE_IL2CPP_API(bool, il2cpp_class_is_enum, const void* klass)

    /**
     * @brief 获取类所属的程序集镜像
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @return 程序集镜像指针(原始类型: const Il2CppImage*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_class_get_image, void* klass)

    /**
     * @brief 获取程序集名称
     * @param klass 类指针(原始类型: const Il2CppClass*)
     * @return 程序集名称
     */
    DEFINE_IL2CPP_API(const char*, il2cpp_class_get_assemblyname, const void* klass)

    /**
     * @brief 获取数组秩
     * @param klass 类指针(原始类型: const Il2CppClass*)
     * @return 数组维度
     */
    DEFINE_IL2CPP_API(int, il2cpp_class_get_rank, const void* klass)

    /**
     * @brief 获取类数据大小
     * @param klass 类指针(原始类型: const Il2CppClass*)
     * @return 数据大小
     */
    DEFINE_IL2CPP_API(uint32_t, il2cpp_class_get_data_size, const void* klass)

    /**
     * @brief 获取静态字段数据
     * @param klass 类指针(原始类型: const Il2CppClass*)
     * @return 静态数据指针
     */
    DEFINE_IL2CPP_API(void*, il2cpp_class_get_static_field_data, const void* klass)
}
