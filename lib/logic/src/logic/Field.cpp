#include "logic/Field.hpp"

Field::Field() : state(FieldState::Free)
{}

Field::~Field()
{}

FieldState Field::getState() const
{
	return state;
}