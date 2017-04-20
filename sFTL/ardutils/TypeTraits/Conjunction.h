#pragma once

#include "IntegralConstant.h"
#include "Conditional.h"

//
// Conjunction
//

namespace Ardutils
{
	// C++17
	template< typename... > struct Conjunction : TrueType {};

	template< typename B0 > struct Conjunction< B0 > : B0 {};

	template< typename B0, typename... Bn >
	struct Conjunction< B0, Bn... >
		: Conditional< bool(B0::Value), Conjunction< Bn... >, B0 >::Type {};
	
	// C++17
	// C++14 is needed for template variables
#if AT_LEAST_CPP_14

	template< typename... T >
	constexpr bool ConjunctionV = Conjunction< T... >::Value;

#endif
}