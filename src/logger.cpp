/*******************************************************************************
 * 文件名称: logger
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

#include "IL2CppReflector/logger.hpp"

void IL2CppReflector::Logger::SetOutputFunction(LogOutputFunc outputFunc) {
    std::lock_guard lock(mutex_);
    outputFunc_ = std::move(outputFunc);
}

void IL2CppReflector::Logger::SetMinLevel(const Level level) {
    std::lock_guard lock(mutex_);
    minLevel_ = level;
}

IL2CppReflector::Logger::Level IL2CppReflector::Logger::GetMinLevel() {
    std::lock_guard lock(mutex_);
    return minLevel_;
}


const char *IL2CppReflector::Logger::LevelToString(const Level level) {
    switch (level) {
        case Level::Trace: return "TRACE";
        case Level::Debug: return "DEBUG";
        case Level::Info: return "INFO";
        case Level::Warning: return "WARN";
        case Level::Error: return "ERROR";
        case Level::Critical: return "CRITICAL";
        default: return "UNKNOWN";
    }
}