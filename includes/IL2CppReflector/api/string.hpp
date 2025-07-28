/*******************************************************************************
 * 文件名称: string
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
     * @brief 获取字符串长度
     * @param str 字符串对象(原始类型: Il2CppString*)
     * @return 字符串长度(字符数)
     */
    DEFINE_IL2CPP_API(int32_t, il2cpp_string_length, void* str)

    /**
     * @brief 获取字符串字符数组
     * @param str 字符串对象(原始类型: Il2CppString*)
     * @return 字符数组指针(原始类型: Il2CppChar*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_string_chars, void* str)

    /**
     * @brief 创建新字符串(UTF-8)
     * @param str UTF-8字符串
     * @return 字符串对象(原始类型: Il2CppString*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_string_new, const char* str)

    /**
     * @brief 创建新字符串(UTF-8带长度)
     * @param str UTF-8字符串
     * @param length 字符串长度
     * @return 字符串对象(原始类型: Il2CppString*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_string_new_len, const char* str, uint32_t length)

    /**
     * @brief 创建新字符串(UTF-16)
     * @param text UTF-16字符串
     * @param len 字符串长度
     * @return 字符串对象(原始类型: Il2CppString*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_string_new_utf16, const void* text, int32_t len)

    /**
     * @brief 创建字符串包装器
     * @param str UTF-8字符串
     * @return 字符串对象(原始类型: Il2CppString*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_string_new_wrapper, const char* str)

    /**
     * @brief 字符串驻留
     * @param str 字符串对象(原始类型: Il2CppString*)
     * @return 驻留后的字符串对象(原始类型: Il2CppString*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_string_intern, void* str)

    /**
     * @brief 检查字符串是否已驻留
     * @param str 字符串对象(原始类型: Il2CppString*)
     * @return 已驻留的字符串对象(原始类型: Il2CppString*)，若未驻留返回NULL
     */
    DEFINE_IL2CPP_API(void*, il2cpp_string_is_interned, void* str)
}
