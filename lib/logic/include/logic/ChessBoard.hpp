#pragma once

#include "logic/Board.hpp"
#include "util/Vector2.hpp"
#include <vector>

namespace logic
{
struct Field
{
	const util::Vector2i position;
	State state;
};

class ChessBoard : public Board
{
public:
	ChessBoard();

	State get_piece_at(util::Vector2i) const override;

	void move_piece(util::Vector2i, util::Vector2i) override;

private:
	using Fields = std::vector<Field>;
	using FieldsConstIter = Fields::const_iterator;
	using FieldsIter = Fields::iterator;

	Fields fields;

	FieldsConstIter find_field(util::Vector2i) const;

	FieldsConstIter try_find_field(util::Vector2i) const;

	FieldsIter find_field(util::Vector2i);

	FieldsIter try_find_field(util::Vector2i);
};
} // namespace logic