/*******************************************************************************
 * 文件名称: class_user_data
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
     * @brief 设置类的用户数据
     * @param klass 类指针(原始类型: Il2CppClass*)
     * @param userdata 用户数据指针
     */
    DEFINE_IL2CPP_API(void, il2cpp_class_set_userdata, void* klass, void* userdata)

    /**
     * @brief 获取类用户数据偏移量
     * @return 用户数据偏移量
     */
    DEFINE_IL2CPP_API(int, il2cpp_class_get_userdata_offset,)

    // thread affinity
    /**
     * @brief 设置默认线程亲和性掩码
     * @param affinity_mask 亲和性掩码
     */
    DEFINE_IL2CPP_API(void, il2cpp_set_default_thread_affinity, int64_t affinity_mask)
}
