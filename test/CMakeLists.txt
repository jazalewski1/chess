set(EXECUTABLE_OUTPUT_PATH ${TEST_EXECUTABLE_OUTPUT_PATH})

add_executable(
	DummyTests
	src/DummyTests.cpp
)

target_link_libraries(
	DummyTests
	gtest
	gtest_main
	gmock
)
add_test(NAME DummyTests COMMAND DummyTests)