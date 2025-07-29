/*******************************************************************************
 * 文件名称: monitor
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
     * @brief 进入对象监视器
     * @param obj 对象指针(原始类型: Il2CppObject*)
     */
    DEFINE_IL2CPP_API(void, il2cpp_monitor_enter, void* obj)

    /**
     * @brief 尝试进入对象监视器
     * @param obj 对象指针(原始类型: Il2CppObject*)
     * @param timeout 超时时间(毫秒)
     * @return 是否成功获取锁
     */
    DEFINE_IL2CPP_API(bool, il2cpp_monitor_try_enter, void* obj, uint32_t timeout)

    /**
     * @brief 退出对象监视器
     * @param obj 对象指针(原始类型: Il2CppObject*)
     */
    DEFINE_IL2CPP_API(void, il2cpp_monitor_exit, void* obj)

    /**
     * @brief 唤醒一个等待对象监视器的线程
     * @param obj 对象指针(原始类型: Il2CppObject*)
     */
    DEFINE_IL2CPP_API(void, il2cpp_monitor_pulse, void* obj)

    /**
     * @brief 唤醒所有等待对象监视器的线程
     * @param obj 对象指针(原始类型: Il2CppObject*)
     */
    DEFINE_IL2CPP_API(void, il2cpp_monitor_pulse_all, void* obj)

    /**
     * @brief 等待对象监视器
     * @param obj 对象指针(原始类型: Il2CppObject*)
     */
    DEFINE_IL2CPP_API(void, il2cpp_monitor_wait, void* obj)

    /**
     * @brief 尝试等待对象监视器
     * @param obj 对象指针(原始类型: Il2CppObject*)
     * @param timeout 超时时间(毫秒)
     * @return 是否在超时前获得通知
     */
    DEFINE_IL2CPP_API(bool, il2cpp_monitor_try_wait, void* obj, uint32_t timeout)
}
