#pragma once

#include "Utils.h"

//
// Declaration
//

namespace Ardutils
{
	template<typename TValue, TValue Min, TValue Max>
	class StaticClampedValue
	{
	private:
		TValue value;

	public:
		StaticClampedValue(const TValue & value);

		TValue GetValue(void) const;

		TValue GetMin(void) const;

		TValue GetMax(void) const;

		operator TValue(void) const;

		StaticClampedValue<TValue, Min, Max> & operator =(const TValue & value);

		StaticClampedValue<TValue, Min, Max> & operator +=(const TValue & value);

		StaticClampedValue<TValue, Min, Max> & operator -=(const TValue & value);

		ClampedValue<TValue> & operator ++(void);

		ClampedValue<TValue> & operator --(void);
	};
}


//
// Definition
//

template<typename TValue, TValue Min, TValue Max>
Ardutils::StaticClampedValue<TValue, Min, Max>::StaticClampedValue(const TValue & value)
{
	this->value = Clamp<TValue, Min, Max>(value);
}

template<typename TValue, TValue Min, TValue Max>
TValue Ardutils::StaticClampedValue<TValue, Min, Max>::GetValue(void) const
{
	return this->value;
}

template<typename TValue, TValue Min, TValue Max>
TValue Ardutils::StaticClampedValue<TValue, Min, Max>::GetMin(void) const
{
	return Min;
}

template<typename TValue, TValue Min, TValue Max>
TValue Ardutils::StaticClampedValue<TValue, Min, Max>::GetMax(void) const
{
	return Max;
}

template<typename TValue, TValue Min, TValue Max>
Ardutils::StaticClampedValue<TValue, Min, Max>::operator TValue(void) const
{
	return this->value;
}

template<typename TValue, TValue Min, TValue Max>
Ardutils::StaticClampedValue<TValue, Min, Max> & Ardutils::StaticClampedValue<TValue, Min, Max>::operator =(const TValue & value)
{
	this->value = Clamp<TValue, Min, Max>(value);
	return *this;
}

template<typename TValue, TValue Min, TValue Max>
Ardutils::StaticClampedValue<TValue, Min, Max> & Ardutils::StaticClampedValue<TValue, Min, Max>::operator +=(const TValue & value)
{
	this->value = Clamp<TValue, Min, Max>(this->value + value);
	return *this;
}

template<typename TValue, TValue Min, TValue Max>
Ardutils::StaticClampedValue<TValue, Min, Max> & Ardutils::StaticClampedValue<TValue, Min, Max>::operator -=(const TValue & value)
{
	this->value = Clamp<TValue, Min, Max>(this->value - value);
	return *this;
}

template<typename TValue, TValue Min, TValue Max>
Ardutils::StaticClampedValue<TValue> & Ardutils::StaticClampedValue<TValue, Min, Max>::operator ++(void)
{
	this->value = Min<TValue, Max>(this->value + 1);
	return *this;
}

template<typename TValue, TValue Min, TValue Max>
Ardutils::StaticClampedValue<TValue> & Ardutils::StaticClampedValue<TValue, Min, Max>::operator --(void)
{
	this->value = Max<TValue, Min>(this->value - 1);
	return *this;
}
