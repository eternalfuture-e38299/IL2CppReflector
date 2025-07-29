/*******************************************************************************
 * 文件名称: il2cpp_reflector
 * 项目名称: IL2CppReflector
 * 创建时间: 25-7-20
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

#include <functional>

namespace IL2CppReflector {

    class HookWrapper {
        public:

            struct Info {
                void* address;
                void* replace_func;
                void** origin_func;
            };

            using hookFunc = std::function<bool(const Info &)>;
            using unHookFunc = std::function<bool(void*)>;

            static void SetHookFun(hookFunc hook_func, unHookFunc un_hook_func);

            static bool DoHook(const Info& info);
            static bool DoUnHook(void* address);

        private:
            inline static hookFunc Hook;
            inline static unHookFunc UnHook;
    };

    inline std::vector<std::function<void()>> OnLoadedEvents{};
    void AddOnLoadedEvent(const std::function<void()> &even);

    inline int (*old_il2cpp_init)(const char*) = nullptr;
    int hook_il2cpp_init(const char* domain_name);

    bool init_from_handle(void *handle);

    bool init_sym(void *handle);
    bool init_hook();
    bool init_ref();
    bool init_type();

}
