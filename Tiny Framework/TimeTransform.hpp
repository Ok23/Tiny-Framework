#pragma once
#include "Timer.hpp"
#include "EaseFunctions.hpp"

namespace TinyFramework
{
	template<auto Function, typename TimeRep = DefaultTimeType>
	class TimeTransform : public Timer<TimeRep>
	{
	public:
		static const auto Func = (auto(typename TimeRep::rep))Function;
		TimeTransform() : Timer<TimeRep>() {}
		TimeTransform(const TimeRep & duration) : Timer<TimeRep>(duration) {}

		auto update(TimeRep dt) -> decltype(auto)
		{
			Timer<TimeRep>::update(dt);
			return Function(Timer<TimeRep>::getState());
		}

		auto view(typename TimeRep::rep state) -> decltype(Function(typename TimeRep::rep(0)))
		{
			return Function(state);
		}
	};

}