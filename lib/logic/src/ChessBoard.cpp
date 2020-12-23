#include "logic/ChessBoard.hpp"
#include "logic/Piece.hpp"
#include "util/Vector2.hpp"
#include "util/Exception.hpp"
#include <algorithm>

namespace
{
using namespace logic;
std::vector<State> create_basic_setup()
{
	return {
		State::ROOK   ,State::KNIGHT ,State::BISHOP ,State::QUEEN  ,State::KING   ,State::BISHOP ,State::KNIGHT ,State::ROOK   ,
		State::PAWN   ,State::PAWN   ,State::PAWN   ,State::PAWN   ,State::PAWN   ,State::PAWN   ,State::PAWN   ,State::PAWN   ,
		State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,
		State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,
		State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,
		State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,State::EMPTY  ,
		State::PAWN   ,State::PAWN   ,State::PAWN   ,State::PAWN   ,State::PAWN   ,State::PAWN   ,State::PAWN   ,State::PAWN   ,
		State::ROOK   ,State::KNIGHT ,State::BISHOP ,State::QUEEN  ,State::KING   ,State::BISHOP ,State::KNIGHT ,State::ROOK   ,
	};
}
} // namespace

namespace logic
{
ChessBoard::ChessBoard()
{
	const auto states = create_basic_setup();

	constexpr auto size_x = 8;
	constexpr auto size_y = 8;
	constexpr auto size = size_x * size_y;

	fields.reserve(size);

	const auto linear_index = [size_x, size_y](int x, int y) { return y * size_x + x; };

	for(auto y = 0; y < size_y; ++y)
	{
		for(auto x = 0; x < size_x; ++x)
		{
			const auto index = linear_index(x, y);
			const auto state = states.at(index);

			const auto position = util::Vector2i{x, y};
			fields.push_back(Field{position, state});
		}
	}
}

State ChessBoard::get_piece_at(util::Vector2i position) const
{
	const auto field = try_find_field(position);
	return field->state;
}

void ChessBoard::move_piece(util::Vector2i source, util::Vector2i destination)
{
	auto source_field = try_find_field(source);
	auto destination_field = try_find_field(destination);
	
	const auto old_source_state = source_field->state;
	source_field->state = destination_field->state;
	destination_field->state = old_source_state;
}

ChessBoard::FieldsConstIter ChessBoard::find_field(util::Vector2i position) const
{
	const auto is_searched_position = [position](const Field& f) { return f.position == position; };
	return std::find_if(std::begin(fields), std::end(fields), is_searched_position);
}

ChessBoard::FieldsConstIter ChessBoard::try_find_field(util::Vector2i position) const
{
	const auto result = find_field(position);
	if(result == std::end(fields))
	{
		const auto message = std::string{
			"Position [" + std::to_string(position.x) + ", " + std::to_string(position.y) + "] is out of board bounds!"
		};
		throw util::OutOfBoundsException{message};
	}
	return result;
}

ChessBoard::FieldsIter ChessBoard::find_field(util::Vector2i position)
{
	const auto is_searched_position = [position](const Field& f) { return f.position == position; };
	return std::find_if(std::begin(fields), std::end(fields), is_searched_position);
}

ChessBoard::FieldsIter ChessBoard::try_find_field(util::Vector2i position)
{
	const auto result = find_field(position);
	if(result == std::end(fields))
	{
		const auto message = std::string{
			"Position [" + std::to_string(position.x) + ", " + std::to_string(position.y) + "] is out of board bounds!"
		};
		throw util::OutOfBoundsException{message};
	}
	return result;
}
} // namespace logic