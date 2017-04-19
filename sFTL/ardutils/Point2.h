#pragma once

// Required for use of sqrt
#include <math.h>

// Vector2 required for operators
#include "Vector2.h"

//
// Declaration
//

namespace Ardutils
{
	template< typename TValue >
	class Point2
	{
	public:
		TValue X;
		TValue Y;

		Point2(void);
		Point2(const TValue & x, const TValue & y);

		// Member operators because these modify state
		Point2<TValue> & operator +=(const Vector2<TValue> & vector);
		Point2<TValue> & operator -=(const Vector2<TValue> & vector);
	};

	template< typename TValue >
	TValue Distance(const Point2<TValue> & left, const Point2<TValue> & right);

	template< typename TValue >
	bool operator ==(const Point2<TValue> & left, const Point2<TValue> & right);

	template< typename TValue >
	bool operator !=(const Point2<TValue> & left, const Point2<TValue> & right);

	template< typename TValue >
	Point2<TValue> operator +(Point2<TValue> left, const Vector2<TValue> & right);

	template< typename TValue >
	Point2<TValue> operator -(Point2<TValue> left, const Vector2<TValue> & right);

	template< typename TValue >
	Point2<TValue> operator +(const Vector2<TValue> &  left, Point2<TValue> right);

	template< typename TValue >
	Point2<TValue> operator -(const Vector2<TValue> &  left, Point2<TValue> right);
}


//
// Definition
//

namespace Ardutils
{
	template< typename TValue >
	Point2<TValue>::Point2() : X(), Y()
	{
	}

	template< typename TValue >
	Point2<TValue>::Point2(const TValue & x, const TValue & y) : X(x), Y(y)
	{
	}

	template< typename TValue >
	Point2<TValue> & Point2<TValue>::operator+=(const Vector2<TValue> & vector)
	{
		this->X += vector.X;
		this->Y += vector.Y;
		return *this;
	}

	template< typename TValue >
	Point2<TValue> & Point2<TValue>::operator-=(const Vector2<TValue> & vector)
	{
		this->X -= vector.X;
		this->Y -= vector.Y;
		return *this;
	}

	template< typename TValue >
	TValue Distance(const Point2<TValue> & left, const Point2<TValue> & right)
	{
		TValue x = left.X - right.X;
		TValue y = left.Y - right.Y;
		return sqrt((x * x) + (y * y));
	}

	template< typename TValue >
	bool operator ==(const Point2<TValue> & left, const Point2<TValue> & right)
	{
		return(left.X == right.X) && (left.Y == right.Y);
	}

	template< typename TValue >
	bool operator !=(const Point2<TValue> & left, const Point2<TValue> & right)
	{
		return(left.X != right.X) || (left.Y != right.Y);
	}

	template< typename TValue >
	Point2<TValue> operator +(Point2<TValue> left, const Vector2<TValue> & right)
	{
		return left += right;
	}

	template< typename TValue >
	Point2<TValue> operator -(Point2<TValue> left, const Vector2<TValue> & right)
	{
		return left -= right;
	}

	template< typename TValue >
	Point2<TValue> operator +(const Vector2<TValue> & left, Point2<TValue> & right)
	{
		return right += left;
	}

	template< typename TValue >
	Point2<TValue> operator -(const Vector2<TValue> & left, Point2<TValue> & right)
	{
		return right -= left;
	}
}
