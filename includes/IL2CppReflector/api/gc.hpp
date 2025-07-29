/*******************************************************************************
 * 文件名称: gc
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
     * @brief 执行垃圾回收
     * @param maxGenerations 最大回收代数
     */
    DEFINE_IL2CPP_API(void, il2cpp_gc_collect, int maxGenerations)

    /**
     * @brief 执行少量垃圾回收
     * @return 回收的代数
     */
    DEFINE_IL2CPP_API(int32_t, il2cpp_gc_collect_a_little)

    /**
     * @brief 开始增量式垃圾回收
     */
    DEFINE_IL2CPP_API(void, il2cpp_gc_start_incremental_collection)

    /**
     * @brief 禁用垃圾回收
     */
    DEFINE_IL2CPP_API(void, il2cpp_gc_disable)

    /**
     * @brief 启用垃圾回收
     */
    DEFINE_IL2CPP_API(void, il2cpp_gc_enable)

    /**
     * @brief 检查垃圾回收是否被禁用
     * @return 是否被禁用
     */
    DEFINE_IL2CPP_API(bool, il2cpp_gc_is_disabled)

    /**
     * @brief 设置垃圾回收模式
     * @param mode 回收模式(原始类型: Il2CppGCMode)
     */
    DEFINE_IL2CPP_API(void, il2cpp_gc_set_mode, int mode)

    /**
     * @brief 获取最大时间片纳秒数
     * @return 最大时间片(纳秒)
     */
    DEFINE_IL2CPP_API(int64_t, il2cpp_gc_get_max_time_slice_ns)

    /**
     * @brief 设置最大时间片纳秒数
     * @param maxTimeSlice 最大时间片(纳秒)
     */
    DEFINE_IL2CPP_API(void, il2cpp_gc_set_max_time_slice_ns, int64_t maxTimeSlice)

    /**
     * @brief 检查是否使用增量式垃圾回收
     * @return 是否增量式
     */
    DEFINE_IL2CPP_API(bool, il2cpp_gc_is_incremental)

    /**
     * @brief 获取已使用堆大小
     * @return 已使用字节数
     */
    DEFINE_IL2CPP_API(int64_t, il2cpp_gc_get_used_size)

    /**
     * @brief 获取堆总大小
     * @return 堆总字节数
     */
    DEFINE_IL2CPP_API(int64_t, il2cpp_gc_get_heap_size)

    /**
     * @brief 设置写屏障字段
     * @param obj 对象实例(原始类型: Il2CppObject*)
     * @param targetAddress 目标地址
     * @param object 对象值
     */
    DEFINE_IL2CPP_API(void, il2cpp_gc_wbarrier_set_field,
                      void* obj, void** targetAddress, void* object)

    /**
     * @brief 检查是否有严格写屏障
     * @return 是否有严格写屏障
     */
    DEFINE_IL2CPP_API(bool, il2cpp_gc_has_strict_wbarriers)

    /**
     * @brief 设置外部分配追踪器
     * @param func 回调函数
     */
    DEFINE_IL2CPP_API(void, il2cpp_gc_set_external_allocation_tracker,
                      void(*func)(void*, size_t, int))

    /**
     * @brief 设置外部写屏障追踪器
     * @param func 回调函数
     */
    DEFINE_IL2CPP_API(void, il2cpp_gc_set_external_wbarrier_tracker,
                      void(*func)(void**))

    /**
     * @brief 遍历堆
     * @param func 回调函数
     * @param userData 用户数据
     */
    DEFINE_IL2CPP_API(void, il2cpp_gc_foreach_heap,
                      void(*func)(void* data, void* userData), void* userData)

    /**
     * @brief 停止GC世界
     */
    DEFINE_IL2CPP_API(void, il2cpp_stop_gc_world)

    /**
     * @brief 启动GC世界
     */
    DEFINE_IL2CPP_API(void, il2cpp_start_gc_world)

    /**
     * @brief 分配固定内存
     * @param size 分配大小
     * @return 内存指针
     */
    DEFINE_IL2CPP_API(void*, il2cpp_gc_alloc_fixed, size_t size)

    /**
     * @brief 释放固定内存
     * @param address 内存地址
     */
    DEFINE_IL2CPP_API(void, il2cpp_gc_free_fixed, void* address)
}
