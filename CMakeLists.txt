cmake_minimum_required(VERSION 3.20)
project(cpp_dsa_journey LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)   # lets VS Code / clangd understand the project

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

option(ENABLE_SANITIZERS "Build with AddressSanitizer and UBSan" ON)

enable_testing()

# Every .cpp under leetcode/ and learncpp/ becomes its own executable and test.
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
  ${CMAKE_SOURCE_DIR}/leetcode/*.cpp
  ${CMAKE_SOURCE_DIR}/learncpp/*.cpp)

foreach(src IN LISTS SOURCES)
  file(RELATIVE_PATH rel ${CMAKE_SOURCE_DIR} ${src})
  string(REGEX REPLACE "\\.cpp$" "" name ${rel})
  string(REPLACE "/" "__" name ${name})

  add_executable(${name} ${src})
  target_include_directories(${name} PRIVATE ${CMAKE_SOURCE_DIR}/include)
  target_compile_options(${name} PRIVATE -Wall -Wextra -Wpedantic -Wshadow)

  if(ENABLE_SANITIZERS AND CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(${name} PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(${name} PRIVATE -fsanitize=address,undefined)
  endif()

  add_test(NAME ${name} COMMAND ${name})
endforeach()
