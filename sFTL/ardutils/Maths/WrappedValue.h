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
		const TValue minValue;
		const TValue maxValue;

	public:
		WrappedValue(const TValue & minValue, const TValue & maxValue);

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
Ardutils::WrappedValue< TValue >::WrappedValue(const TValue & minValue, const TValue & maxValue)
	: value(minValue), minValue(minValue), maxValue(maxValue)
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
	return this->minValue;
}

template< typename TValue >
TValue Ardutils::WrappedValue< TValue >::GetMax(void) const
{
	return this->maxValue;
}

template< typename TValue >
Ardutils::WrappedValue< TValue >::operator TValue(void) const
{
	return this->value;
}

template< typename TValue >
Ardutils::WrappedValue< TValue > & Ardutils::WrappedValue< TValue >::operator ++(void)
{
	if (this->value == this->maxValue)
		this->value = this->minValue;
	else
		++this->value;
	return *this;
}

template< typename TValue >
Ardutils::WrappedValue< TValue >  & Ardutils::WrappedValue< TValue >::operator --(void)
{
	if (this->value == this->minValue)
		this->value = this->maxValue;
	else
		--this->value;
	return *this;
}
