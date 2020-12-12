cmake_minimum_required(VERSION 3.16)
project(ChessGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(LINKER_LANGUAGE CXX)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(Chess app/Main.cpp)