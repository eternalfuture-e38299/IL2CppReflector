/*******************************************************************************
 * 文件名称: class
 * 项目名称: IL2CppReflector
 * 创建时间: 25-7-23
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

#include <string>
#include <vector>

namespace IL2CppReflector {

    const void* GetImage(const std::string& Name);

    class Field;
    class Method;
    class Property;


    class Class {
        void *_class{};

    public:
        Class() = default;

        explicit Class(void *m_class): _class(m_class) {}

        explicit Class(const std::string &Namespace, const std::string &Name, const void *Image = nullptr);

        [[nodiscard]] std::string ToString() const;

        [[nodiscard]] std::string GetNamespace() const;

        [[nodiscard]] std::string GetName() const;

        [[nodiscard]] bool IsAbstract() const;

        [[nodiscard]] bool IsInterface() const;

        [[nodiscard]] bool IsEnum() const;

        [[nodiscard]] bool IsGeneric() const;

        [[nodiscard]] bool IsInflated() const;

        [[nodiscard]] std::vector<Class> GetInnerClasses() const;

        [[nodiscard]] Class GetInnerClass(const std::string &Name) const;

        [[nodiscard]] std::vector<Field> GetFields(bool ParentClass = false) const;

        [[nodiscard]] Field GetField(const std::string &Name) const;

        [[nodiscard]] std::vector<Method> GetMethods(bool ParentClass = false) const;

        [[nodiscard]] Method GetMethod(const std::string &Name, int args_count = -1) const;

        [[nodiscard]] Method GetMethod(const std::string& Name, const std::vector<std::string>& args_name) const;

        [[nodiscard]] std::vector<Property> GetProperties(bool ParentClass = false) const;

        [[nodiscard]] Property GetProperty(const std::string &Name) const;

        [[nodiscard]] Class GetGeneric(const std::vector<void *> &templateTypes) const;

        [[nodiscard]] void* GetMonoType() const;

        [[nodiscard]] void *CreateNewInstance() const;

        template<typename... Args>
        [[nodiscard]] void *CreateNewObjectParameters(Args... args);

        [[nodiscard]] void* GetIl2cppClass() const;
    };
    /**
     * 创建 IL2CppReflector::Class
     * @param ImageName Image 名称
     * @param FullName 类的完整名称(命名空间 + 类名)
     * @return
     */
    IL2CppReflector::Class GetClass(const std::string &ImageName, const std::string &FullName);

    void* CreateTypeArrayFromVector(const std::vector<void*>& typeObjects);
}
