set(EXECUTABLE_OUTPUT_PATH ${TEST_EXECUTABLE_OUTPUT_PATH})

add_executable(
	FieldTest
	src/FieldTest.cpp
)

target_link_libraries(
	FieldTest
	Logic
	gtest
	gtest_main
	gmock
)
add_test(NAME FieldTest COMMAND FieldTest)