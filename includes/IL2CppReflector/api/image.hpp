/*******************************************************************************
 * 文件名称: image
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
#include "api_define.hpp"

namespace Il2CppAPI {
    /**
     * @brief 获取镜像所属程序集
     * @param image 镜像指针(原始类型: const Il2CppImage*)
     * @return 程序集指针(原始类型: const Il2CppAssembly*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_image_get_assembly, const void* image)

    /**
     * @brief 获取镜像名称
     * @param image 镜像指针(原始类型: const Il2CppImage*)
     * @return 镜像名称字符串
     */
    DEFINE_IL2CPP_API(const char*, il2cpp_image_get_name, const void* image)

    /**
     * @brief 获取镜像文件名
     * @param image 镜像指针(原始类型: const Il2CppImage*)
     * @return 镜像文件名字符串
     */
    DEFINE_IL2CPP_API(const char*, il2cpp_image_get_filename, const void* image)

    /**
     * @brief 获取镜像入口点方法
     * @param image 镜像指针(原始类型: const Il2CppImage*)
     * @return 方法信息指针(原始类型: const MethodInfo*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_image_get_entry_point, const void* image)

    /**
     * @brief 获取镜像中的类数量
     * @param image 镜像指针(原始类型: const Il2CppImage*)
     * @return 类数量
     */
    DEFINE_IL2CPP_API(size_t, il2cpp_image_get_class_count, const void* image)

    /**
     * @brief 获取镜像中指定索引的类
     * @param image 镜像指针(原始类型: const Il2CppImage*)
     * @param index 类索引
     * @return 类指针(原始类型: const Il2CppClass*)
     */
    DEFINE_IL2CPP_API(void*, il2cpp_image_get_class, const void* image, size_t index)
}
