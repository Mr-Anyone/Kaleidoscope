cmake_minimum_required(VERSION 3.10.0)

project(MyFirstProgrammingLanguage)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

include(FetchContent)
FetchContent_Declare(
  llvm
  URL https://github.com/llvm/llvm-project/archive/refs/tags/llvmorg-19.1.3.tar.gz
  SOURCE_SUBDIR llvm
)

FetchContent_MakeAvailable(llvm)

add_subdirectory(src)

