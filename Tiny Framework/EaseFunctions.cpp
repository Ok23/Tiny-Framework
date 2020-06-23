#include "EaseFunctions.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

static float pi_f = M_PI;
static double pi_d = M_PI;

float TinyFramework::ease::linear(float state) noexcept
{
	return state;
}

double TinyFramework::ease::linear(double state) noexcept
{
	return state;
}

float TinyFramework::ease::inSine(float state) noexcept
{
	return std::sin(pi_f / 2.f * state);
}

double TinyFramework::ease::inSine(double state) noexcept
{
	return std::sin(pi_d / 2.0 * state);
}

float TinyFramework::ease::outSine(float state) noexcept
{
	return 1.f + std::sin(pi_f / 2.f * (state - 1.f));
}

double TinyFramework::ease::outSine(double state) noexcept
{
	return 1.f + std::sin(pi_d / 2.0 * (state - 1.0));
}

float TinyFramework::ease::inOutSine(float state) noexcept
{
	return 0.5f * (1.f + std::sin(pi_f * (state - 0.5f)));
}

double TinyFramework::ease::inOutSine(double state) noexcept
{
	return 0.5 * (1.0 + std::sin(pi_d * (state - 0.5)));
}

float TinyFramework::ease::inQuad(float state) noexcept
{
	return state * state;
}

double TinyFramework::ease::inQuad(double state) noexcept
{
	return state * state;
}

float TinyFramework::ease::outQuad(float state) noexcept
{
	return state * (2.f - state);
}

double TinyFramework::ease::outQuad(double state) noexcept
{
	return state * (2.0 - state);
}

float TinyFramework::ease::inOutQuad(float state) noexcept
{
	return state < 0.5f ? 2.f * state * state : state * (4.f - 2.f * state) - 1.f;
}

double TinyFramework::ease::inOutQuad(double state) noexcept
{
	return state < 0.5 ? 2.0 * state * state : state * (4.0 - 2.0 * state) - 1.0;
}

float TinyFramework::ease::inCubic(float state) noexcept
{
	return state * state * state;
}

double TinyFramework::ease::inCubic(double state) noexcept
{
	return state * state * state;
}

float TinyFramework::ease::outCubic(float state) noexcept
{
	return 1.f + (state - 1.f) * (state - 1.f) * (state - 1.f);
}

double TinyFramework::ease::outCubic(double state) noexcept
{
	return 1.0 + (state - 1.0) * (state - 1.0) * (state - 1.0);
}

float TinyFramework::ease::inOutCubic(float state) noexcept
{
	return state < 0.5f ?
		4.f * state * state * state : 1.f + (state - 1.f) * (2.f * (state - 1.f)) * (2.f * (state - 1.f));
}

double TinyFramework::ease::inOutCubic(double state) noexcept
{
	return state < 0.5 ?
		4.0 * state * state * state : 1.0 + (state - 1.0) * (2.0 * (state - 1.0)) * (2.0 * (state - 1.0));
}

float TinyFramework::ease::inQuart(float state) noexcept
{
	return state * state * state * state;
}

double TinyFramework::ease::inQuart(double state) noexcept
{
	return state * state * state * state;
}

float TinyFramework::ease::outQuart(float state) noexcept
{
	return 1.f + (state - 1.f) * (state - 1.f) * (state - 1.f);
}

double TinyFramework::ease::outQuart(double state) noexcept
{
	return 1.0 + (state - 1.0) * (state - 1.0) * (state - 1.0);
}

float TinyFramework::ease::inOutQuart(float state) noexcept
{
	return state < 0.5f ? 8.f * (state * state) * (state * state) :
		1.f - 8.f * ((state - 1.f) * (state - 1.f)) * ((state - 1.f) * (state - 1.f));
}

double TinyFramework::ease::inOutQuart(double state) noexcept
{
	return state < 0.5 ? 8.0 * (state * state) * (state * state) :
		1.0 - 8.0 * ((state - 1.0) * (state - 1.0)) * ((state - 1.0) * (state - 1.0));
}

float TinyFramework::ease::inQuint(float state) noexcept
{
	float t = state * state;
	return state * t * t;
}

double TinyFramework::ease::inQuint(double state) noexcept
{
	double t = state * state;
	return state * t * t;
}

float TinyFramework::ease::outQuint(float state) noexcept
{
	float t = (state - 1.f) * (state - 1.f);
	return 1.f + (state - 1.f) * t * t;
}

double TinyFramework::ease::outQuint(double state) noexcept
{
	double t = (state - 1.0) * (state - 1.0);
	return 1.0 + (state - 1.0) * t * t;
}

float TinyFramework::ease::inOutQuint(float state) noexcept
{
	float t;
	if (state < 0.5f)
	{
		t = state * state;
		return 16.f * state * t * t;
	}
	else
	{
		t = (state - 1.f) * (state - 1.f);
		return 1.f + 16.f * (state - 1.f) * t * t;
	}
}

double TinyFramework::ease::inOutQuint(double state) noexcept
{
	double t;
	if (state < 0.5)
	{
		t = state * state;
		return 16.0 * state * t * t;
	}
	else
	{
		t = (state - 1.0) * (state - 1.0);
		return 1.0 + 16.0 * (state - 1.0) * t * t;
	}
}

float TinyFramework::ease::inExpo(float state) noexcept
{
	return (std::pow(2.f, 8.f * state) - 1.f) / 255.f;
}

double TinyFramework::ease::inExpo(double state) noexcept
{
	return (std::pow(2.0, 8.0 * state) - 1.0) / 255.0;
}

float TinyFramework::ease::outExpo(float state) noexcept
{
	return 1.f - std::pow(2.f, -8.f * state);
}

double TinyFramework::ease::outExpo(double state) noexcept
{
	return 1.0 - std::pow(2.0, -8.0 * state);
}

float TinyFramework::ease::inOutExpo(float state) noexcept
{
	if (state < 0.5f)
		return (std::pow(2.f, 16.f * state) - 1.f) / 510.f;
	else
		return 1.f - 0.5f * std::pow(2.f, -16.f * (state - 0.5f));
}

double TinyFramework::ease::inOutExpo(double state) noexcept
{
	if (state < 0.5)
		return (std::pow(2.0, 16.0 * state) - 1.0) / 510.0;
	else
		return 1.0 - 0.50 * std::pow(2.0, -16.0 * (state - 0.5));
}

float TinyFramework::ease::inCirc(float state) noexcept
{
	return 1.f - std::sqrt(1.f - state);
}

double TinyFramework::ease::inCirc(double state) noexcept
{
	return 1.0 - std::sqrt(1.0 - state);
}

float TinyFramework::ease::outCirc(float state) noexcept
{
	return std::sqrt(state);
}

double TinyFramework::ease::outCirc(double state) noexcept
{
	return std::sqrt(state);
}

float TinyFramework::ease::inOutCirc(float state) noexcept
{
	return (state < 0.5f) ? (1.f - std::sqrt(1.f - 2.f * state)) * 0.5f : (1.f + std::sqrt(2.f * state - 1.f)) * 0.5f;
}

double TinyFramework::ease::inOutCirc(double state) noexcept
{
	return (state < 0.5) ? (1.0 - std::sqrt(1.0 - 2.0 * state)) * 0.5 : (1.0 + std::sqrt(2.0 * state - 1.0)) * 0.5;
}

float TinyFramework::ease::inBack(float state) noexcept
{
	return state * state * ((1.70158f + 1.f) * state - 1.70158f);
}

double TinyFramework::ease::inBack(double state) noexcept
{
	return state * state * ((1.70158 + 1.0) * state - 1.70158);
}

float TinyFramework::ease::outBack(float state) noexcept
{
	return 1.f + (state - 1.f) * (state - 1.f) * ((1.70158f + 1.f) * (state - 1.f) + 1.70158f);
}

double TinyFramework::ease::outBack(double state) noexcept
{
	return 1.0 + (state - 1.0) * (state - 1.0) * ((1.70158 + 1.) * (state - 1.0) + 1.70158);
}

float TinyFramework::ease::inOutBack(float state) noexcept
{
	return state < 0.5f ?
		state * state * (7.f * state - 2.5f) * 2.f :
		1.f + (state - 1.f) * (state - 1.f) * 2.f * (7.f * (state - 1.f) + 2.5f);
}

double TinyFramework::ease::inOutBack(double state) noexcept
{
	return state < 0.5 ?
		state * state * (7.0 * state - 2.5) * 2. :
		1.0 + (state - 1.0) * (state - 1.0) * 2.0 * (7.0 * (state - 1.0) + 2.5);
}

float TinyFramework::ease::inElastic(float state) noexcept
{
	float t = state * state;
	return t * t * std::sin(state * pi_f * 4.5f);
}

double TinyFramework::ease::inElastic(double state) noexcept
{
	double t = state * state;
	return t * t * std::sin(state * pi_d * 4.5);
}

float TinyFramework::ease::outElastic(float state) noexcept
{
	float t = (state - 1.f) * (state - 1.f);
	return 1.f - t * t * std::cos(state * pi_f * 4.5f);
}

double TinyFramework::ease::outElastic(double state) noexcept
{
	double t = (state - 1.0) * (state - 1.0);
	return 1.0 - t * t * std::cos(state * pi_d * 4.5);
}

float TinyFramework::ease::inOutElastic(float state) noexcept
{
	if (state < 0.45f)
	{
		float t = state * state;
		return 8.f * t * t * std::sin(state * pi_f * 9.f);
	}
	else if (state < 0.55f)
	{
		return 0.5f + 0.75f * std::sin(state * pi_f * 4.f);
	}
	else
	{
		float t = (state - 1.f) * (state - 1.f);
		return 1.f - 8.f * t * t * std::sin(state * pi_f * 9.f);
	}
}

double TinyFramework::ease::inOutElastic(double state) noexcept
{
	if (state < 0.45)
	{
		double t = state * state;
		return 8.0 * t * t * std::sin(state * pi_d * 9.0);
	}
	else if (state < 0.55)
	{
		return 0.5 + 0.75 * std::sin(state * pi_d * 4.0);
	}
	else
	{
		double t = (state - 1.0) * (state - 1.0);
		return 1.0 - 8.0 * t * t * std::sin(state * pi_d * 9.0);
	}
}

float TinyFramework::ease::inBounce(float state) noexcept
{
	return std::pow(2.f, 6.f * (state - 1.f)) * std::abs(std::sin(state * pi_f * 3.5f));
}

double TinyFramework::ease::inBounce(double state) noexcept
{
	return std::pow(2.0, 6.0 * (state - 1.0)) * std::abs(std::sin(state * pi_d * 3.5));
}

float TinyFramework::ease::outBounce(float state) noexcept
{
	return 1.f - std::pow(2.f, -6.f * state) * std::abs(std::cos(state * pi_f * 3.5f));
}

double TinyFramework::ease::outBounce(double state) noexcept
{
	return 1.0 - std::pow(2.0, -6.0 * state) * std::abs(std::cos(state * pi_d * 3.5));
}

float TinyFramework::ease::inOutBounce(float state) noexcept
{
	return state < 0.5f ?
		8.f * std::pow(2.f, 8.f * (state - 1.f)) * std::abs(std::sin(state * pi_f * 7.f)) :
		1.f - 8.f * std::pow(2.f, -8.f * state) * std::abs(std::sin(state * pi_f * 7.f));
}

double TinyFramework::ease::inOutBounce(double state) noexcept
{
	return state < 0.5 ?
		8.0 * std::pow(2.0, 8.0 * (state - 1.0)) * std::abs(std::sin(state * pi_d * 7.0)) :
		1.0 - 8.0 * std::pow(2.0, -8.0 * state) * std::abs(std::sin(state * pi_d * 7.0));
}
