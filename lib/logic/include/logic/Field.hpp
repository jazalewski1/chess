#pragma once
#include "Piece.hpp"
#include <memory>
#include "util/Vector2.hpp"

namespace logic
{
class Field 
{
public:
    Field();
    Field(const int x, const int y);
    Field(const util::Vector2i position);
    std::shared_ptr<Piece> get_piece() const;
    void set_piece(std::shared_ptr<Piece> new_piece);
    util::Vector2i get_position();
private:
    std::shared_ptr<Piece> piece;
    util::Vector2i m_position;
};
} // namespace logic