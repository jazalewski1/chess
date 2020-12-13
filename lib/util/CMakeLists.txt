set(
	HEADERS
	include/util/Vector2.hpp
)

set(
	SOURCES
)

add_library(Util
	${HEADERS}
	${SOURCES}
)

target_include_directories(
	Util
	PUBLIC include
)

set_target_properties(
	Util
	PROPERTIES
	LINKER_LANGUAGE CXX
)