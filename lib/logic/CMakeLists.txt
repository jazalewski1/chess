set(
	HEADERS
	include/logic/Board.hpp
	include/logic/Piece.hpp
)

set(
	SOURCES
)

add_library(
	Logic
	${HEADERS}
	${SOURCES}
)

target_include_directories(
	Logic
	PUBLIC include
)

target_link_libraries(
	Logic
	Util
)

set_target_properties(
	Logic
	PROPERTIES
	LINKER_LANGUAGE CXX
)