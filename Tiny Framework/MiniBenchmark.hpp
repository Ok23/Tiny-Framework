#pragma once
#include <string_view>
#include <algorithm>
#include <vector>
#include <chrono>
#include <ostream>
#include "PrettyFormat.hpp"

namespace TinyFramework::Minibench
{
	class Result;
	using Time = std::chrono::duration<double, std::nano>;

	template<auto Func, size_t IterCount = 10000, size_t TimeCheckPerIter = 10>
	Result run(std::string_view name)
	{
		static_assert(IterCount % TimeCheckPerIter == 0);

		std::vector<Time> timeResults;
		timeResults.reserve(IterCount / TimeCheckPerIter);

		auto startTime = std::chrono::steady_clock::now();
		for (size_t iter = 0; iter < IterCount / TimeCheckPerIter; ++iter)
		{
			auto startIterTime = std::chrono::steady_clock::now();
			for (size_t i = 0; i < TimeCheckPerIter; ++i)
			{
				Func();
			}
			auto endIterTime = std::chrono::steady_clock::now();
			timeResults.emplace_back((endIterTime - startIterTime));
		}
		auto endTime = std::chrono::steady_clock::now();

		for (auto & el : timeResults)
			el /= TimeCheckPerIter;

		std::sort(timeResults.begin(), timeResults.end());

		Time min = Time::max();
		Time max = Time::min();
		Time mean = Time::zero();
		Time median = Time::zero();
		Time stddev { 0.f };
		Time variance { 0.f };
		Time elapsed = endTime - startTime;

		for (auto & el : timeResults)
		{
			min = std::min(min, el);
			max = std::max(max, el);
			mean += el;
		}
		mean /= timeResults.size();

		if (timeResults.size() % 2 == 0)
			median = (timeResults[timeResults.size() / 2 - 1] + timeResults[timeResults.size() / 2]) / 2;
		else
			median = timeResults[timeResults.size() / 2];

		for (auto el : timeResults)
		{
			variance += Time(el.count() - mean.count()) * (el.count() - mean.count());
		}

		variance /= Time::rep((timeResults.size() - 1) or 1);

		stddev = Time(std::sqrt(variance.count()));

		return Result { min, max, mean, median, variance, stddev, elapsed, IterCount };
	}


	class Result
	{
	private:
		template<auto, size_t, size_t>
		friend Result run(std::string_view);
		Result(Time min, Time max, Time mean, Time median, Time variance, Time stddev, Time elapsed, size_t iterCount)
			: min(min), max(max), mean(mean), median(median), variance(variance), stddev(stddev), elapsed(elapsed), iterCount(iterCount) {}
	public:
		const std::string_view name;
		const Time min, max, mean, median, elapsed;
		const Time variance, stddev;
		const size_t iterCount;
	};
}

namespace std
{
	ostream & operator << (ostream & os, TinyFramework::Minibench::Result result)
	{
		os << "min " << result.min << " max " << result.max << " mean " << result.mean << " meadian " << result.median << " variance " << result.variance << " stddev " << result.stddev << std::endl;
		return os;
	}
}