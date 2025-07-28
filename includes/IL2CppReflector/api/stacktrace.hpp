/*******************************************************************************
 * 文件名称: stacktrace
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
     * @brief 遍历当前线程的调用栈帧
     * @param func 回调函数(原始类型: Il2CppFrameWalkFunc)
     * @param user_data 用户数据
     */
    DEFINE_IL2CPP_API(void, il2cpp_current_thread_walk_frame_stack,
                      void(*func)(void*, void*), void* user_data)

    /**
     * @brief 遍历指定线程的调用栈帧
     * @param thread 线程指针(原始类型: Il2CppThread*)
     * @param func 回调函数(原始类型: Il2CppFrameWalkFunc)
     * @param user_data 用户数据
     */
    DEFINE_IL2CPP_API(void, il2cpp_thread_walk_frame_stack,
                      void* thread, void(*func)(void*, void*), void* user_data)

    /**
     * @brief 获取当前线程的顶部栈帧
     * @param frame [out] 栈帧信息(原始类型: Il2CppStackFrameInfo*)
     * @return 是否获取成功
     */
    DEFINE_IL2CPP_API(bool, il2cpp_current_thread_get_top_frame, void* frame)

    /**
     * @brief 获取指定线程的顶部栈帧
     * @param thread 线程指针(原始类型: Il2CppThread*)
     * @param frame [out] 栈帧信息(原始类型: Il2CppStackFrameInfo*)
     * @return 是否获取成功
     */
    DEFINE_IL2CPP_API(bool, il2cpp_thread_get_top_frame,
                      void* thread, void* frame)

    /**
     * @brief 获取当前线程指定偏移的栈帧
     * @param offset 栈帧偏移
     * @param frame [out] 栈帧信息(原始类型: Il2CppStackFrameInfo*)
     * @return 是否获取成功
     */
    DEFINE_IL2CPP_API(bool, il2cpp_current_thread_get_frame_at,
                      int32_t offset, void* frame)

    /**
     * @brief 获取指定线程指定偏移的栈帧
     * @param thread 线程指针(原始类型: Il2CppThread*)
     * @param offset 栈帧偏移
     * @param frame [out] 栈帧信息(原始类型: Il2CppStackFrameInfo*)
     * @return 是否获取成功
     */
    DEFINE_IL2CPP_API(bool, il2cpp_thread_get_frame_at,
                      void* thread, int32_t offset, void* frame)

    /**
     * @brief 获取当前线程的调用栈深度
     * @return 调用栈深度
     */
    DEFINE_IL2CPP_API(int32_t, il2cpp_current_thread_get_stack_depth,)

    /**
     * @brief 获取指定线程的调用栈深度
     * @param thread 线程指针(原始类型: Il2CppThread*)
     * @return 调用栈深度
     */
    DEFINE_IL2CPP_API(int32_t, il2cpp_thread_get_stack_depth, void* thread)

    /**
     * @brief 覆盖默认的堆栈回溯实现
     * @param stackBacktraceFunc 回溯函数(原始类型: Il2CppBacktraceFunc)
     */
    DEFINE_IL2CPP_API(void, il2cpp_override_stack_backtrace,
                      void(*stackBacktraceFunc)(void*))
}
