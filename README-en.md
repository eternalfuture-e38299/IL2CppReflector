# IL2CppReflector

> 🔍 A lightweight cross-platform C++ tool for reflecting IL2CPP game structures including classes, methods, fields, types, and more.

## 📌 Introduction

**IL2CppReflector** is a C++ library designed to parse and analyze IL2CPP metadata files extracted from Unity games. It provides a clean and modular approach to interact with IL2CPP-encoded structural elements like class definitions, fields, properties, and methods.

* This project is ideal for developers, reverse engineers, or tool authors looking to build custom IL2CPP analysis or decompilation tools.

## 🧰 Features

- Cross-platform support
- Dynamic support for multiple Unity versions
- Modular headers for each IL2CPP component: classes, methods, fields, properties, etc.
- Minimal dependencies (only requires UTF-8 support)
- Easy-to-integrate CMake build system
- Built-in hook mechanism and logging system

## 🚀 Quick Start

### 1. Configure Logging (Optional)

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
// ...Other log level handlers
}
});
```

### 2. Set Up Hook Callbacks

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

### 3. Initialize Reflector

```cpp
void* handle = ... // Handle to il2cpp module
IL2CppReflector::init_from_handle(handle);
```

### 4. Use Reflection Features

```cpp
/**
* Code using IL2CppReflector API must be called within this callback,
* or after il2cpp_init has been called, otherwise it will be invalid
**/
IL2CppReflector::AddOnLoadedEvent([]() -> void {
// Get class and method information
auto targetClass = IL2CppReflector::Class("NamespaceA", "ClassA",
IL2CppReflector::GetImage("Assembly-CSharp.dll"));

auto targetMethod = targetClass.GetMethod("MethodA");

// Hook using method pointer
void* originalMethod;
DobbyHook(targetMethod.GetMethodPointer(),
(void*)hookFunction, &originalMethod);
});
```

## 🛠️ Building Instructions

### Prerequisites

- C++17 compatible compiler
- [CMake](https://cmake.org/) (version 3.10+ recommended)