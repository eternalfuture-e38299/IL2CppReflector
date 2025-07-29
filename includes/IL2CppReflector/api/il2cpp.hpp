/*******************************************************************************
 * 文件名称: il2cpp
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
  * @brief 初始化IL2CPP运行时
  * @param domain_name 域名
  * @return 初始化状态
  */
    DEFINE_IL2CPP_API(int, il2cpp_init, const char* domain_name)

    /**
     * @brief UTF-16版本的运行时初始化
     * @param domain_name UTF-16格式的域名(原始类型: const Il2CppChar*)
     * @return 初始化状态
     */
    DEFINE_IL2CPP_API(int, il2cpp_init_utf16, const void* domain_name)

    /**
     * @brief 关闭IL2CPP运行时
     */
    DEFINE_IL2CPP_API(void, il2cpp_shutdown)

    /**
     * @brief 设置配置目录路径
     * @param config_path 配置目录路径
     */
    DEFINE_IL2CPP_API(void, il2cpp_set_config_dir, const char* config_path)

    /**
     * @brief 设置数据目录路径
     * @param data_path 数据目录路径
     */
    DEFINE_IL2CPP_API(void, il2cpp_set_data_dir, const char* data_path)

    /**
     * @brief 设置临时目录路径
     * @param temp_path 临时目录路径
     */
    DEFINE_IL2CPP_API(void, il2cpp_set_temp_dir, const char* temp_path)

    /**
     * @brief 设置命令行参数(UTF-8)
     * @param argc 参数数量
     * @param argv 参数数组
     * @param basedir 基础目录
     */
    DEFINE_IL2CPP_API(void, il2cpp_set_commandline_arguments,
                      int argc, const char* const argv[], const char* basedir)

    /**
     * @brief 设置命令行参数(UTF-16)
     * @param argc 参数数量
     * @param argv UTF-16参数数组(原始类型: const Il2CppChar* const[])
     * @param basedir 基础目录
     */
    DEFINE_IL2CPP_API(void, il2cpp_set_commandline_arguments_utf16,
                      int argc, const void* const argv[], const char* basedir)

    /**
     * @brief 设置UTF-16配置路径
     * @param executablePath 可执行文件路径(原始类型: const Il2CppChar*)
     */
    DEFINE_IL2CPP_API(void, il2cpp_set_config_utf16, const void* executablePath)

    /**
     * @brief 设置配置路径
     * @param executablePath 可执行文件路径
     */
    DEFINE_IL2CPP_API(void, il2cpp_set_config, const char* executablePath)

    /**
     * @brief 设置内存回调
     * @param callbacks 内存回调结构体(原始类型: Il2CppMemoryCallbacks*)
     */
    DEFINE_IL2CPP_API(void, il2cpp_set_memory_callbacks, void* callbacks)

    /**
     * @brief 获取核心库镜像
     * @return 核心库镜像指针(原始类型: const Il2CppImage*)
     */
    DEFINE_IL2CPP_API(const void*, il2cpp_get_corlib)

    /**
     * @brief 添加内部调用
     * @param name 方法全名
     * @param method 方法指针(原始类型: Il2CppMethodPointer)
     */
    DEFINE_IL2CPP_API(void, il2cpp_add_internal_call,
                      const char* name, void* method)

    /**
     * @brief 解析内部调用
     * @param name 方法全名
     * @return 方法指针(原始类型: Il2CppMethodPointer)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_resolve_icall, const char* name)

    /**
     * @brief 分配内存
     * @param size 分配大小
     * @return 内存指针
     */
    DEFINE_IL2CPP_API(void*, il2cpp_alloc, size_t size)

    /**
     * @brief 释放内存
     * @param ptr 要释放的内存指针
     */
    DEFINE_IL2CPP_API(void, il2cpp_free, void* ptr)
}
