#pragma once
#include <cmath>

class vec3
{
public:
	vec3() = default;
	vec3(float);
	vec3(float, float, float);
	vec3(const vec3&);
	vec3 operator+(const vec3&) const;
	vec3& operator+=(const vec3&);
	vec3 operator-(const vec3&) const;
	vec3& operator-=(const vec3&);
	float ScalarMultiplication(const vec3&);
	vec3 operator*(float) const;
	vec3& operator*=(float);
	vec3 operator/(float) const;
	vec3& operator/=(float);
	vec3 VectorMultiplication(const vec3&);
	float Lenght();
	vec3 Normalize();
	const bool operator==(const vec3&);
	const bool operator!=(const vec3&);
	float x = 0, y = 0, z = 0;
};

