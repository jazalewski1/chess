#pragma once

#include "util/Vector2.hpp"

namespace logic
{
enum class State {EMPTY, PAWN, KING, KNIGHT, BISHOP, ROOK, QUEEN};

class Board
{
public:
	virtual ~Board()
	{
	}

	virtual State get_piece_at(util::Vector2i) const = 0;

	virtual void move_piece(util::Vector2i, util::Vector2i) = 0;
};
} // namespace logic