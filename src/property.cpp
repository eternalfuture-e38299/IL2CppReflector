/*******************************************************************************
 * 文件名称: property
 * 项目名称: TEFModLoader
 * 创建时间: 25-7-28
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

#include "IL2CppReflector/property.hpp"

#include "IL2CppReflector/api/property.hpp"

#include "IL2CppReflector/method.hpp"

std::string IL2CppReflector::Property::GetName() const {
    return Il2CppAPI::il2cpp_property_get_name(_property);
}

uint32_t IL2CppReflector::Property::GetFlags() const {
    return Il2CppAPI::il2cpp_property_get_flags(_property);
}

IL2CppReflector::Method IL2CppReflector::Property::GetMethod() const {
    return Method(Il2CppAPI::il2cpp_property_get_get_method(_property));
}

IL2CppReflector::Method IL2CppReflector::Property::SetMethod() const {
    return Method(Il2CppAPI::il2cpp_property_get_set_method(_property));
}