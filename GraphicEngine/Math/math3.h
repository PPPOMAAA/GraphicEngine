#pragma once
#include <cmath>
#include "vec3.h"
#include <vector>
#include <array>

class math3
{
public:
	math3();
	math3(float);
	math3(float, float, float,
		  float, float, float,
		  float, float, float);
	math3(const vec3&, const vec3&, const vec3&);
	math3(const math3&);
	math3 operator+(const math3&) const;
	math3& operator+=(const math3&);
	math3 operator-(const math3&) const;
	math3& operator-=(const math3&);
	math3 operator*(const math3&) const;
	math3& operator*=(const math3&);
	math3 operator*(float) const;
	math3& operator*=(float);
	math3 operator/(float) const;
	math3& operator/=(float);
	math3 operator+(float) const;
	math3& operator+=(float);
	math3 operator-(float) const;
	math3& operator-=(float);
	vec3 operator*(const vec3&) const;
	math3 IdentityMatrix();
	math3 ReverseMatrix();
	math3 TransposedMatrix();
	vec3 GetRow(int);
	vec3 GetColumn(int);
	const bool operator==(const math3&);
	const bool operator!=(const math3&);

	std::array<std::array<float, 3>, 3> matrix;
};

