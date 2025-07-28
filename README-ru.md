# IL2CppReflector

> 🔍 Легковесный кроссплатформенный инструмент на C++ для рефлексии структур IL2CPP в играх, включая классы, методы, поля, типы и другие элементы.

## 📌 Введение

**IL2CppReflector** — это библиотека на C++, предназначенная для анализа метаданных IL2CPP, извлеченных из игр на Unity. Она предоставляет удобный и модульный способ взаимодействия с закодированными в IL2CPP структурными элементами, такими как определения классов, поля, свойства и методы.

* Проект идеально подходит для разработчиков, реверс-инженеров или авторов инструментов, которые хотят создать собственные решения для анализа или декомпиляции IL2CPP.

## 🧰 Возможности

- Кроссплатформенная поддержка
- Динамическая поддержка различных версий Unity
- Модульные заголовочные файлы для каждого компонента IL2CPP: классы, методы, поля, свойства и т.д.
- Минимальные зависимости (требуется только поддержка UTF-8)
- Простая интеграция с системой сборки CMake
- Встроенные механизмы хуков и система логирования

## 🚀 Быстрый старт

### 1. Настройка логирования (опционально)

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
// ...Обработка других уровней логирования
}
});
```

### 2. Настройка хуков

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

### 3. Инициализация рефлектора

```cpp
void* handle = ... // Указатель на модуль il2cpp
IL2CppReflector::init_from_handle(handle);
```

### 4. Использование возможностей рефлексии

```cpp
/**
* Код, использующий API IL2CppReflector, должен вызываться внутри этого колбэка
* или после вызова il2cpp_init, иначе он будет недействителен
**/
IL2CppReflector::AddOnLoadedEvent([]() -> void {
// Получение информации о классе и методе
auto targetClass = IL2CppReflector::Class("NamespaceA", "ClassA",
IL2CppReflector::GetImage("Assembly-CSharp.dll"));

auto targetMethod = targetClass.GetMethod("MethodA");

// Установка хука с использованием указателя на метод
void* originalMethod;
DobbyHook(targetMethod.GetMethodPointer(),
(void*)hookFunction, &originalMethod);
});
```

## 🛠️ Инструкции по сборке

### Требования

- Компилятор с поддержкой C++17
- [CMake](https://cmake.org/) (рекомендуется версия 3.10 и выше)