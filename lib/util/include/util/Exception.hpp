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
} // namespace util