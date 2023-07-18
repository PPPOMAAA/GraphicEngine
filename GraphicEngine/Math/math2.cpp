#include "math2.h"

math2::math2() = default;

math2::math2(float number) {
	matrix[0][0] = number;
	matrix[0][1] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = number;
}

math2::math2(float a, float b, float c, float d) {
	matrix[0][0] = a;
	matrix[0][1] = c;
	matrix[1][0] = b;
	matrix[1][1] = d;
}

math2::math2(const vec2& first, const vec2& second) {
	matrix[0][0] = first.x;
	matrix[0][1] = second.x;
	matrix[1][0] = first.y;
	matrix[1][1] = second.y;
}

math2::math2(const math2& other) {
	matrix = other.matrix;
}

math2 math2::operator+(const math2& other) const {
	return math2(matrix[0][0] + other.matrix[0][0],
		matrix[0][1] + other.matrix[0][1],
		matrix[1][0] + other.matrix[1][0],
		matrix[1][1] + other.matrix[1][1]);
}

math2& math2::operator+=(const math2& other) {
	*this = *this + other;
	return *this;
}

math2 math2::operator-(const math2& other) const {
	return math2(matrix[0][0] - other.matrix[0][0],
		matrix[0][1] - other.matrix[0][1],
		matrix[1][0] - other.matrix[1][0],
		matrix[1][1] - other.matrix[1][1]);
}

math2& math2::operator-=(const math2& other) {
	*this = *this - other;
	return *this;
}

math2 math2::operator*(const math2& other) const {
	return math2(matrix[0][0] * other.matrix[0][0] + matrix[0][1] * other.matrix[1][0],
		matrix[0][0] * other.matrix[0][1] + matrix[0][1] * other.matrix[1][1],
		matrix[1][0] * other.matrix[0][0] + matrix[1][1] * other.matrix[1][0],
		matrix[1][0] * other.matrix[0][1] + matrix[1][1] * other.matrix[1][1]);
}

math2& math2::operator*=(const math2& other) {
	*this = *this * other;
	return *this;
}

math2 math2::operator*(float number) const {
	return math2(matrix[0][0] * number,
		matrix[0][1] * number,
		matrix[1][0] * number,
		matrix[1][1] * number);
}

math2& math2::operator*=(float number) {
	*this = *this * number;
	return *this;
}

math2 math2::operator/(float number) const {
	if ((matrix[0][0] != 0) && (matrix[0][1] != 0) && (matrix[1][0] != 0) && (matrix[1][1] != 0)) {
		return math2(matrix[0][0] / number,
			matrix[0][1] / number,
			matrix[1][0] / number,
			matrix[1][1] / number);
	}
}

math2& math2::operator/=(float number) {
	*this = *this / number;
	return *this;
}

math2 math2::operator+(float number) const {
	return math2(matrix[0][0] + number,
		matrix[0][1] + number,
		matrix[1][0] + number,
		matrix[1][1] + number);
}

math2& math2::operator+=(float number) {
	*this = *this + number;
	return *this;
}

math2 math2::operator-(float number) const {
	return math2(matrix[0][0] - number,
		matrix[0][1] - number,
		matrix[1][0] - number,
		matrix[1][1] - number);
}

math2& math2::operator-=(float number) {
	*this = *this - number;
	return *this;
}

vec2 math2::operator*(const vec2& other) const {
	vec2 res;
	res.x = matrix[0][0] * other.x + matrix[0][1] * other.y;
	res.y = matrix[1][0] * other.x + matrix[1][1] * other.y;
	return res;
}

math2 math2::IdentityMatrix() {
	return math2(1.0f);
}


math2 math2::ReverseMatrix() {
	float DivDet = 1 / (+matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]);
	return math2(+matrix[1][1] * DivDet, 
		-matrix[0][1] * DivDet,
		-matrix[1][0] * DivDet,
		+matrix[0][0] * DivDet);
}


math2 math2::TransposedMatrix() {
	return math2(GetColumn(0), GetColumn(1));
}

vec2 math2::GetRow(int ind) {
	if (ind >= 0 && ind < 2) {
		return vec2(matrix[ind][0], matrix[ind][1]);
	}
}

vec2 math2::GetColumn(int ind) {
	if (ind >= 0 && ind < 2) {
		std::vector<float> res(2);
		for (int i = 0; i < 2; i++) {
			res[i] = matrix[i][ind];
		}
		return vec2(res[0], res[1]);
	}
}

const bool math2::operator==(const math2& other) {
	return (matrix == other.matrix);
}

const bool math2::operator!=(const math2& other) {
	return !(matrix == other.matrix);
}