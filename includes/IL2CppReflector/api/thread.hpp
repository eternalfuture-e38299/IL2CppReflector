/*******************************************************************************
 * 文件名称: thread
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

namespace Il2CppAPI {
    /**
     * @brief 获取当前线程
     * @return 线程指针(原始类型: Il2CppThread*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_thread_current,)

    /**
     * @brief 附加线程到域
     * @param domain 域指针(原始类型: Il2CppDomain*)
     * @return 线程指针(原始类型: Il2CppThread*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_thread_attach, void* domain)

    /**
     * @brief 分离线程
     * @param thread 线程指针(原始类型: Il2CppThread*)
     */
    DEFINE_IL2CPP_API(void, il2cpp_thread_detach, void* thread)

    /**
     * @brief 获取所有已附加线程
     * @param size [out] 线程数量
     * @return 线程指针数组(原始类型: Il2CppThread**)
     */
    DEFINE_IL2CPP_API(void**, il2cpp_thread_get_all_attached_threads, size_t* size)

    /**
     * @brief 检查线程是否为VM线程
     * @param thread 线程指针(原始类型: Il2CppThread*)
     * @return 是否为VM线程
     */
    DEFINE_IL2CPP_API(bool, il2cpp_is_vm_thread, void* thread)
}
