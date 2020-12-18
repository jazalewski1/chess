function(add_test_module)
	cmake_parse_arguments(
		"ARG"
		""
		"MODULE_NAME;MODULE_PATH"
		"DEPENDENCIES"
		${ARGN}
	)

	add_executable(
		${ARG_MODULE_NAME}
		${ARG_MODULE_PATH}
	)

	target_link_libraries(
		${ARG_MODULE_NAME}
		${ARG_DEPENDENCIES}
	)

	add_test(NAME ${ARG_MODULE_NAME} COMMAND ${ARG_MODULE_NAME})
endfunction(add_test_module)