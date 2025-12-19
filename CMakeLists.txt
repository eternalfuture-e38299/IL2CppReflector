cmake_minimum_required(VERSION 3.22.1)
project(IL2CppReflector)

set(CMAKE_CXX_STANDARD 17)
set(IL2CPPREFLECTOR_ENABLE_LOGGING ON)

add_library(IL2CppReflector STATIC
        src/il2cpp_reflector.cpp
        src/logger.cpp
        src/class.cpp
        src/field.cpp
        src/method.cpp
        src/struct.cpp
        src/type.cpp
        src/property.cpp
        src/tool.cpp
)

target_include_directories(IL2CppReflector
        PUBLIC
        includes
)

if(IL2CPPREFLECTOR_ENABLE_LOGGING)
    add_definitions(-DIL2CPPREFLECTOR_ENABLE_LOGGING)
    message(STATUS "Logging EFModLoader system enabled")
else()
    message(STATUS "Logging EFModLoader system disabled")
endif()