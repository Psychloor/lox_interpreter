cmake_minimum_required(VERSION 4.0)
project(lox_interpreter)

set(CMAKE_CXX_STANDARD_REQUIRED  ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(LOX_SOURCE_FILES
        # CPP Files
        main.cpp
        src/lox.cpp
        src/scanner.cpp
        src/token.cpp
        src/generate_ast.cpp

        # HPP Files
        src/expression.hpp
        src/generate_ast.hpp
        src/lox.hpp
        src/scanner.hpp
        src/token.hpp
        src/token_type.hpp

        # IPP Files
        src/token.ipp
)

add_executable(${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)

target_sources(${PROJECT_NAME} PRIVATE ${LOX_SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/)

# Warnings (per-compiler)
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive- /Zc:__cplusplus /utf-8)
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
    if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
        target_compile_options(${PROJECT_NAME} PRIVATE -Wconversion -Wsign-conversion)
    endif ()
endif ()