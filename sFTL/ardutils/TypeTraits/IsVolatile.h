#pragma once

#include "IntegralConstant.h"

#include "../Details/VersioningStart.h"

//
// IsVolatile
//

namespace Ardutils
{
	// C++11
	template< typename T >
	struct IsVolatile : FalseType {};

	template< typename T >
	struct IsVolatile< volatile T > : TrueType {};

	// C++17
	// C++14 is needed for template variables
#if AT_LEAST_CPP_14

	template< typename T >
	constexpr bool IsVolatileV = IsVolatile< T >::Value;

#endif
}

#include "../Details/VersioningEnd.h"