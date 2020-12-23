#pragma once

#include <string>

namespace util
{
class Exception
{
public:
	virtual ~Exception()
	{
	}

	virtual std::string what() const = 0;
};

class OutOfBoundsException : public Exception
{
public:
	OutOfBoundsException(std::string message) : message{message}
	{
	}

	std::string what() const override
	{
		return message;
	}
private:
	std::string message;
};
} // namespace util