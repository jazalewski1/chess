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
	~Field();
	FieldState getState() const;
private:
	FieldState state;
};