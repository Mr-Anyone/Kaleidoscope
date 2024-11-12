cmake_minimum_required(VERSION 3.10.0)

project(MyFirstProgrammingLanguage)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

add_subdirectory(vendor)

add_executable(main main.cpp)

# stuff that I got from llvm-config
set(LLVM_INCLUDE_DIR 
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/llvm-project/llvm/include
    ${CMAKE_CURRENT_BINARY_DIR}/vendor/llvm-project/llvm/include
)

target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${LLVM_INCLUDE_DIR})
#target_link_libraries(main LLVMCore LLV)
target_link_libraries(main LLVMCore LLVMRemarks LLVMBitstreamReader LLVMBinaryFormat LLVMTargetParser LLVMSupport LLVMDemangle)


#clang++ -g -O3 toy.cpp `llvm-config --cxxflags --ldflags --system-libs --libs core` -o toy

#-I/home/vhe/vscode/Kaleidoscope/vendor/llvm-project/llvm/include 
#-I/home/vhe/vscode/Kaleidoscope/build/vendor/llvm-project/llvm/include 

# compiler flags
#-std=c++17   -fno-exceptions -funwind-tables -fno-rtti 

#-L/home/vhe/vscode/Kaleidoscope/build/vendor/llvm-project/llvm/lib 

# libs
#-lLLVMCore -lLLVMRemarks -lLLVMBitstreamReader -lLLVMBinaryFormat -lLLVMTargetParser -lLLVMSupport -lLLVMDemangle

#-lrt -ldl -lm -lz -lxml2

