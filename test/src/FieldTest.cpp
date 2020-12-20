#include <gtest/gtest.h>
#include "logic/Field.hpp"

TEST(FieldTest, Succes_When_Field_Created)
{
	Field field;
}

TEST(FieldTest, Succes_When_State_Is_Default_Free)
{
	Field field;
	EXPECT_EQ(FieldState::Free,field.getState());
}

TEST(FieldTest, Succes_When_State_Is_Queen_After_Set)
{
	Field field;
	EXPECT_TRUE(field.setState(FieldState::Queen));
	EXPECT_EQ(FieldState::Queen,field.getState());
}