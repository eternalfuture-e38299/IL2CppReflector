/*******************************************************************************
 * 文件名称: struct
 * 项目名称: TEFModLoader
 * 创建时间: 25-7-26
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

#include "IL2CppReflector/struct.hpp"
#include "utfcpp/utf8.h"

std::string UnityStruct::string::str() {
    std::string utf8String{};
    utf8::unchecked::utf16to8(m_data, m_data + m_length, std::back_inserter(utf8String));
    return utf8String;
}

wchar_t &UnityStruct::string::at(const size_t pos) {
    if (pos >= static_cast<size_t>(m_length)) {
        throw std::out_of_range("string index out of range");
    }
    return m_data[pos];
}

bool UnityStruct::string::equals(const string &other) const {
    if (m_length != other.m_length) return false;
    return std::memcmp(m_data, other.m_data, m_length * sizeof(wchar_t)) == 0;
}

bool UnityStruct::string::empty() const {
    return m_length == 0;
}

size_t UnityStruct::string::length() const {
    return m_length;
}

size_t UnityStruct::string::size() const {
    return m_length * sizeof(wchar_t);
}

const wchar_t *UnityStruct::string::c_str() const {
    return m_data;
}

const wchar_t *UnityStruct::string::data() const {
    return m_data;
}