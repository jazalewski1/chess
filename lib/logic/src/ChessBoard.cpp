#include "logic/ChessBoard.hpp"
#include "util/Vector2.hpp"
#include "util/Exception.hpp"

namespace
{
constexpr auto size_x = 8; // TODO: not global, but these should be moved to a class called Configuration or BoardSettings
constexpr auto size_y = 8;

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
ChessBoard::ChessBoard() :
	size{size_x, size_y}, states{create_basic_setup()}
{
}

State ChessBoard::get_piece_at(util::Vector2i position) const
{
	throw_if_out_of_bounds(position);
	const auto index = linear_index(position);
	return states.at(index);
}

void ChessBoard::move_piece(util::Vector2i source, util::Vector2i destination)
{
	throw_if_out_of_bounds(source);
	throw_if_out_of_bounds(destination);
	
	const auto source_index = linear_index(source);
	const auto destination_index = linear_index(destination);

	auto& source_state = states.at(source_index);
	auto& destination_state = states.at(destination_index);

	const auto old_source_state = source_state;
	source_state = destination_state;
	destination_state = old_source_state;
}

inline auto ChessBoard::linear_index(util::Vector2i position) const -> ChessBoard::States::size_type
{
	return position.y * size.x + position.x;
}

inline void ChessBoard::throw_if_out_of_bounds(util::Vector2i position) const
{
	const auto is_larger = [this](util::Vector2i position){ return position.x >= size.x or position.y >= size.y; };
	const auto is_negative = [this](util::Vector2i position){ return position.x < 0 or position.y < 0; };

	if(is_larger(position) or is_negative(position))
	{
		const auto message = std::string{
			"Position [" + std::to_string(position.x) + ", " + std::to_string(position.y) + "] is out of board bounds!"
		};
		throw util::OutOfBoundsException{message};
	}
}
} // namespace logic