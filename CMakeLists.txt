cmake_minimum_required(VERSION 3.10.0)

project(MyFirstProgrammingLanguage)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

add_subdirectory(vendor)

add_executable(main main.cpp)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(main LLVMCore)