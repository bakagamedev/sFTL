#pragma once

// Required for sqrt
#include <math.h>

//
// Declaration
//

namespace Ardutils
{
	template< typename TValue >
	class Vector2
	{
	public:
		TValue X;
		TValue Y;

		Vector2(void);
		Vector2(const TValue & x, const TValue & y);

		float Magnitude(void) const;
		TValue MagnitudeSquared(void) const;

		Vector2<TValue> & operator +=(const Vector2<TValue> & other);
		Vector2<TValue> & operator -=(const Vector2<TValue> & other);
		Vector2<TValue> & operator *=(const TValue & value);
	};

	template< typename TValue >
	bool operator ==(const Ardutils::Vector2<TValue> & left, const Ardutils::Vector2<TValue> & right);

	template< typename TValue >
	bool operator !=(const Ardutils::Vector2<TValue> & left, const Ardutils::Vector2<TValue> & right);

	template< typename TValue >
	Ardutils::Vector2<TValue> operator +(Ardutils::Vector2<TValue> left, const Ardutils::Vector2<TValue> & right);

	template< typename TValue >
	Ardutils::Vector2<TValue> operator -(Ardutils::Vector2<TValue> left, const Ardutils::Vector2<TValue> & right);

	template< typename TValue >
	Ardutils::Vector2<TValue> operator *(Ardutils::Vector2<TValue> left, const TValue right);

	template< typename TValue >
	Ardutils::Vector2<TValue> operator *(const TValue left, Ardutils::Vector2<TValue> right);
}


//
// Definition
//

namespace Ardutils
{
	template< typename TValue >
	Vector2<TValue>::Vector2(void) : X(), Y()
	{
	}

	template< typename TValue >
	Vector2<TValue>::Vector2(const TValue & x, const TValue & y) : X(x), Y(y)
	{
	}

	template< typename TValue >
	float Vector2<TValue>::Magnitude(void) const
	{
		return float(sqrt(this->MagnitudeSquared()));
	}

	template< typename TValue >
	TValue Vector2<TValue>::MagnitudeSquared(void) const
	{
		return (this->X * this->X) + (this->Y + this->Y);
	}

	template< typename TValue >
	Vector2<TValue> & Vector2<TValue>::operator+=(const Vector2<TValue> & other)
	{
		this->X += other.X;
		this->Y += other.Y;
		return *this;
	}

	template< typename TValue >
	Vector2<TValue> & Vector2<TValue>::operator-=(const Vector2<TValue> & other)
	{
		this->X -= other.X;
		this->Y -= other.Y;
		return *this;
	}

	template< typename TValue >
	Vector2<TValue> & Vector2<TValue>::operator*=(const TValue & value)
	{
		this->X *= value;
		this->Y *= value;
		return *this;
	}

	template< typename TValue >
	bool operator==(const Vector2<TValue> & left, const Vector2<TValue> & right)
	{
		return (left.X == right.X) && (left.Y == right.Y);
	}

	template< typename TValue >
	bool operator!=(const Vector2<TValue> & left, const Vector2<TValue> & right)
	{
		return (left.X != right.X) || (left.Y != right.Y);
	}

	template< typename TValue >
	Vector2<TValue> operator+(Vector2<TValue> left, const Vector2<TValue> &right)
	{
		return left += right;
	}

	template< typename TValue >
	Vector2<TValue> operator-(Vector2<TValue> left, const Vector2<TValue> &right)
	{
		return left -= right;
	}

	template< typename TValue >
	Vector2<TValue> operator*(Vector2<TValue> left, const TValue right)
	{
		return left *= right;
	}

	template< typename TValue >
	Vector2<TValue> operator *(const TValue left, Vector2<TValue> right)
	{
		return right *= left;
	}
}
