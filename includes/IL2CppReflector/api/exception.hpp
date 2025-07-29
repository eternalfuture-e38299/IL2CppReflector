/*******************************************************************************
 * 文件名称: exception
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
     * @brief 抛出异常（无返回）
     * @param ex 异常对象(原始类型: Il2CppException*)
     */
    DEFINE_IL2CPP_API(void, il2cpp_raise_exception, void* ex)

    /**
     * @brief 从名称创建异常对象
     * @param image 镜像(原始类型: const Il2CppImage*)
     * @param name_space 命名空间
     * @param name 异常类名
     * @param msg 异常消息
     * @return 异常对象(原始类型: Il2CppException*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_exception_from_name_msg,
                      const void* image, const char* name_space,
                      const char* name, const char* msg)

    /**
     * @brief 获取参数为空的异常
     * @param arg 参数名称
     * @return 异常对象(原始类型: Il2CppException*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_get_exception_argument_null, const char* arg)

    /**
     * @brief 格式化异常信息
     * @param ex 异常对象(原始类型: const Il2CppException*)
     * @param message 输出缓冲区
     * @param message_size 缓冲区大小
     */
    DEFINE_IL2CPP_API(void, il2cpp_format_exception,
                      const void* ex, char* message, int message_size)

    /**
     * @brief 格式化堆栈跟踪信息
     * @param ex 异常对象(原始类型: const Il2CppException*)
     * @param output 输出缓冲区
     * @param output_size 缓冲区大小
     */
    DEFINE_IL2CPP_API(void, il2cpp_format_stack_trace,
                      const void* ex, char* output, int output_size)

    /**
     * @brief 处理未捕获的异常
     * @param ex 异常对象(原始类型: Il2CppException*)
     */
    DEFINE_IL2CPP_API(void, il2cpp_unhandled_exception, void* ex)

    /**
     * @brief 获取原生堆栈跟踪信息
     * @param ex 异常对象(原始类型: const Il2CppException*)
     * @param addresses [out] 地址数组
     * @param numFrames [out] 帧数
     * @param imageUUID [out] 镜像UUID
     * @param imageName [out] 镜像名称
     */
    DEFINE_IL2CPP_API(void, il2cpp_native_stack_trace,
                      const void* ex, uintptr_t** addresses,
                      int* numFrames, char** imageUUID, char** imageName)
}
