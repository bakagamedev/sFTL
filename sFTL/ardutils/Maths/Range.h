#pragma once

#include "..\Debug.h"
#include "..\Utils.h"

//
// Declaration
//

namespace Ardutils
{
	template<typename TValue>
	class Range
	{
	private:
		TValue minValue;
		TValue maxValue;

	public:
		Range(const TValue & minValue, const TValue & maxValue);

		TValue GetMin(void) const;
		TValue GetMax(void) const;

		void SetMin(const TValue & minValue);
		void SetMax(const TValue & maxValue);

		TValue Clamp(const TValue & value) const;
	};
}


//
// Definition
//

template<typename TValue>
Ardutils::Range<TValue>::Range(const TValue & minValue, const TValue & maxValue)
	: minValue(minValue), maxValue(maxValue)
{
}

template<typename TValue>
TValue Ardutils::Range<TValue>::GetMin(void) const
{
	return this->minValue;
}

template<typename TValue>
TValue Ardutils::Range<TValue>::GetMax(void) const
{
	return this->maxValue;
}

template<typename TValue>
void Ardutils::Range<TValue>::SetMin(const TValue & minValue)
{
	DEBUG_ASSERT(minValue < this->maxValue);

	if (minValue < this->maxValue)
		this->minValue = minValue;
}

template<typename TValue>
void Ardutils::Range<TValue>::SetMax(const TValue & maxValue)
{
	DEBUG_ASSERT(maxValue > this->minValue);

	if (maxValue > this->minValue)
		this->maxValue = maxValue;
}

template<typename TValue>
TValue Ardutils::Range<TValue>::Clamp(const TValue & value) const
{
	return Clamp(value, this->minValue, this->maxValue);
}
