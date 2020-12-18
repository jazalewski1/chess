cmake_minimum_required(VERSION 3.16)
project(ChessGame LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
	googletest
	GIT_REPOSITORY "https://github.com/google/googletest.git"
	GIT_TAG master
)
FetchContent_MakeAvailable(googletest)

set(CMAKE_CXX_STANDARD 17)
set(LINKER_LANGUAGE CXX)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(TEST_EXECUTABLE_OUTPUT_PATH ${EXECUTABLE_OUTPUT_PATH}/test)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin/libs)

enable_testing()

add_executable(Chess app/Main.cpp)

add_subdirectory(${PROJECT_SOURCE_DIR}/lib/logic)
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/util)
add_subdirectory(${PROJECT_SOURCE_DIR}/test)