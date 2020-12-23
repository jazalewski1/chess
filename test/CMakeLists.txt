set(EXECUTABLE_OUTPUT_PATH ${TEST_EXECUTABLE_OUTPUT_PATH})

add_executable(
	FieldTests
	src/FieldTests.cpp
)

target_link_libraries(
	FieldTests
	Logic
	gtest
	gtest_main
	gmock
)
add_test(NAME FieldTests COMMAND FieldTests)