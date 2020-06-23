#pragma once
#include <type_traits>
#include <cstdint>


namespace TinyFramework
{
	// Apply bytes offset to given memory
	template<typename MemoryT, typename IntegerT>
	inline MemoryT applyBytesOffset(MemoryT memory, IntegerT bytesOffet) noexcept
	{
		static_assert(std::is_pointer_v<MemoryT>, "TinyFramework::applyBytesOffset: MemoryT must be pointer");
		static_assert(std::is_integral_v<IntegerT>, "TinyFramework::applyBytesOffset: IntegerT must be integer type");
		return MemoryT((std::uint8_t *)memory + bytesOffet);
	}

	// Return true if value equal at least one argument
	template<typename ValueT, typename ... ArgsT>
	constexpr inline bool equalAny(ValueT && value, ArgsT &&... args)
	{
		static_assert(sizeof...(args) > 0, "TinyFramework::equalAny: Needs at least one argument");
		return (... or (value == args));
	}

	// Return true if value equal all arguments
	template<typename ValueT, typename ... ArgsT>
	constexpr inline bool equalAll(ValueT && value, ArgsT &&... args)
	{
		static_assert(sizeof...(args) > 0, "TinyFramework::equalAll: Needs at least one argument");
		return (... and (value == args));
	}

	// Linear interpolation
	template<typename ValueT, typename FloatT>
	constexpr inline ValueT lerp(ValueT from, ValueT to, FloatT percent)
	{
		static_assert(std::is_floating_point_v<FloatT>, "TinyFramework::lerp: FloatT must be float type");
		return from + percent * (to - from);
	}

	// Not allow for non unsigned integer argument
	template<typename T> inline constexpr float floatFromBits(const T) noexcept = delete;

	// Convert 32 bit unsigned integer to float in range [0, 1)
	inline constexpr float floatFromBits(const std::uint32_t integer) noexcept
	{
		return (integer >> 8) * 0x1.0p-24f;
	}

	// Convert 64 bit unsigned integer to float in range [0, 1)
	inline constexpr float floatFromBits(const std::uint64_t integer) noexcept
	{
		return (integer >> 11) * 0x1.0p-53f;
	}

	// Not allow for non unsigned integer argument
	template<typename T> inline constexpr double doubleFromBits(const T) noexcept = delete;

	// Convert 64 bit unsigned integer to duble in range [0, 1)
	inline constexpr double doubleFromBits(const std::uint64_t integer) noexcept
	{
		return (integer >> 11) * 0x1.0p-53;
	}

	// Convert 32 bit unsigned integer to duble in range [0, 1)
	inline constexpr double doubleFromBits(const std::uint32_t integer) noexcept
	{
		return (integer >> 8) * 0x1.0p-24;
	}
}