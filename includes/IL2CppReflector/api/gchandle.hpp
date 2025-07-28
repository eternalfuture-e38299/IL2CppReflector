/*******************************************************************************
 * 文件名称: gchandle
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
     * @brief 创建新的GC句柄
     * @param obj 托管对象(原始类型: Il2CppObject*)
     * @param pinned 是否固定对象
     * @return GC句柄标识符
     */
    DEFINE_IL2CPP_API(uint32_t, il2cpp_gchandle_new, void* obj, bool pinned)

    /**
     * @brief 创建新的弱引用GC句柄
     * @param obj 托管对象(原始类型: Il2CppObject*)
     * @param track_resurrection 是否跟踪复活
     * @return GC句柄标识符
     */
    DEFINE_IL2CPP_API(uint32_t, il2cpp_gchandle_new_weakref, void* obj, bool track_resurrection)

    /**
     * @brief 通过GC句柄获取目标对象
     * @param gchandle GC句柄标识符
     * @return 托管对象(原始类型: Il2CppObject*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_gchandle_get_target, uint32_t gchandle)

    /**
     * @brief 释放GC句柄
     * @param gchandle GC句柄标识符
     */
    DEFINE_IL2CPP_API(void, il2cpp_gchandle_free, uint32_t gchandle)

    /**
     * @brief 遍历所有GC句柄的目标对象
     * @param func 回调函数
     * @param userData 用户数据
     */
    DEFINE_IL2CPP_API(void, il2cpp_gchandle_foreach_get_target,
                      void(*func)(void* data, void* userData), void* userData)
}
