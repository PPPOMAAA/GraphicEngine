#pragma once
#include <cmath>

class vec2
{
public:
	vec2() = default;
	vec2(float);
	vec2(float, float);
	vec2(const vec2&);
	vec2 operator+(const vec2&) const;
	vec2& operator+=(const vec2&);
	vec2 operator-(const vec2&) const;
	vec2& operator-=(const vec2&);
	float ScalarMultiplication(const vec2&);
	vec2 operator*(float) const;
	vec2& operator*=(float);
	vec2 operator/(float) const;
	vec2& operator/=(float);
	float Lenght();
	vec2 Normalize();
	const bool operator==(const vec2&);
	const bool operator!=(const vec2&);
	float x = 0, y = 0;
};
