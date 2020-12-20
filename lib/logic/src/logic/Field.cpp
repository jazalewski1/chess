#include "logic/Field.hpp"

Field::Field() : state(FieldState::Free)
{}

FieldState Field::getState() const
{
	return state;
}

bool Field::setState(FieldState new_state)
{
	state=new_state;
	if(state==new_state)
	{
		return true;
	}
	else
	{
		return false;
	}
}