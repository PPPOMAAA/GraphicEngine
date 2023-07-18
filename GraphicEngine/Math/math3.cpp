#include "math3.h"

math3::math3() = default;

math3::math3(float number) {
	matrix[0][0] = number;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = number;
	matrix[1][2] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = number;
}

math3::math3(float a, float b, float c,
			 float d, float e, float f,
			 float g, float h, float i) 
{
	matrix[0][0] = a;
	matrix[0][1] = d;
	matrix[0][2] = g;
	matrix[1][0] = b;
	matrix[1][1] = e;
	matrix[1][2] = h;
	matrix[2][0] = c;
	matrix[2][1] = f;
	matrix[2][2] = i;
}

math3::math3(const vec3& first, const vec3& second, const vec3& third) {
	matrix[0][0] = first.x;
	matrix[0][1] = second.x;
	matrix[0][2] = third.x;
	matrix[1][0] = first.y;
	matrix[1][1] = second.y;
	matrix[1][2] = third.y;
	matrix[2][0] = first.z;
	matrix[2][1] = second.z;
	matrix[2][2] = third.z;
}

math3::math3(const math3& other) {
	matrix = other.matrix;
}

math3 math3::operator+(const math3& other) const {
	math3 res;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			res.matrix[i][j] = matrix[j][i] + other.matrix[j][i];
		}
	}
	return res;
}

math3& math3::operator+=(const math3& other) {
	*this = *this + other;
	return *this;
}

math3 math3::operator-(const math3& other) const {
	math3 res;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			res.matrix[i][j] = matrix[j][i] - other.matrix[j][i];
		}
	}
	return res;
}

math3& math3::operator-=(const math3& other) {
	*this = *this - other;
	return *this;
}

math3 math3::operator*(const math3& other) const {
	math3 res;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			res.matrix[j][i] = 0;
			for (int k = 0; k < 3; k++) {
				res.matrix[j][i] += matrix[i][k] * other.matrix[k][j];
			}
		}
	}
	return res;
}

math3& math3::operator*=(const math3& other) {
	*this = *this * other;
	return *this;
}

math3 math3::operator*(float number) const {
	math3 res;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			res.matrix[i][j] = matrix[j][i] * number;
		}
	}
	return res;
}

math3& math3::operator*=(float number) {
	*this = *this * number;
	return *this;
}

math3 math3::operator/(float number) const {
	math3 res;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			res.matrix[i][j] = matrix[j][i] / number;
		}
	}
	return res;
}

math3& math3::operator/=(float number) {
	*this = *this / number;
	return *this;
}

math3 math3::operator+(float number) const {
	math3 res;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			res.matrix[i][j] = matrix[j][i] + number;
		}
	}
	return res;
}

math3& math3::operator+=(float number) {
	*this = *this + number;
	return *this;
}

math3 math3::operator-(float number) const {
	math3 res;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			res.matrix[i][j] = matrix[j][i] - number;
		}
	}
	return res;
}

math3& math3::operator-=(float number) {
	*this = *this - number;
	return *this;
}

vec3 math3::operator*(const vec3& vec) const {
	vec3 res;
	res.x = matrix[0][0] * vec.x + matrix[0][1] * vec.y + matrix[0][2] * vec.z;
	res.y = matrix[1][0] * vec.x + matrix[1][1] * vec.y + matrix[1][2] * vec.z;
	res.z = matrix[2][0] * vec.x + matrix[2][1] * vec.y + matrix[2][2] * vec.z;
	return res;
}

math3 math3::IdentityMatrix() {
	return math3(1.0f);
}

math3 math3::ReverseMatrix() {
	float det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2])
		- matrix[1][0] * (matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[0][2])
		+ matrix[2][0] * (matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2]);

	math3 res;
	res.matrix[0][0] = (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]) * (1 / det);
	res.matrix[1][0] = -(matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]) * (1 / det);
	res.matrix[2][0] = (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]) * (1 / det);
	res.matrix[0][1] = -(matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[0][2]) * (1 / det);
	res.matrix[1][1] = (matrix[0][0] * matrix[2][2] - matrix[2][0] * matrix[0][2]) * (1 / det);
	res.matrix[2][1] = -(matrix[0][0] * matrix[2][1] - matrix[2][0] * matrix[0][1]) * (1 / det);
	res.matrix[0][2] = (matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2]) * (1 / det);
	res.matrix[1][2] = -(matrix[0][0] * matrix[1][2] - matrix[1][0] * matrix[0][2]) * (1 / det);
	res.matrix[2][2] = (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]) * (1 / det);

	return res;
}

math3 math3::TransposedMatrix() {
	return math3(GetColumn(0), GetColumn(1), GetColumn(2));
}

vec3 math3::GetRow(int ind) {
	if (ind >= 0 && ind < 3) {
		return vec3(matrix[ind][0], matrix[ind][1], matrix[ind][2]);
	}
}

vec3 math3::GetColumn(int ind) {
	if (ind >= 0 && ind < 3) {
		std::vector<float> res(3);
		for (int i = 0; i < 3; i++) {
			res[i] = matrix[i][ind];
		}
		return vec3(res[0], res[1], res[2]);
	}
}
const bool math3::operator==(const math3& other) {
	return (matrix == other.matrix);
}

const bool math3::operator!=(const math3& other) {
	return !(matrix == other.matrix);
}
