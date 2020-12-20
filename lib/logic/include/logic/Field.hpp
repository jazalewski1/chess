#pragma once
#include "Piece.hpp"
#include <memory>

namespace logic
{
class Field 
{
public:
	Field();
	std::shared_ptr<Piece> getPiece() const;
	void setPiece(std::shared_ptr<Piece> new_piece);
private:
	std::shared_ptr<Piece> piece;
	int x_pos;
	int y_pos;
};
} // namespace logic