#include <gtest/gtest.h>
#include "logic/Field.hpp"

TEST(CreateEmptyFieldTest, SuccesWhenFieldCreated)
{
	Field field;
}

TEST(FieldTestWithStateFree, SuccesWhenStateIsDefaultFree)
{
	Field field;
	EXPECT_EQ(FieldState::Free,field.getState());
}