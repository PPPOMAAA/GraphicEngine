#pragma once
#include <cmath>

class vec4
{
public:
	vec4() = default;
	vec4(float);
	vec4(float, float, float, float);
	vec4(const vec4&);
	vec4 operator+(const vec4&) const;
	vec4& operator+=(const vec4&);
	vec4 operator-(const vec4&) const;
	vec4& operator-=(const vec4&);
	float ScalarMultiplication(const vec4&);
	vec4 operator*(float) const;
	vec4& operator*=(float);
	vec4 operator/(float) const;
	vec4& operator/=(float);
	float Lenght();
	vec4 Normalize();
	const bool operator==(const vec4&);
	const bool operator!=(const vec4&);
	float x = 0, y = 0, z = 0, w = 0;
};

