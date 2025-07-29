/*******************************************************************************
 * 文件名称: debugger
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
     * @brief 设置调试器代理选项
     * @param options 选项字符串
     */
    DEFINE_IL2CPP_API(void, il2cpp_debugger_set_agent_options, const char* options)

    /**
     * @brief 检查调试器是否已附加
     * @return 调试器是否已附加
     */
    DEFINE_IL2CPP_API(bool, il2cpp_is_debugger_attached,)

    /**
     * @brief 注册调试器传输代理
     * @param debuggerTransport 调试器传输接口(原始类型: Il2CppDebuggerTransport*)
     */
    DEFINE_IL2CPP_API(void, il2cpp_register_debugger_agent_transport, void* debuggerTransport)
}
