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

#pragma once

#include "IL2CppReflector/api/string.hpp"

#include <cstring>
#include <memory>
#include <stdexcept>
#include <vector>

namespace UnityStruct {
    template<typename T>
    struct array {
        void *m_class{};
        void *m_monitor{};
        void *m_bounds{};
        uintptr_t m_length{};
        T *m_values;

        array() = default;

        explicit array(void *ptr);

        struct array_deleter {
            void operator()(array *arr) {
                if (arr) {
                    char *buffer = reinterpret_cast<char *>(arr) - (sizeof(array) - sizeof(T *));
                    arr->~array();
                    ::operator delete(buffer);
                }
            }
        };

        static std::unique_ptr<array, array_deleter> create(const std::vector<T> &vec);

        T &at(size_t index);

        void set(size_t index, const T &value);

        void fill(const T &value);

        void clear();

        std::vector<T> to_vector() const;

        [[nodiscard]] size_t size() const;

        [[nodiscard]] bool empty() const;

        T &front();

        T &back();

        T *data();

        T *begin();

        T *end();

        const T *begin() const;

        const T *end() const;
    };

    template<typename T>
    struct list {
        void *m_class{};
        void *m_monitor{};
        array<T> m_data{};

        array<T> &get_data();

        T &at(size_t index);

        void set(size_t index, const T &value);

        void fill(const T &value);

        void clear();
    };

    struct string {
        void *m_class{};
        void *m_monitor{};
        int m_length{};
        wchar_t m_data[];

        string() = default;

        static string *create(const std::string &str);

        std::string str();

        wchar_t &at(size_t pos);

        [[nodiscard]] bool equals(const string &other) const;

        [[nodiscard]] bool empty() const;

        [[nodiscard]] size_t length() const;

        [[nodiscard]] size_t size() const;

        [[nodiscard]] const wchar_t *c_str() const;

        [[nodiscard]] const wchar_t *data() const;

        bool operator==(const string &other) const { return equals(other); }
        bool operator!=(const string &other) const { return !equals(other); }
    };

    template<typename Key, typename Value>
    struct dictionary {
        struct entry {
            int m_hashCode{};
            int m_next{};
            Key m_key{};
            Value m_value{};
        };

        void *m_class{};
        void *m_monitor{};
        array<int> *m_buckets{};
        array<entry *> *m_entries;
        int m_count{};
        int m_version{};
        int m_freeList{};
        int m_freeCount{};
        void *m_comparer{};
        void *m_keys{};
        void *m_values{};

        Value &get_value(Key key);

        Key &get_key_by_index(int index);

        Value &get_value_by_index(int index);
    };
}


template<typename T>
UnityStruct::array<T>::array(void *ptr) {
    memcpy(this, ptr, sizeof(*this) - sizeof(T *));
    const size_t nonElementsSize = sizeof(*this) - sizeof(T *);
    m_values = reinterpret_cast<T *>(static_cast<char *>(ptr) + nonElementsSize);
}

template<typename T>
std::unique_ptr<UnityStruct::array<T>, typename UnityStruct::array<T>::array_deleter> UnityStruct::array<
    T>::create(const std::vector<T> &vec) {
    const size_t data_size = vec.size() * sizeof(T);
    const size_t total_size = sizeof(array) - sizeof(T *) + data_size;

    void *buffer = ::operator new(total_size);

    try {
        auto *result = new(buffer) array;
        result->m_length = vec.size();
        result->m_values = reinterpret_cast<T *>(static_cast<char *>(buffer) + sizeof(array) - sizeof(T *));

        if constexpr (std::is_same_v<T, bool>) {
            for (size_t i = 0; i < vec.size(); ++i) {
                result->m_values[i] = vec[i];
            }
        } else {
            std::memcpy(result->m_values, vec.data(), data_size);
        }

        return std::unique_ptr<array, array_deleter>(result);
    } catch (...) {
        ::operator delete(buffer);
        throw;
    }
}

template<typename T>
T &UnityStruct::array<T>::at(size_t index) {
    if (index >= m_length) {
        throw std::out_of_range("Index out of range");
    }
    return m_values[index];
}

template<typename T>
void UnityStruct::array<T>::set(const size_t index, const T &value) {
    at(index) = value;
}

template<typename T>
size_t UnityStruct::array<T>::size() const {
    return m_length;
}

template<typename T>
bool UnityStruct::array<T>::empty() const {
    return m_length == 0;
}

template<typename T>
void UnityStruct::array<T>::fill(const T &value) {
    std::fill_n(m_values, m_length, value);
}

template<typename T>
void UnityStruct::array<T>::clear() {
    fill(T{});
}

template<typename T>
std::vector<T> UnityStruct::array<T>::to_vector() const {
    return std::vector<T>(m_values, m_values + m_length);
}

template<typename T>
T &UnityStruct::array<T>::front() {
    if (empty()) {
        throw std::out_of_range("array is empty");
    }
    return m_values[0];
}

template<typename T>
T &UnityStruct::array<T>::back() {
    if (empty()) {
        throw std::out_of_range("Array is empty");
    }
    return m_values[m_length - 1];
}

template<typename T>
T *UnityStruct::array<T>::data() {
    return m_values;
}

template<typename T>
T *UnityStruct::array<T>::begin() {
    return m_values;
}

template<typename T>
T *UnityStruct::array<T>::end() {
    return m_values + m_length;
}

template<typename T>
const T *UnityStruct::array<T>::begin() const {
    return m_values;
}

template<typename T>
const T *UnityStruct::array<T>::end() const {
    return m_values + m_length;
}

template<typename T>
UnityStruct::array<T> &UnityStruct::list<T>::get_data() {
    return m_data;
}

template<typename T>
T &UnityStruct::list<T>::at(size_t index) {
    return m_data.at(index);
}

template<typename T>
void UnityStruct::list<T>::set(size_t index, const T &value) {
    m_data.set(index, value);
}

template<typename T>
void UnityStruct::list<T>::fill(const T &value) {
    m_data.fill(value);
}

template<typename T>
void UnityStruct::list<T>::clear() {
    m_data.clear();
}

template<typename Key, typename Value>
Value &UnityStruct::dictionary<Key, Value>::get_value(Key key) {
    for (int i = 0; i < m_count; ++i) {
        if (m_entries->at(i)->m_key == key) return m_entries->at(i)->m_value;
    }
    return Value{};
}

template<typename Key, typename Value>
Key &UnityStruct::dictionary<Key, Value>::get_key_by_index(int index) {
    return m_entries->at(index)->m_key;
}

template<typename Key, typename Value>
Value &UnityStruct::dictionary<Key, Value>::get_value_by_index(int index) {
    return m_entries->at(index)->m_value;
}

inline UnityStruct::string *UnityStruct::string::create(const std::string &str) {
    return static_cast<string *>(Il2CppAPI::il2cpp_string_new(str.c_str()));
}
