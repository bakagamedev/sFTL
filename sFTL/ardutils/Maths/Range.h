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
		TValue min;
		TValue max;

	public:
		Range(const TValue & min, const TValue & max);

		TValue GetMin(void) const;
		TValue GetMax(void) const;

		void SetMin(const TValue & min);
		void SetMax(const TValue & max);

		TValue Clamp(const TValue & value) const;
	};
}


//
// Definition
//

template<typename TValue>
Ardutils::Range<TValue>::Range(const TValue & min, const TValue & max)
	: min(min), max(max)
{
}

template<typename TValue>
TValue Ardutils::Range<TValue>::GetMin(void) const
{
	return this->min;
}

template<typename TValue>
TValue Ardutils::Range<TValue>::GetMax(void) const
{
	return this->max;
}

template<typename TValue>
void Ardutils::Range<TValue>::SetMin(const TValue & min)
{
	DEBUG_ASSERT(min < this->max);

	if (min < this->max)
		this->min = min;
}

template<typename TValue>
void Ardutils::Range<TValue>::SetMax(const TValue & max)
{
	DEBUG_ASSERT(max > this->min);

	if (max > this->min)
		this->max = max;
}

template<typename TValue>
TValue Ardutils::Range<TValue>::Clamp(const TValue & value) const
{
	return Clamp(value, this->min, this->max);
}
