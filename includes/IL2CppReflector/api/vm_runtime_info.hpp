/*******************************************************************************
 * 文件名称: vm_runtime_info
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
     * @brief 获取普通对象头大小
     * @return 对象头大小(字节)
     */
    DEFINE_IL2CPP_API(uint32_t, il2cpp_object_header_size)

    /**
     * @brief 获取数组对象头大小
     * @return 数组对象头大小(字节)
     */
    DEFINE_IL2CPP_API(uint32_t, il2cpp_array_object_header_size)

    /**
     * @brief 获取数组长度字段在对象头中的偏移量
     * @return 偏移量(字节)
     */
    DEFINE_IL2CPP_API(uint32_t, il2cpp_offset_of_array_length_in_array_object_header)

    /**
     * @brief 获取数组边界信息在对象头中的偏移量
     * @return 偏移量(字节)
     */
    DEFINE_IL2CPP_API(uint32_t, il2cpp_offset_of_array_bounds_in_array_object_header)

    /**
     * @brief 获取内存分配粒度
     * @return 分配粒度大小(字节)
     */
    DEFINE_IL2CPP_API(uint32_t, il2cpp_allocation_granularity)
}
