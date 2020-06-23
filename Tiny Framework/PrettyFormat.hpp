#pragma once
#include <sstream>
#include <ostream>
#include <chrono>
#include <type_traits>

namespace std
{
	template<typename TimeRep, typename TimeRatio>
	ostream & operator << (ostream & os, chrono::duration<TimeRep, TimeRatio> time)
	{
		//template<typename To, typename Rep, typename Period>

		using chrono::duration_cast;

		std::ostringstream localStr;
		const char * suffix = "ns";
		auto absTime = time;
		if constexpr (is_signed_v<TimeRep>)
			absTime = absTime.count() < TimeRep(0) ? -absTime : absTime;
		TimeRep formatTime = time.count();

		using ns = chrono::duration<TimeRep, std::nano>;
		using us = chrono::duration<TimeRep, std::micro>;
		using ms = chrono::duration<TimeRep, std::milli>;
		using sec = chrono::duration<TimeRep>;
		using min = chrono::duration<TimeRep, std::ratio<60>>;
		using hour = chrono::duration<TimeRep, std::ratio<3600>>;
		using day = chrono::duration<TimeRep, std::ratio<86400>>;

		auto nanoseconds = duration_cast<ns>(absTime);
		auto microsecs = duration_cast<us>(absTime);
		auto millisecs = duration_cast<ms>(absTime);
		auto seconds = duration_cast<sec>(absTime);
		auto minutes = duration_cast<min>(absTime);
		auto hours = duration_cast<hour>(absTime);
		auto days = duration_cast<day>(absTime);

		localStr.flags(os.flags());
		localStr.imbue(os.getloc());
		localStr.precision(os.precision());

		if (time.count() == TimeRep(0))
		{
			suffix = "ns";
			formatTime = TimeRep(0);
		}
		else
		{
			if (microsecs.count() >= TimeRep(1))
			{
				suffix = "us";
				formatTime = microsecs.count();
			}
			if (millisecs.count() >= TimeRep(1))
			{
				suffix = "ms";
				formatTime = millisecs.count();
			}
			if (seconds.count() >= TimeRep(1))
			{
				suffix = "sec";
				formatTime = seconds.count();
			}
			if (minutes.count() >= TimeRep(1))
			{
				suffix = "min";
				formatTime = minutes.count();
			}
			if (hours.count() >= TimeRep(1))
			{
				suffix = "hour";
				formatTime = hours.count();
			}
			if (days.count() >= TimeRep(1))
			{
				suffix = "day";
				formatTime = days.count();
			}
		}

		

		if constexpr (is_signed_v<TimeRep>)
		{
			if (time.count() < TimeRep(0))
				formatTime = -formatTime;
		}
		localStr << formatTime;
		localStr << suffix;
		os << localStr.str();

		return os;
	}
}