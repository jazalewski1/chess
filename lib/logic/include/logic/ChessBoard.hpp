#pragma once

#include "logic/Board.hpp"
#include "util/Vector2.hpp"
#include <vector>

namespace logic
{
class ChessBoard : public Board
{
public:
	ChessBoard();

	State get_piece_at(util::Vector2i) const override;

	void move_piece(util::Vector2i, util::Vector2i) override;

private:
	using States = std::vector<State>;

	const util::Vector2i size;
	States states;

	inline auto linear_index(util::Vector2i position) const -> States::size_type;

	inline void throw_if_out_of_bounds(util::Vector2i position) const;
};
} // namespace logic