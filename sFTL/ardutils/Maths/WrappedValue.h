#pragma once

//
// Declaration
//

namespace Ardutils
{
	template< typename TValue >
	class WrappedValue
	{
	private:
		TValue value;
		const TValue min;
		const TValue max;

	public:
		WrappedValue(const TValue & min, const TValue & max);

		TValue GetValue(void) const;
		TValue GetMin(void) const;
		TValue GetMax(void) const;

		operator TValue(void) const;

		WrappedValue< TValue > & operator ++(void);
		WrappedValue< TValue >  & operator --(void);
	};
}


//
// Definition
//

template< typename TValue >
Ardutils::WrappedValue< TValue >::WrappedValue(const TValue & min, const TValue & max)
	: value(min), min(min), max(max)
{
}

template< typename TValue >
TValue Ardutils::WrappedValue< TValue >::GetValue(void) const
{
	return this->value;
}

template< typename TValue >
TValue Ardutils::WrappedValue< TValue >::GetMin(void) const
{
	return this->min;
}

template< typename TValue >
TValue Ardutils::WrappedValue< TValue >::GetMax(void) const
{
	return this->max;
}

template< typename TValue >
Ardutils::WrappedValue< TValue >::operator TValue(void) const
{
	return this->value;
}

template< typename TValue >
Ardutils::WrappedValue< TValue > & Ardutils::WrappedValue< TValue >::operator ++(void)
{
	if (this->value == this->max)
		this->value = this->min;
	else
		++this->value;
	return *this;
}

template< typename TValue >
Ardutils::WrappedValue< TValue >  & Ardutils::WrappedValue< TValue >::operator --(void)
{
	if (this->value == this->min)
		this->value = this->max;
	else
		--this->value;
	return *this;
}
