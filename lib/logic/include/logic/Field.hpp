#pragma once

enum class FieldState
{
	Free,
	King,
	Queen
};

class Field 
{
public:
	Field();
	FieldState getState() const;
	bool setState(FieldState new_state);
private:
	FieldState state;
};