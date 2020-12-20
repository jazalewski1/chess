#include "logic/Field.hpp"

namespace logic
{
Field::Field()
{}

std::shared_ptr<Piece> Field::getPiece() const
{
	return piece;
}

void Field::setPiece(std::shared_ptr<Piece> new_piece)
{
	piece=new_piece;
}
} // namespace logic