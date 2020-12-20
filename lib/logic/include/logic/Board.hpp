#pragma once

#include "util/Vector2.hpp"
#include <memory>

namespace logic
{
struct Piece;

class Board
{
public:
	virtual ~Board()
	{
	}

	virtual Piece& get_piece_at(util::Vector2i) const = 0;

	virtual void move_piece(util::Vector2i, util::Vector2i) = 0;
};
} // namespace logic