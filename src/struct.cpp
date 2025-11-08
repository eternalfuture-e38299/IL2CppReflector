/*******************************************************************************
 * 文件名称: struct
 * 项目名称: IL2CppReflector
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

#include "IL2CppReflector/logger.hpp"

void* UnityStruct::string::create(const std::string& str) {
    void* il2cppStr = Il2CppAPI::il2cpp_string_new_len(str.data(), str.length());
    if (!il2cppStr) {
        ILRL_LOG_ERROR("Failed to create IL2CPP string");
        return nullptr;
    }
    return static_cast<string*>(il2cppStr);
}

std::string UnityStruct::string::str() const {
    if (!_string) {
        ILRL_LOG_ERROR("Null IL2CPP string encountered");
        return "";
    }

    const int32_t length = Il2CppAPI::il2cpp_string_length(_string);
    const auto* chars = static_cast<const char16_t*>(
            Il2CppAPI::il2cpp_string_chars(_string)
    );

    std::string utf8Str;
    try {
        utf8::utf16to8(chars, chars + length, std::back_inserter(utf8Str));
    } catch (const utf8::exception& e) {
        ILRL_LOG_ERROR("UTF-16 to UTF-8 conversion failed: ", e.what());
        return "";
    }

    return utf8Str;
}

char16_t UnityStruct::string::at(size_t pos) const {
    if (!_string) {
        ILRL_LOG_ERROR("Null IL2CPP string");
        return '\0';
    }

    if (const int32_t length = Il2CppAPI::il2cpp_string_length(_string); pos >= static_cast<size_t>(length)) {
        ILRL_LOG_ERROR("string index out of range");
        return '\0';
    }

    const auto* chars = static_cast<const char16_t*>(
            Il2CppAPI::il2cpp_string_chars(_string)
    );
    return chars[pos];
}

bool UnityStruct::string::equals(const string& other) const {
    if (!_string || !other._string) return false;

    const int32_t len1 = Il2CppAPI::il2cpp_string_length(_string);
    if (const int32_t len2 = Il2CppAPI::il2cpp_string_length(other._string); len1 != len2) return false;

    const auto* chars1 = static_cast<const char16_t*>(
            Il2CppAPI::il2cpp_string_chars(_string)
    );
    const auto* chars2 = static_cast<const char16_t*>(
            Il2CppAPI::il2cpp_string_chars(other._string)
    );

    return std::memcmp(chars1, chars2, len1 * sizeof(char16_t)) == 0;
}

bool UnityStruct::string::empty() const {
    if (!_string) return true;
    return Il2CppAPI::il2cpp_string_length(_string) == 0;
}

size_t UnityStruct::string::length() const {
    if (!_string) return 0;
    return static_cast<size_t>(Il2CppAPI::il2cpp_string_length(_string));
}

size_t UnityStruct::string::size() const {
    if (!_string) return 0;
    return static_cast<size_t>(Il2CppAPI::il2cpp_string_length(_string)) * sizeof(char16_t);
}

const char16_t* UnityStruct::string::c_str() const {
    if (!_string) return nullptr;
    return static_cast<const char16_t*>(Il2CppAPI::il2cpp_string_chars(_string));
}

const char16_t* UnityStruct::string::data() const {
    return c_str();
}