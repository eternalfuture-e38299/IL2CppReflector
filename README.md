# IL2CppReflector 🌍 [English](README-en.md) | [Русский](README-ru.md)

> 🔍 一个轻量级跨平台C++工具，用于反射IL2CPP游戏中的结构，包括类、方法、字段、类型等。

## 📌 简介

**IL2CppReflector** 是一个C++库，旨在解析和分析从Unity游戏中提取的IL2CPP元数据文件。它提供了一种清晰且模块化的方式来与类定义、字段、属性、方法等IL2CPP编码的结构元素进行交互。

* 该项目非常适合希望构建自定义IL2CPP分析或反编译工具的开发者、逆向工程师或工具作者。

## 🧰 功能

- 跨平台支持
- 动态支持多个Unity版本
- 每个IL2CPP组件的模块化头文件：类、方法、字段、属性等
- 最小依赖（仅需UTF8支持）
- 易于集成的CMake构建系统
- 提供Hook机制和日志系统

## 🚀 快速开始

### 1. 设置日志输出（可选）

```cpp
#include <spdlog/spdlog.h>

IL2CppReflector::Logger::SetOutputFunction([](const IL2CppReflector::Logger::Record &record) -> void {
    switch (record.level) {
        case IL2CppReflector::Logger::Level::Trace:
            spdlog::trace("[{}:{} ({})] {}", record.sourceFile, record.sourceLine, record.sourceFunction, record.message);
        break;
        case IL2CppReflector::Logger::Level::Debug:
            spdlog::debug("[{}:{} ({})] {}", record.sourceFile, record.sourceLine, record.sourceFunction, record.message);
        break;
// ...其他日志级别处理
}
});
```

### 2. 设置Hook回调

```cpp
#include <dobby.h>

IL2CppReflector::HookWrapper::SetHookFun(
[](const IL2CppReflector::HookWrapper::Info& info) -> bool {
    return !DobbyHook(info.address, info.replace_func, info.origin_func);
},
[](void* address) -> bool {
    return !DobbyDestroy(address);
});
```

### 3. 初始化反射器

```cpp
void* handle = ... //il2cpp模块的句柄
IL2CppReflector::init_from_handle(handle);
```

### 4. 使用反射功能

```cpp
/**
* 使用IL2CppReflector API的代码必须在此调用，或者在il2cpp_init已调用的情况下调用，否则无效
**/
IL2CppReflector::AddOnLoadedEvent([]() -> void {
    // 获取类和方法信息
    auto targetClass = IL2CppReflector::Class("NamespaceA", "ClassA",
    IL2CppReflector::GetImage("Assembly-CSharp.dll"));

    auto targetMethod = targetClass.GetMethod("MethodA");

    // 使用方法指针进行Hook
    void* originalMethod;
    DobbyHook(targetMethod.GetMethodPointer(),
    (void*)hookFunction, &originalMethod);
});
```

## 🛠️ 构建说明

### 前提条件

- 兼容C++17的编译器
- [CMake](https://cmake.org/)（推荐3.10以上版本）
