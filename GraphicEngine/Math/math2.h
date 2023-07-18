#pragma once
#include <cmath>
#include "vec2.h"
#include <vector>
#include <array>

class math2
{
public:
	math2();
	math2(float);
	math2(float, float, float, float);
	math2(const vec2&, const vec2&);
	math2(const math2&);
	math2 operator+(const math2&) const;
	math2& operator+=(const math2&);
	math2 operator-(const math2&) const;
	math2& operator-=(const math2&);
	math2 operator*(const math2&) const;
	math2& operator*=(const math2&);
	math2 operator*(float) const;
	math2& operator*=(float);
	math2 operator/(float) const;
	math2& operator/=(float);
	math2 operator+(float) const;
	math2& operator+=(float);
	math2 operator-(float) const;
	math2& operator-=(float);
	vec2 operator*(const vec2&) const;
	math2 IdentityMatrix();
	math2 ReverseMatrix();
	math2 TransposedMatrix();
	vec2 GetRow(int);
	vec2 GetColumn(int);
	const bool operator==(const math2&);
	const bool operator!=(const math2&);

	std::array<std::array<float, 2>, 2> matrix;
};
