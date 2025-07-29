/*******************************************************************************
 * 文件名称: class
 * 项目名称: TEFModLoader
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

#include "IL2CppReflector/class.hpp"

#include "IL2CppReflector/api/class.hpp"
#include "IL2CppReflector/api/assembly.hpp"
#include "IL2CppReflector/api/domain.hpp"
#include "IL2CppReflector/api/image.hpp"
#include "IL2CppReflector/api/method.hpp"
#include "IL2CppReflector/api/object.hpp"
#include "IL2CppReflector/api/type.hpp"

#include "IL2CppReflector/field.hpp"
#include "IL2CppReflector/logger.hpp"
#include "IL2CppReflector/method.hpp"
#include "IL2CppReflector/property.hpp"
#include "IL2CppReflector/struct.hpp"

const void *IL2CppReflector::GetImage(const std::string &Name) {
    ILRL_LOG_DEBUG("Attempting to get image for assembly:", Name);

    const auto domain = Il2CppAPI::il2cpp_domain_get();
    if (!domain) {
        ILRL_LOG_ERROR("Failed to get current app domain");
        return nullptr;
    }

    size_t assemblies_count = 0;
    const auto assemblies = Il2CppAPI::il2cpp_domain_get_assemblies(domain, &assemblies_count);
    if (!assemblies || assemblies_count == 0) {
        ILRL_LOG_ERROR("No assemblies found in current domain");
        return nullptr;
    }

    ILRL_LOG_DEBUG("Scanning ", assemblies_count, " assemblies...");

    for (size_t i = 0; i < assemblies_count; ++i) {
        const auto image = Il2CppAPI::il2cpp_assembly_get_image(assemblies[i]);
        if (!image) {
            ILRL_LOG_WARN("Assembly at index", i, "has no image");
            continue;
        }

        const auto name = Il2CppAPI::il2cpp_image_get_name(image);

        if (const auto nameNoExt = Il2CppAPI::il2cpp_image_get_filename(image);
                (name && Name == name) || (nameNoExt && Name == nameNoExt)) {
            ILRL_LOG_INFO("Found matching assembly:", name ? name : nameNoExt, "(Image:", image, ")");
            return image;
        }

        ILRL_LOG_DEBUG("Assembly", name ? name : "unnamed", "doesn't match target", Name);
    }

    ILRL_LOG_ERROR("Assembly not found:", Name, "(Searched", assemblies_count, "assemblies)");
    return nullptr;
}

IL2CppReflector::Class::Class(const std::string& Namespace, const std::string& Name, const void* Image) {
    // Validate input parameters
    if (Name.empty()) {
        ILRL_LOG_ERROR("[Class::Class] Empty class name provided");
        return;
    }

    ILRL_LOG_DEBUG("[Class::Class] Searching for class: ", Namespace, ".", Name,
                   "in image: ", Image ? " specified " : "all assemblies");

    // Case 1: Specific image provided
    if (Image != nullptr) {
        _class = Il2CppAPI::il2cpp_class_from_name(Image, Namespace.c_str(), Name.c_str());
        if (_class) {
            ILRL_LOG_INFO("[Class::Class] Found class in specified image: ",
                          Namespace, ".", Name, " at address: ", _class);
            return;
        }
        ILRL_LOG_WARN("[Class::Class] Class not found in specified image: ",
                      Namespace, ".", Name, " image: ", Image);
        return;
    }

    // Case 2: Search all assemblies
    const auto domain = Il2CppAPI::il2cpp_domain_get();
    if (!domain) {
        ILRL_LOG_ERROR("[Class::Class] Failed to get current app domain");
        return;
    }

    size_t assemblies_count = 0;
    const auto assemblies = Il2CppAPI::il2cpp_domain_get_assemblies(domain, &assemblies_count);
    if (!assemblies || assemblies_count == 0) {
        ILRL_LOG_ERROR("[Class::Class] No assemblies found in current domain");
        return;
    }

    ILRL_LOG_DEBUG("[Class::Class] Scanning ", assemblies_count, " assemblies...");

    for (size_t i = 0; i < assemblies_count; ++i) {
        const auto assembly = assemblies[i];
        const auto image = Il2CppAPI::il2cpp_assembly_get_image(assembly);
        if (!image) {
            ILRL_LOG_WARN("[Class::Class] Assembly at index ", i, " has no image");
            continue;
        }

        const char* assembly_name = Il2CppAPI::il2cpp_image_get_name(image);
        ILRL_LOG_TRACE("[Class::Class] Checking assembly: ",
                       assembly_name ? assembly_name : "unnamed", " at index: ", i);

        void* found_class = Il2CppAPI::il2cpp_class_from_name(image, Namespace.c_str(), Name.c_str());
        if (found_class) {
            _class = found_class;
            ILRL_LOG_INFO("[Class::Class] Found class in assembly: ",
                          assembly_name ? assembly_name : "unnamed",
                          " at index: ", i, " address: ", _class);
            return;
        }
    }

    ILRL_LOG_ERROR("[Class::Class] Failed to locate class: ", Namespace, ".", Name,
                   " after scanning ", assemblies_count, " assemblies");
}

std::string IL2CppReflector::Class::ToString() const {
    if (!_class) {
        ILRL_LOG_WARN("Attempting ToString() on null class");
        return "NullClass";
    }
    return std::string(GetNamespace() + "." + GetName());
}

std::string IL2CppReflector::Class::GetNamespace() const {
    if (!_class) {
        ILRL_LOG_WARN("Attempting GetNamespace() on null class");
        return "";
    }
    const char *ns = Il2CppAPI::il2cpp_class_get_namespace(_class);
    return ns ? ns : "";
}

std::string IL2CppReflector::Class::GetName() const {
    if (!_class) {
        ILRL_LOG_WARN("Attempting GetName() on null class");
        return "";
    }
    const char *name = Il2CppAPI::il2cpp_class_get_name(_class);
    return name ? name : "";
}

bool IL2CppReflector::Class::IsAbstract() const {
    if (!_class) {
        ILRL_LOG_WARN("Attempting IsAbstract() on null class");
        return false;
    }
    return Il2CppAPI::il2cpp_class_is_abstract(_class);
}

bool IL2CppReflector::Class::IsInterface() const {
    if (!_class) {
        ILRL_LOG_WARN("Attempting IsInterface() on null class");
        return false;
    }
    return Il2CppAPI::il2cpp_class_is_interface(_class);
}

bool IL2CppReflector::Class::IsEnum() const {
    if (!_class) {
        ILRL_LOG_WARN("Attempting IsEnum() on null class");
        return false;
    }
    return Il2CppAPI::il2cpp_class_is_enum(_class);
}

bool IL2CppReflector::Class::IsGeneric() const {
    if (!_class) {
        ILRL_LOG_WARN("Attempting IsGeneric() on null class");
        return false;
    }
    return Il2CppAPI::il2cpp_class_is_generic(_class);
}

bool IL2CppReflector::Class::IsInflated() const {
    if (!_class) {
        ILRL_LOG_WARN("Attempting IsInflated() on null class");
        return false;
    }
    return Il2CppAPI::il2cpp_class_is_inflated(_class);
}

std::vector<IL2CppReflector::Class> IL2CppReflector::Class::GetInnerClasses() const {
    std::vector<Class> classes;

    if (!_class) {
        ILRL_LOG_WARN("Attempting GetInnerClasses() on null class");
        return classes;
    }

    ILRL_LOG_DEBUG("Getting inner classes for", ToString());

    void *currentClass = _class;
    do {
        void *iter = nullptr;
        size_t count = 0;

        while (void *nestedType = Il2CppAPI::il2cpp_class_get_nested_types(currentClass, &iter)) {
            classes.emplace_back(nestedType);
            count++;
        }

        ILRL_LOG_DEBUG("Found", count, "nested types in current class");
    } while ((currentClass = Il2CppAPI::il2cpp_class_get_parent(currentClass)) != nullptr);

    ILRL_LOG_INFO("Found", classes.size(), "inner classes total");
    return classes;
}

IL2CppReflector::Class IL2CppReflector::Class::GetInnerClass(const std::string &Name) const {
    if (!_class) {
        ILRL_LOG_WARN("Attempting GetInnerClass() on null class");
        return {};
    }

    ILRL_LOG_DEBUG("Searching for inner class", Name, "in", ToString());

    const auto classes = GetInnerClasses();
    if (classes.empty()) {
        ILRL_LOG_WARN("No inner classes found in", ToString());
        return {};
    }

    for (const auto &cls: classes) {
        if (cls.GetName() == Name) {
            ILRL_LOG_INFO("Found inner class", Name);
            return cls;
        }
    }

    ILRL_LOG_ERROR("Inner class", Name, "not found in", ToString());
    return {};
}

std::vector<IL2CppReflector::Field> IL2CppReflector::Class::GetFields(const bool ParentClass) const {
    std::vector<Field> fields;

    if (!_class) {
        ILRL_LOG_WARN("Attempting GetFields() on null class");
        return fields;
    }

    ILRL_LOG_DEBUG("Getting fields for", ToString(), "(includeParent:", ParentClass ? "true" : "false", ")");

    void *currentClass = _class;
    size_t totalFields = 0;

    do {
        void *iter = nullptr;
        size_t count = 0;

        while (void *fieldInfo = Il2CppAPI::il2cpp_class_get_fields(currentClass, &iter)) {
            fields.emplace_back(fieldInfo);
            count++;
        }

        ILRL_LOG_DEBUG("Found", count, "fields in current class");
        totalFields += count;

        if (!ParentClass) break;
    } while ((currentClass = Il2CppAPI::il2cpp_class_get_parent(currentClass)) != nullptr);

    ILRL_LOG_INFO("Found", totalFields, "fields total");
    return fields;
}

IL2CppReflector::Field IL2CppReflector::Class::GetField(const std::string &Name) const {
    if (!_class) {
        ILRL_LOG_WARN("Attempting GetField() on null class");
        return {};
    }

    ILRL_LOG_DEBUG("Looking for field", Name, "in class", ToString());

    if (const auto field = Il2CppAPI::il2cpp_class_get_field_from_name(_class, Name.c_str())) {
        ILRL_LOG_INFO("Found field", Name);
        return Field(field);
    }

    ILRL_LOG_ERROR("Field", Name, "not found in class", ToString());
    return {};
}

std::vector<IL2CppReflector::Method> IL2CppReflector::Class::GetMethods(const bool ParentClass) const {
    std::vector<Method> methods;

    if (!_class) {
        ILRL_LOG_WARN("Attempting GetMethods() on null class");
        return methods;
    }

    ILRL_LOG_DEBUG("Getting methods for", ToString(), "(includeParent:", ParentClass ? "true" : "false", ")");

    void *currentClass = _class;
    size_t totalMethods = 0;

    do {
        void *iter = nullptr;
        size_t count = 0;

        while (void *methodInfo = Il2CppAPI::il2cpp_class_get_methods(currentClass, &iter)) {
            methods.emplace_back(methodInfo);
            count++;
        }

        ILRL_LOG_DEBUG("Found ", count, " methods in current class");
        totalMethods += count;

        if (!ParentClass) break;
    } while ((currentClass = Il2CppAPI::il2cpp_class_get_parent(currentClass)) != nullptr);

    ILRL_LOG_INFO("Found ", totalMethods, " methods total");
    return methods;
}

IL2CppReflector::Method IL2CppReflector::Class::GetMethod(const std::string &Name, int args_count) const {
    if (!_class) {
        ILRL_LOG_WARN("Attempting GetMethod() on null class");
        return {};
    }

    ILRL_LOG_DEBUG("Looking for method ", Name, " in class ", ToString(), "(args_count:", args_count, ")");

    if (args_count != -1) {
        if (void *method = Il2CppAPI::il2cpp_class_get_method_from_name(_class, Name.c_str(), args_count)) {
            ILRL_LOG_INFO("Found method ", Name, " with ", args_count, " parameters");
            return Method(method);
        }

        ILRL_LOG_ERROR("Method", Name, "with", args_count, "parameters not found");
        return {};
    }

    const auto methods = GetMethods(false);
    for (const auto &methodBase: methods) {
        if (const char *methodName = Il2CppAPI::il2cpp_method_get_name(methodBase.GetMethodInfo());
                methodName && Name == methodName) {
            ILRL_LOG_INFO("Found method ", Name, "(parameter count unspecified)");
            return methodBase;
        }
    }

    ILRL_LOG_ERROR("Method", Name, "not found (parameter count unspecified)");
    return {};
}

IL2CppReflector::Method IL2CppReflector::Class::GetMethod(const std::string& Name,
                                                          const std::vector<std::string>& args_name) const {
    ILRL_LOG_DEBUG("[Class::GetMethod] Searching for method:", Name,
                   "with", args_name.size(), "parameters");

    if (Name.empty()) {
        ILRL_LOG_ERROR("[Class::GetMethod] Empty method name provided");
        return {};
    }

    const auto methods = GetMethods(false);
    ILRL_LOG_TRACE("[Class::GetMethod] Found", methods.size(), "methods to search");

    for (const auto& methodBase : methods) {
        const char* methodName = Il2CppAPI::il2cpp_method_get_name(methodBase.GetMethodInfo());
        if (!methodName) {
            ILRL_LOG_WARN("[Class::GetMethod] Failed to get name for method at:",
                          methodBase.GetMethodInfo());
            continue;
        }

        if (Name != methodName) {
            ILRL_LOG_TRACE("[Class::GetMethod] Name mismatch - searching:", Name,
                           "found:", methodName);
            continue;
        }

        auto count = Il2CppAPI::il2cpp_method_get_param_count(methodBase.GetMethodInfo());
        ILRL_LOG_DEBUG("[Class::GetMethod] Candidate method:", methodName,
                       "Parameter count: ", count);

        if (count != static_cast<uint32_t>(args_name.size())) {
            ILRL_LOG_WARN("[Class::GetMethod] Parameter count mismatch - expected: ",
                           args_name.size(), " actual: ", count);
            continue;
        }

        bool allParamsMatch = true;
        for (int i = 0; i < count; ++i) {
            if (std::string arg_name = Il2CppAPI::il2cpp_method_get_param_name(methodBase.GetMethodInfo(), i); args_name[i] != arg_name) {
                ILRL_LOG_DEBUG("[Class::GetMethod] Parameter name mismatch at index: ", i,
                               "expected:", args_name[i], "actual:", arg_name);
                allParamsMatch = false;
                break;
            }
        }

        if (allParamsMatch) {
            ILRL_LOG_DEBUG("[Class::GetMethod] Found matching method: ", methodName);
            return methodBase;
        }
    }

    ILRL_LOG_ERROR("[Class::GetMethod] Method not found:", Name,
                   "with specified parameters");
    return {};
}

std::vector<IL2CppReflector::Property> IL2CppReflector::Class::GetProperties(const bool ParentClass) const {
    std::vector<Property> properties;

    if (!_class) {
        ILRL_LOG_WARN("Attempting GetProperties() on null class");
        return properties;
    }

    ILRL_LOG_DEBUG("Getting properties for", ToString(), "(includeParent:", ParentClass ? "true" : "false", ")");

    void *currentClass = _class;
    size_t totalProperties = 0;

    do {
        void *iter = nullptr;
        size_t count = 0;

        while (void *propertyInfo = Il2CppAPI::il2cpp_class_get_properties(currentClass, &iter)) {
            properties.emplace_back(propertyInfo);
            count++;
        }

        ILRL_LOG_DEBUG("Found", count, "properties in current class");
        totalProperties += count;

        if (!ParentClass) break;
    } while ((currentClass = Il2CppAPI::il2cpp_class_get_parent(currentClass)) != nullptr);

    ILRL_LOG_INFO("Found", totalProperties, "properties total");
    return properties;
}

IL2CppReflector::Property IL2CppReflector::Class::GetProperty(const std::string &Name) const {
    if (!_class) {
        ILRL_LOG_WARN("Attempting GetProperty() on null class");
        return {};
    }

    ILRL_LOG_DEBUG("Looking for property", Name, "in class", ToString());

    if (void *property = Il2CppAPI::il2cpp_class_get_property_from_name(_class, Name.c_str())) {
        ILRL_LOG_INFO("Found property", Name);
        return Property(property);
    }

    ILRL_LOG_ERROR("Property", Name, "not found in class", ToString());
    return {};
}

IL2CppReflector::Class IL2CppReflector::Class::GetGeneric(const std::vector<void *> &templateTypes) const {
    if (!_class) {
        ILRL_LOG_WARN("Attempting GetGeneric() on null class");
        return *this;
    }

    if (!IsGeneric()) {
        ILRL_LOG_ERROR("Class", ToString(), "is not generic");
        return *this;
    }

    ILRL_LOG_DEBUG("Creating generic instance of ", ToString(), " with ", templateTypes.size(), " type arguments");

    const auto monoType = Il2CppAPI::il2cpp_type_get_object(Il2CppAPI::il2cpp_class_get_type(_class));
    if (!monoType) {
        ILRL_LOG_ERROR("Failed to get mono type for class ", ToString());
        return *this;
    }

    const auto args = UnityStruct::array<void *>::create(templateTypes);
    if (!args) {
        ILRL_LOG_ERROR("Failed to create type arguments array");
        return *this;
    }

    const auto genericType = MakeGenericType.Invoke<void *>(monoType, args.get());
    if (!genericType) {
        ILRL_LOG_ERROR("Failed to create generic type instance");
        return *this;
    }

    ILRL_LOG_INFO("Successfully created generic type instance");
    return Class(genericType);
}

void *IL2CppReflector::Class::CreateNewInstance() const {
    if (!_class) {
        ILRL_LOG_WARN("Attempting CreateNewInstance() on null class");
        return nullptr;
    }

    void *instance = Il2CppAPI::il2cpp_object_new(_class);
    if (instance) {
        ILRL_LOG_INFO("Created new instance of ", ToString(), " at ", instance);
    } else {
        ILRL_LOG_ERROR("Failed to create instance of ", ToString());
    }
    return instance;
}
