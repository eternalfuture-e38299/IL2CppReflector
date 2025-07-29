/*******************************************************************************
 * 文件名称: liveness
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
     * @brief 分配存活分析结构体
     * @param filter 过滤类(原始类型: Il2CppClass*)
     * @param max_object_count 最大对象数量
     * @param callback 对象注册回调
     * @param userdata 用户数据
     * @param reallocate 重新分配回调
     * @return 状态指针
     */
    DEFINE_IL2CPP_API(void*, il2cpp_unity_liveness_allocate_struct,
                      void* filter, int max_object_count,
                      void(*callback)(void*, void*), void* userdata,
                      void*(*reallocate)(void*, size_t))

    /**
     * @brief 从根对象开始计算存活对象
     * @param root 根对象(原始类型: Il2CppObject*)
     * @param state 状态指针
     */
    DEFINE_IL2CPP_API(void, il2cpp_unity_liveness_calculation_from_root,
                      void* root, void* state)

    /**
     * @brief 从静态字段开始计算存活对象
     * @param state 状态指针
     */
    DEFINE_IL2CPP_API(void, il2cpp_unity_liveness_calculation_from_statics,
                      void* state)

    /**
     * @brief 完成存活分析
     * @param state 状态指针
     */
    DEFINE_IL2CPP_API(void, il2cpp_unity_liveness_finalize,
                      void* state)

    /**
     * @brief 释放存活分析结构体
     * @param state 状态指针
     */
    DEFINE_IL2CPP_API(void, il2cpp_unity_liveness_free_struct,
                      void* state)
}
