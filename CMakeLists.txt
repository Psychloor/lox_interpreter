cmake_minimum_required(VERSION 4.0)
project(lox_interpreter)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE LOX_HEADER_FILES
        LIST_DIRECTORIES false
        CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/include/lox_interpreter/*.hpp
)

file(GLOB_RECURSE LOX_SOURCE_FILES
        LIST_DIRECTORIES false
        CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_executable(${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)
target_sources(${PROJECT_NAME}
        PRIVATE
        main.cpp
        ${LOX_SOURCE_FILES}

        PUBLIC
        FILE_SET headers TYPE HEADERS
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include/
        FILES ${LOX_HEADER_FILES}
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX /utf-8)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()