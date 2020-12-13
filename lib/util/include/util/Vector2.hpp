#pragma once

namespace util
{
template <typename T>
struct Vector2
{
	T x, y;

	Vector2<T>& operator+=(const Vector2<T>& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	Vector2<T>& operator-=(const Vector2<T>& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	Vector2<T>& operator*=(T rhs)
	{
		x *= rhs;
		y *= rhs;
		return *this;
	}

	Vector2<T>& operator/=(T rhs)
	{
		x /= rhs;
		y /= rhs;
		return *this;
	}
};

using Vector2i = Vector2<int>;
using Vector2u = Vector2<unsigned>;
using Vector2l = Vector2<long>;
using Vector2d = Vector2<double>;

template <typename T>
Vector2<T> operator+(Vector2<T> lhs, const Vector2<T>& rhs)
{
	lhs += rhs;
	return lhs;
}

template <typename T>
Vector2<T> operator-(Vector2<T> lhs, const Vector2<T>& rhs)
{
	lhs -= rhs;
	return lhs;
}

template <typename T>
Vector2<T> operator*(Vector2<T> lhs, T rhs)
{
	lhs *= rhs;
	return lhs;
}

template <typename T>
Vector2<T> operator/(Vector2<T> lhs, T rhs)
{
	lhs /= rhs;
	return lhs;
}

template <typename T>
bool operator==(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
	return lhs.x == rhs.x and lhs.y == rhs.y;
}

template <typename T>
bool operator!=(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
	return not(lhs == rhs);
}
} // namespace util