#pragma once
#include <string_view>
#include <algorithm>
#include <vector>
#include <chrono>
#include <ostream>
#include <iomanip>
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
		Time elapsed = endTime - startTime;

		for (auto & el : timeResults)
		{
			min = std::min(min, Time(el));
			max = std::max(max, Time(el));
			mean += Time(el);
		}
		mean /= timeResults.size();

		if (timeResults.size() % 2 == 0)
			median = Time((timeResults[timeResults.size() / 2 - 1] + timeResults[timeResults.size() / 2]) / 2);
		else
			median = Time(timeResults[timeResults.size() / 2]);

		return Result { name, min, max, mean, median, elapsed, timeResults };
	}


	class Result
	{
	private:
		template<auto, size_t, size_t>
		friend Result run(std::string_view);
		Result(std::string_view name, Time min, Time max, Time mean, Time median, Time elapsed, std::vector<Time> results)
			: name(name), min(min), max(max), mean(mean), median(median), elapsed(elapsed), results(results) {}
	public:
		const std::string_view name;
		const std::vector<Time> results;
		const Time min, max, mean, median, elapsed;
	};


	template<typename ... Args>
	std::ostream & compare(std::ostream & os, Result origin, Args &&... compareTo)
	{
		using std::setw;
		std::ostringstream ios {};
		const size_t maxNameShift = std::max(std::max({ origin.name.size(), compareTo.name.size()... }) + 3, 11Ui64);
		const size_t indent = 11;
		auto consumeArg = [&ios, &origin, indent, maxNameShift](auto arg)
		{
			ios << "   ";
			ios << setw(maxNameShift) << arg.name << setw(indent) << arg.min / origin.min << setw(indent) << arg.max / origin.max << setw(indent) << arg.mean / origin.mean << setw(indent) << arg.median / origin.median << std::endl;
		};
		ios << std::left;
		ios << "MiniBench\n";
		ios << "   ";
		ios << setw(maxNameShift) << "name" << setw(indent) << "min" << setw(indent) << "max" << setw(indent) << "mean" << setw(indent) << "median" << std::endl;
		ios << "   ";
		ios << setw(maxNameShift) << origin.name << setw(indent) << origin.min << setw(indent) << origin.max << setw(indent) << origin.mean << setw(indent) << origin.median << "[origin]" << std::endl;
		ios << std::setprecision(3);
		(consumeArg(compareTo), ...);
		os << ios.str();
		return os << std::endl;
	}
}

namespace std
{
	ostream & operator << (ostream & os, TinyFramework::Minibench::Result result)
	{
		os << result.name << ": "  << "min " << result.min << " max " << result.max << " mean " << result.mean << " meadian " << result.median << std::endl;
		return os;
	}
}