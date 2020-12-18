set(EXECUTABLE_OUTPUT_PATH ${TEST_EXECUTABLE_OUTPUT_PATH})

include(${PROJECT_SOURCE_DIR}/cmake/AddTestModule.cmake)

add_test_module(
	MODULE_NAME DummyTests
	MODULE_PATH src/DummyTests.cpp
	DEPENDENCIES
	gtest
	gtest_main
	gmock
	Logic
	Util
)

# wait for other tests here