#pragma once

#include "IntegralConstant.h"
#include "Conditional.h"

//
// Disjunction
//

namespace Ardutils
{
	// C++17
	template< typename... > struct Disjunction : FalseType {};

	template< typename B0 > struct Disjunction< B0 > : B0 {};

	template< typename B0, typename... Bn >
	struct Disjunction< B0, Bn... >
		: Conditional< bool(B0::Value), B0, Disjunction< Bn... > >::Type {};

	// C++17
	// C++14 is needed for template variables
#if AT_LEAST_CPP_14

	template< typename... T >
	constexpr bool DisjunctionV = Disjunction< T... >::Value;

#endif
}