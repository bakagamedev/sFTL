#pragma once

#include "..\Utils.h"

//
// Declaration
//

namespace Ardutils
{
	template<typename TValue>
	class ClampedValue
	{
	private:
		TValue value;
		TValue min;
		TValue max;

	public:
		ClampedValue(const TValue & value, const TValue & min, const TValue & max);

		TValue GetValue(void) const;
		TValue GetMin(void) const;
		TValue GetMax(void) const;

		void SetValue(const TValue & value);
		void SetMin(const TValue & value);
		void SetMax(const TValue & value);

		operator TValue(void) const;

		ClampedValue<TValue> & operator =(const TValue & value);
		
		ClampedValue<TValue> & operator +=(const TValue & value);
		ClampedValue<TValue> & operator -=(const TValue & value);

		ClampedValue<TValue> & operator ++(void);
		ClampedValue<TValue> & operator --(void);
	};
}


//
// Definition
//

template<typename TValue>
Ardutils::ClampedValue<TValue>::ClampedValue(const TValue & value, const TValue & min, const TValue & max)
	: min(min), max(max)
{
	this->value = Clamp(value, min, max);
}

template<typename TValue>
TValue Ardutils::ClampedValue<TValue>::GetValue(void) const
{
	return this->value;
}

template<typename TValue>
TValue Ardutils::ClampedValue<TValue>::GetMin(void) const
{
	return this->min;
}

template<typename TValue>
TValue Ardutils::ClampedValue<TValue>::GetMax(void) const
{
	return this->max;
}

template<typename TValue>
void Ardutils::ClampedValue<TValue>::SetValue(const TValue & value)
{
	this->value = Clamp(this->value, this->min, this->max);
}

template<typename TValue>
void Ardutils::ClampedValue<TValue>::SetMin(const TValue & value)
{
	DEBUG_ASSERT(value <= this->max);

	this->min = value;
	this->value = Max(this->value, this->min);
}

template<typename TValue>
void Ardutils::ClampedValue<TValue>::SetMax(const TValue & value)
{
	DEBUG_ASSERT(value >= this->min);

	this->max = value;
	this->value = Min(this->value, this->max);
}

template<typename TValue>
Ardutils::ClampedValue<TValue>::operator TValue(void) const
{
	return this->value;
}

template<typename TValue>
Ardutils::ClampedValue<TValue> & Ardutils::ClampedValue<TValue>::operator =(const TValue & value)
{
	this->value = Clamp(this->value, this->min, this->max);
	return *this;
}

template<typename TValue>
Ardutils::ClampedValue<TValue> & Ardutils::ClampedValue<TValue>::operator +=(const TValue & value)
{
	// Explicit type required on Clamp because of integer promotion rules
	this->value = Clamp<TValue>(this->value + value, this->min, this->max);
	return *this;
}

template<typename TValue>
Ardutils::ClampedValue<TValue> & Ardutils::ClampedValue<TValue>::operator -=(const TValue & value)
{
	// Explicit type required on Clamp because of integer promotion rules
	this->value = Clamp<TValue>(this->value - value, this->min, this->max);
	return *this;
}

template<typename TValue>
Ardutils::ClampedValue<TValue> & Ardutils::ClampedValue<TValue>::operator ++(void)
{
	// Explicit type required on Min because of integer promotion rules
	this->value = Min<TValue>(this->value + 1, this->max);
	return *this;
}

template<typename TValue>
Ardutils::ClampedValue<TValue> & Ardutils::ClampedValue<TValue>::operator --(void)
{
	// Explicit type required on Max because of integer promotion rules
	this->value = Max<TValue>(this->value - 1, this->min);
	return *this;
}
