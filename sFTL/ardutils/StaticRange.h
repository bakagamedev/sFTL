#pragma once

#include "Utils.h"

//
// Declaration
//

namespace Ardutils
{
	template<typename TValue, TValue Min, TValue Max>
	class StaticRange
	{
	public:
		TValue GetMin(void) const;

		TValue GetMax(void) const;

		TValue Clamp(const TValue & value) const;
	};
}


//
// Definition
//

template<typename TValue, TValue Min, TValue Max>
TValue Ardutils::StaticRange<TValue, Min, Max>::GetMin(void) const
{
	return Min;
}

template<typename TValue, TValue Min, TValue Max>
TValue Ardutils::StaticRange<TValue, Min, Max>::GetMax(void) const
{
	return Max;
}

template<typename TValue, TValue Min, TValue Max>
TValue Ardutils::StaticRange<TValue, Min, Max>::Clamp(const TValue & value) const
{
	return Clamp<TValue, Min, Max>(value);
}
