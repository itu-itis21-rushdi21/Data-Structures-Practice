cmake_minimum_required(VERSION 3.10)
project("${fileDirname}/..")

set(CMAKE_CXX_STANDARD 17)

RUNTIME_OUTPUT_DIRECTORY(${fileDirname}/../bin)

file(GLOB_RECURSE SRC_FILES "src/*.cpp")
file(GLOB_RECURSE HEADER_FILES "src/*.h")

add_executable(${fileBasenameNoExtension} ${fileDirname}/../src/${fileBasenameNoExtension}.cpp)








