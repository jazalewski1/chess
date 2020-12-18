set(EXECUTABLE_OUTPUT_PATH ${TEST_EXECUTABLE_OUTPUT_PATH})

add_executable(
	UnitTests
	src/FieldTest.cpp
)

target_link_libraries(
	UnitTests
	Logic
	gtest
	gtest_main
	gmock
)
add_test(NAME UnitTests COMMAND UnitTests)