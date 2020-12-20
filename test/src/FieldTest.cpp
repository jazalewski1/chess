#include <gtest/gtest.h>
#include "logic/Field.hpp"
#include "logic/Piece.hpp"

namespace logic
{
TEST(FieldTest, Succes_When_Field_Created)
{
	Field field;
}

TEST(FieldTest, Succes_When_State_Is_Default_Free)
{
	Field field;
	EXPECT_EQ(nullptr,field.getPiece());
}

TEST(FieldTest, Succes_When_Piece_Is_Ptr_PieceType_After_Set)
{
	Field field;
	field.setPiece(std::shared_ptr<Piece>());
	EXPECT_EQ(std::shared_ptr<Piece>(),field.getPiece());
}
} // namespace logic