
add_executable(main main.cpp)

target_include_directories(main 
    PUBLIC 
    ${llvm_BINARY_DIR}/include
    ${llvm_SOURCE_DIR}/llvm/include
)

target_link_libraries(main
    LLVMCore
    LLVMRemarks
    LLVMBitstreamReader
    LLVMBinaryFormat
    LLVMTargetParser
    LLVMSupport 
    LLVMDemangle)

add_executable(
    lexer 
    lexer.cpp
)
#-I/home/vhe/vscode/Kaleidoscope/build/_deps/llvm-src/llvm/include 
#-I/home/vhe/vscode/Kaleidoscope/build/_deps/llvm-build/include
#-I/home/vhe/vscode/Kaleidoscope/build/_deps/llvm-src/llvm/include 
#-L/home/vhe/vscode/Kaleidoscope/build/_deps/llvm-build/lib 
#

#-lrt -ldl -lm -lz -lxml2

