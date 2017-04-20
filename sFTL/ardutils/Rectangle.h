#pragma once

#include "Utils.h"

#include "Point2.h"
#include "Vector2.h"

//
// Declaration
//

namespace Ardutils
{
	template< typename TPosition, typename TSize = TPosition >
	class Rectangle
	{
	public:
		TPosition X;
		TPosition Y;
		TSize Width;
		TSize Height;

	public:
		Rectangle(void);

		Rectangle(const TPosition & x, const TPosition & y, const TSize & width, const TSize & height);
		
		TPosition GetLeft(void) const;
		TPosition GetRight(void) const;
		TPosition GetTop(void) const;
		TPosition GetBottom(void) const;

		Point2<TPosition> GetCentre(void) const;
		Point2<TPosition> GetLocation(void) const;

		bool IsEmpty(void) const;
		TSize GetArea(void) const;
		TSize GetPerimeter(void) const;

		void Offset(const Point2<TPosition> & point);
		void Offset(const TPosition & x, const TPosition & y);

		void ScaleByUnit(const Vector2<TPosition> & vector);
		void ScaleByUnit(const TPosition & x, const TPosition & y);

		template< typename TValue >
		bool Contains(const Point2<TValue> & point) const;

		template< typename TValue >
		bool Contains(const TValue & x, const TValue & y) const;

		bool Contains(const Rectangle<TPosition, TSize> & other) const;

		bool Intersects(const Rectangle<TPosition, TSize> & point) const;
	};
	
	template< typename TPosition, typename TSize = TPosition >
	Rectangle<TPosition, TSize> Union(const Rectangle<TPosition, TSize> & left, const Rectangle<TPosition, TSize> & right);
	
	template< typename TPosition, typename TSize = TPosition >
	Rectangle<TPosition, TSize> Intersection(const Rectangle<TPosition, TSize> & left, const Rectangle<TPosition, TSize> & right);

	template< typename TPosition, typename TSize = TPosition >
	bool operator ==(const Rectangle<TPosition, TSize> & left, const Rectangle<TPosition, TSize> & right);

	template< typename TPosition, typename TSize = TPosition >
	bool operator !=(const Rectangle<TPosition, TSize> & left, const Rectangle<TPosition, TSize> & right);
}


//
// Definition
//

template< typename TPosition, typename TSize >
Ardutils::Rectangle< TPosition, TSize >::Rectangle(void) = default;

template< typename TPosition, typename TSize >
Ardutils::Rectangle< TPosition, TSize >::Rectangle(const TPosition & x, const TPosition & y, const TSize & width, const TSize & height) :
	X(x), Y(y), Width(width), Height(height)
{
}

template< typename TPosition, typename TSize >
TPosition Ardutils::Rectangle< TPosition, TSize >::GetLeft(void) const
{
	return this->X;
}

template< typename TPosition, typename TSize >
TPosition Ardutils::Rectangle< TPosition, TSize >::GetRight(void) const
{
	return this->X + this->Width;
}

template< typename TPosition, typename TSize >
TPosition Ardutils::Rectangle< TPosition, TSize >::GetTop(void) const
{
	return this->Y;
}

template< typename TPosition, typename TSize >
TPosition Ardutils::Rectangle< TPosition, TSize >::GetBottom(void) const
{
	return this->Y + this->Height;
}

template< typename TPosition, typename TSize >
Ardutils::Point2<TPosition> Ardutils::Rectangle< TPosition, TSize >::GetCentre(void) const
{
	return Point2<TPosition>((this->X + this->Width) / 2, (this->Y + this->Height) / 2);
}

template< typename TPosition, typename TSize >
Ardutils::Point2<TPosition> Ardutils::Rectangle< TPosition, TSize >::GetLocation(void) const
{
	return Point2<TPosition>(this->X, this->Y);
}

template< typename TPosition, typename TSize >
bool Ardutils::Rectangle< TPosition, TSize >::IsEmpty(void) const
{
	return  (this->X == 0)
		&& (this->Y == 0)
		&& (this->Width == 0)
		&& (this->Height == 0);
}

template< typename TPosition, typename TSize >
TSize Ardutils::Rectangle< TPosition, TSize >::GetArea(void) const
{
	return this->Width * this->Height;
}

template< typename TPosition, typename TSize >
TSize Ardutils::Rectangle< TPosition, TSize >::GetPerimeter(void) const
{
	return (this->Width + this->Height) * 2;
}

template< typename TPosition, typename TSize >
void Ardutils::Rectangle< TPosition, TSize >::Offset(const Point2<TPosition> & point)
{
	this->X += point.X;
	this->Y += point.Y;
}

template< typename TPosition, typename TSize >
void Ardutils::Rectangle< TPosition, TSize >::Offset(const TPosition & x, const TPosition & y)
{
	this->X += x;
	this->Y += y;
}

template< typename TPosition, typename TSize >
void Ardutils::Rectangle< TPosition, TSize >::ScaleByUnit(const Vector2<TPosition> & vector)
{
	this->X -= vector.X;
	this->Y -= vector.Y;
	this->Width += vector.X * 2;
	this->Height += vector.Y * 2;
}

template< typename TPosition, typename TSize >
void Ardutils::Rectangle< TPosition, TSize >::ScaleByUnit(const TPosition & x, const TPosition & y)
{
	this->X -= x;
	this->Y -= y;
	this->Width += x * 2;
	this->Height += y * 2;
}

template< typename TPosition, typename TSize >
template< typename TValue >
bool Ardutils::Rectangle< TPosition, TSize >::Contains(const Point2<TValue> & point) const
{
	return Ardutils::InRange(point.X, this->GetLeft(), this->GetRight())
		&& Ardutils::InRange(point.Y, this->GetTop(), this->GetBottom());
}

template< typename TPosition, typename TSize >
template< typename TValue >
bool Ardutils::Rectangle< TPosition, TSize >::Contains(const TValue & x, const TValue & y) const
{
	return Ardutils::InRange(x, this->GetLeft(), this->GetRight())
		&& Ardutils::InRange(y, this->GetTop(), this->GetBottom());
}

template< typename TPosition, typename TSize >
bool Ardutils::Rectangle< TPosition, TSize >::Contains(const Rectangle<TPosition, TSize> & other) const
{
	return (other.GetTop() >= this->GetTop())
		&& (other.GetLeft() >= this->GetLeft())
		&& (other.GetRight() <= this->GetRight())
		&& (other.GetBottom() <= this->GetBottom());
}

template< typename TPosition, typename TSize >
bool Ardutils::Rectangle< TPosition, TSize >::Intersects(const Rectangle<TPosition, TSize> & other) const
{
	return !
		(
			(other.GetTop() > this->GetBottom())
			|| (other.GetLeft() > this->GetRight())
			|| (other.GetRight() < this->GetLeft())
			|| (other.GetBottom() < this->GetTop())
		);
}

template< typename TPosition, typename TSize >
Ardutils::Rectangle<TPosition, TSize> Ardutils::Union(const Rectangle<TPosition, TSize> & left, const Rectangle<TPosition, TSize> & right)
{
	auto x = Ardutils::Min(left.GetLeft(), right.GetLeft());
	auto y = Ardutils::Min(left.GetTop(), right.GetTop());
	auto w = Ardutils::Max(left.GetRight(), right.GetRight()) - x;
	auto h = Ardutils::Max(left.GetBottom(), right.GetBottom()) - y;
	return Rectangle<TPosition, TSize>(x, y, w, h);
}

template< typename TPosition, typename TSize >
Ardutils::Rectangle<TPosition, TSize> Ardutils::Intersection(const Rectangle<TPosition, TSize> & left, const Rectangle<TPosition, TSize> & right)
{
	auto x = Ardutils::Max(left.GetLeft(), right.GetLeft());
	auto y = Ardutils::Max(left.GetTop(), right.GetTop());
	auto w = Ardutils::Min(left.GetRight(), right.GetRight()) - x;
	auto h = Ardutils::Min(left.GetBottom(), right.GetBottom()) - y;
	return Rectangle<TPosition, TSize>(x, y, w, h);
}

template< typename TPosition, typename TSize >
bool Ardutils::operator ==(const Rectangle<TPosition, TSize> & left, const Rectangle<TPosition, TSize> & right)
{
	return (left.X == right.X)
		&& (left.Y == right.Y)
		&& (left.Width == right.Width)
		&& (left.Height == right.Height);
}

template< typename TPosition, typename TSize >
bool Ardutils::operator !=(const Rectangle<TPosition, TSize> & left, const Rectangle<TPosition, TSize> & right)
{
	return (left.X != right.X)
		|| (left.Y != right.Y)
		|| (left.Width != right.Width)
		|| (left.Height != right.Height);
}
