#pragma once
#include <sstream>
#include <ostream>
#include <chrono>

namespace std
{
	template<typename TimeRep, typename TimeRatio>
	ostream & operator << (ostream & os, chrono::duration<TimeRep, TimeRatio> time)
	{
		//template<typename To, typename Rep, typename Period>

		using std::chrono::duration_cast;

		std::ostringstream localStr;
		const char * suffix = nullptr;
		auto formatTime = time.count();
		const auto absTime = std::chrono::abs(time);

		auto nanoseconds = duration_cast<chrono::nanoseconds>(absTime);
		auto microsecs = duration_cast<chrono::microseconds>(absTime);
		auto millisecs = duration_cast<chrono::milliseconds>(absTime);
		auto seconds = duration_cast<chrono::seconds>(absTime);
		auto minutes = duration_cast<chrono::minutes>(absTime);
		auto hours = duration_cast<chrono::hours>(absTime);

		localStr.flags(os.flags());
		localStr.imbue(os.getloc());
		localStr.precision(os.precision());

		if (nanoseconds.count() == 0.f)
		{
			suffix = "ns";
			nanoseconds = time;
			formatTime = nanoseconds.count();
		}
		else if (nanoseconds.count() >= 1.0 and microsecs.count() < 1.0)
		{
			suffix = "ns";
			nanoseconds = time;
			formatTime = nanoseconds.count();
		}
		else if (microsecs.count() >= 1.0 and millisecs.count() < 1.0)
		{
			suffix = "us";
			microsecs = time;
			formatTime = microsecs.count();
		}
		else if (millisecs.count() >= 1.0 and seconds.count() < 1.0)
		{
			suffix = "ms";
			millisecs = time;
			formatTime = millisecs.count();
		}
		else if (seconds.count() >= 1.0 and minutes.count() < 1.0)
		{
			suffix = "sec";
			seconds = time;
			formatTime = seconds.count();

		}
		else if (minutes.count() >= 1.0 and hours.count() < 1.0)
		{
			suffix = "min";
			minutes = time;
			formatTime = minutes.count();
		}
		else
		{
			suffix = "hour";
			hours = time;
			formatTime = hours.count();
		}
		localStr << formatTime;
		localStr << suffix;
		os << localStr.str();

		return os;
	}
}