#include <gtest/gtest.h>
#include "logic/Field.hpp"
#include "logic/Piece.hpp"
#include "util/Vector2.hpp"

namespace logic
{
TEST(FieldTests, Succes_When_Field_Created)
{
	Field field;
}

TEST(FieldTests, Succes_When_State_Is_Default_Free)
{
	Field field;
	EXPECT_EQ(nullptr,field.get_piece());
}

TEST(FieldTests, Succes_When_Piece_Is_Ptr_PieceType_After_Set)
{
	Field field;
	field.set_piece(std::shared_ptr<Piece>());
	EXPECT_EQ(std::shared_ptr<Piece>(),field.get_piece());
}

TEST(FieldTests, Succes_When_Position_Correctly_Set_By_IntCtor)
{
    Field field(3,5);
    const util::Vector2i pos = {3,5};
    EXPECT_EQ(pos,field.get_position());
}

TEST(FieldTests, Succes_When_Position_Correctly_Set_By_VectorCtor)
{
    const util::Vector2i pos = {2,2};
    Field field(pos);
    EXPECT_EQ(pos,field.get_position());
}

} // namespace logic