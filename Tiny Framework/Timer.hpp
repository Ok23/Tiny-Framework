#pragma once
#include <chrono>



namespace TinyFramework
{
	using DefaultTimeType = std::chrono::duration<float>;

	template<typename TimeT = DefaultTimeType>
	class Timer
	{
	public:
		using Time = TimeT;
		using TimeRep = typename TimeT::rep;
		Timer() noexcept;
		Timer(Time duration) noexcept;
		void setDuration(Time duration) noexcept;
		Time getDuration() const noexcept;
		Time getElapsedTime() const noexcept;
		TimeRep getState() const noexcept;
		bool exceed() const noexcept;
		void reset() noexcept;
		void reset(Time newDuration) noexcept;
		void stop() noexcept;
		void update(Time dt) noexcept;
	private:
		Time duration;
		Time elapsed;
	};

	template<typename TimeT>
	inline Timer<TimeT>::Timer() noexcept : duration(0), elapsed(0)
	{
	}

	template<typename TimeT>
	inline Timer<TimeT>::Timer(Time duration) noexcept : duration(duration), elapsed(0)
	{
	}

	template<typename TimeT>
	inline void Timer<TimeT>::setDuration(Time duration) noexcept
	{
		this->duration = duration;
	}

	template<typename TimeT>
	inline TimeT Timer<TimeT>::getDuration() const noexcept
	{
		return duration;
	}

	template<typename TimeT>
	inline TimeT Timer<TimeT>::getElapsedTime() const noexcept
	{
		return elapsed;
	}

	template<typename TimeT>
	inline typename Timer<TimeT>::TimeRep Timer<TimeT>::getState() const noexcept
	{
		return (elapsed / duration);
	}

	template<typename TimeT>
	inline bool Timer<TimeT>::exceed() const noexcept
	{
		return elapsed >= duration;
	}

	template<typename TimeT>
	inline void Timer<TimeT>::reset() noexcept
	{
		elapsed = Time::zero();
	}

	template<typename TimeT>
	inline void Timer<TimeT>::reset(Time newDuration) noexcept
	{
		elapsed = Time::zero();
		duration = newDuration;
	}

	template<typename TimeT>
	inline void Timer<TimeT>::stop() noexcept
	{
		elapsed = duration;
	}

	template<typename TimeT>
	inline void Timer<TimeT>::update(Time dt) noexcept
	{
		elapsed += dt;
		elapsed = elapsed >= duration ? duration : elapsed;
	}
}