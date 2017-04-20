#pragma once

namespace Ardutils
{
	template< typename T >
	constexpr const T & Min(const T & left, const T & right) noexcept
	{
		return (left < right) ? left : right;
	}

	template< typename T, T Other >
	constexpr T Min(const T & value) noexcept
	{
		return (value < Other) ? value : Other;
	}

	template< typename T, T Left, T Right >
	constexpr T Min(void) noexcept
	{
		return (Left < Right) ? Left : Right;
	}

	template< typename T >
	constexpr const T & Max(const T & left, const T & right) noexcept
	{
		return (left > right) ? left : right;
	}

	template< typename T, T Other >
	constexpr T Max(const T & value) noexcept
	{
		return (value > Other) ? value : Other;
	}

	template< typename T, T Left, T Right >
	constexpr T Max(void) noexcept
	{
		return (Left > Right) ? Left : Right;
	}

	template< typename T >
	constexpr T Clamp(const T & value, const T & min, const T & max) noexcept
	{
		return (value < min) ? min : (value > max) ? max : value;
	}

	template< typename T, T Min, T Max >
	constexpr T Clamp(const T & value) noexcept
	{
		return (value < Min) ? Min : (value > Max) ? Max : value;
	}

	template< typename T, T Value, T Min, T Max >
	constexpr T Clamp(void) noexcept
	{
		return (Value < Min) ? Min : (Value > Max) ? Max : Value;
	}

	template< typename T >
	constexpr T Sign(const T & value) noexcept
	{
		return (value < 0) ? -1 : (value > 0) ? 1 : 0;
	}

	template< typename T, T Value >
	constexpr T Sign(void) noexcept
	{
		return (Value < 0) ? -1 : (Value > 0) ? 1 : 0;
	}

	template< typename T, typename U = T>
	constexpr bool InRange(const T & value, const U & min, const U & max) noexcept
	{
		return (value >= min) && (value <= max);
	}

	template< typename T, T Min, T Max >
	constexpr bool InRange(const T & value) noexcept
	{
		return (value >= Min) && (value <= Max);
	}

	template< typename T, T Value, T Min, T Max >
	constexpr bool InRange(void) noexcept
	{
		return (Value >= Min) && (Value <= Max);
	}
}


