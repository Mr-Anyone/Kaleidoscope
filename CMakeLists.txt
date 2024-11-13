cmake_minimum_required(VERSION 3.1)

project(llvm_playground)
set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp)
target_include_directories(main ${CMAKE_CURRENT_SOURCE_DIR}/include)
