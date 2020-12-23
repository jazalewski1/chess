#include "logic/Field.hpp"

namespace logic
{
Field::Field()
{}

Field::Field(const int x, const int y)
{
    m_position = {x,y};
}

Field::Field(const util::Vector2i position)
{
    m_position = position;
}

std::shared_ptr<Piece> Field::get_piece() const
{
    return piece;
}

void Field::set_piece(std::shared_ptr<Piece> new_piece)
{
    piece=new_piece;
}

util::Vector2i Field::get_position()
{
    return m_position;
}
} // namespace logic