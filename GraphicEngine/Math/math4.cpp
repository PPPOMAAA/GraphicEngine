#include "math4.h"

math4::math4() = default;

math4::math4(float number) {
	matrix[0][0] = number;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = 0;

	matrix[1][0] = 0;
	matrix[1][1] = number;
	matrix[1][2] = 0;
	matrix[1][3] = 0;

	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = number;
	matrix[2][3] = 0;

	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = number;
}

math4::math4(float a, float b, float c, float d,
			 float e, float f, float g, float h,
			 float i, float j, float k, float l,
			 float m, float n, float o, float r) 
{
	matrix[0][0] = a;
	matrix[0][1] = b;
	matrix[0][2] = c;
	matrix[0][3] = d;

	matrix[1][0] = e;
	matrix[1][1] = f;
	matrix[1][2] = g;
	matrix[1][3] = h;

	matrix[2][0] = i;
	matrix[2][1] = j;
	matrix[2][2] = k;
	matrix[2][3] = l;

	matrix[3][0] = m;
	matrix[3][1] = n;
	matrix[3][2] = o;
	matrix[3][3] = r;
}

math4::math4(const vec4& first, const vec4& second, const vec4& third, const vec4& four) {
	matrix[0][0] = first.x;
	matrix[0][1] = first.y;
	matrix[0][2] = first.z;
	matrix[0][3] = first.w;

	matrix[1][0] = second.x;
	matrix[1][1] = second.y;
	matrix[1][2] = second.z;
	matrix[1][3] = second.w;

	matrix[2][0] = third.x;
	matrix[2][1] = third.y;
	matrix[2][2] = third.z;
	matrix[2][3] = third.w;

	matrix[3][0] = four.x;
	matrix[3][1] = four.y;
	matrix[3][2] = four.z;
	matrix[3][3] = four.w;
}

math4::math4(const math4& other) {
	matrix = other.matrix;
}

math4 math4::operator+(const math4& other) const {
	math4 res;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			res.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
		}
	}
	return res;
}

math4& math4::operator+=(const math4& other) {
	*this = *this + other;
	return *this;
}

math4 math4::operator-(const math4& other) const {
	math4 res;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			res.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
		}
	}
	return res;
}

math4& math4::operator-=(const math4& other) {
	*this = *this - other;
	return *this;
}

math4 math4::operator*(const math4& other) const {
	math4 res;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			res.matrix[i][j] = 0;
			for (int k = 0; k < 4; k++) {
				res.matrix[i][j] += other.matrix[i][k] * matrix[k][j];
			}
		}
	}
	return res;
}

math4& math4::operator*=(const math4& other) {
	*this = *this * other;
	return *this;
}

math4 math4::operator*(float number) const {
	math4 res;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			res.matrix[i][j] = matrix[i][j] * number;
		}
	}
	return res;
}

math4& math4::operator*=(float number) {
	*this = *this * number;
	return *this;
}

math4 math4::operator/(float number) const {
	math4 res;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			res.matrix[i][j] = matrix[i][j] / number;
		}
	}
	return res;
}

math4& math4::operator/=(float number) {
	*this = *this / number;
	return *this;
}

math4 math4::operator+(float number) const {
	math4 res;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			res.matrix[i][j] = matrix[i][j] + number;
		}
	}
	return res;
}

math4& math4::operator+=(float number) {
	*this = *this + number;
	return *this;
}

math4 math4::operator-(float number) const {
	math4 res;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			res.matrix[i][j] = matrix[i][j] - number;
		}
	}
	return res;
}

math4& math4::operator-=(float number) {
	*this = *this - number;
	return *this;
}

vec4 math4::operator*(const vec4& vec) const {
	vec4 res;
	res.x = matrix[0][0] * vec.x + matrix[1][0] * vec.y + matrix[2][0] * vec.z + matrix[3][0] * vec.w;
	res.y = matrix[0][1] * vec.x + matrix[1][1] * vec.y + matrix[2][1] * vec.z + matrix[3][1] * vec.w;
	res.z = matrix[0][2] * vec.x + matrix[1][2] * vec.y + matrix[2][2] * vec.z + matrix[3][2] * vec.w;
	res.w = matrix[0][3] * vec.x + matrix[1][3] * vec.y + matrix[2][3] * vec.z + matrix[3][3] * vec.w;
	return res;
}

math4 math4::IdentityMatrix() {
	return math4(1.0f);
}
/*
math4 math4::ReverseMatrix() {
	float det = matrix[0][0] * (matrix[1][1] * matrix[2][2] * matrix[3][3] + matrix[1][2] * matrix[2][3] * matrix[3][1] + matrix[1][3] * matrix[2][1] * matrix[3][2] - matrix[1][3] * matrix[2][2] * matrix[3][1] - matrix[1][1] * matrix[2][3] * matrix[3][2] - matrix[1][2] * matrix[2][1] * matrix[3][3]) -
				matrix[1][0] * (matrix[0][1] * matrix[2][2] * matrix[3][3] + matrix[0][2] * matrix[2][3] * matrix[3][1] + matrix[0][3] * matrix[2][1] * matrix[3][2] - matrix[0][3] * matrix[2][2] * matrix[3][1] - matrix[0][1] * matrix[2][3] * matrix[3][2] - matrix[0][2] * matrix[2][1] * matrix[3][3]) +
				matrix[2][0] * (matrix[0][1] * matrix[1][2] * matrix[3][3] + matrix[0][2] * matrix[1][3] * matrix[3][1] + matrix[0][3] * matrix[1][1] * matrix[3][2] - matrix[0][3] * matrix[1][2] * matrix[3][1] - matrix[0][1] * matrix[1][3] * matrix[3][2] - matrix[0][2] * matrix[1][1] * matrix[3][3]) -
				matrix[3][0] * (matrix[0][1] * matrix[1][2] * matrix[2][3] + matrix[0][2] * matrix[1][3] * matrix[2][1] + matrix[0][3] * matrix[1][1] * matrix[2][2] - matrix[0][3] * matrix[1][2] * matrix[2][1] - matrix[0][1] * matrix[1][3] * matrix[2][2] - matrix[0][2] * matrix[1][1] * matrix[2][3]);

	
}
*/
math4 math4::TransposedMatrix() {
	return math4(GetRow(0), GetRow(1), GetRow(2), GetRow(3));
}

math4 math4::Translate(const vec3& vec) {
	math4 result(*this);

	result.matrix[3][0] = matrix[0][0] * vec.x + matrix[1][0] * vec.y + matrix[2][0] * vec.z + matrix[3][0];
	result.matrix[3][1] = matrix[0][1] * vec.x + matrix[1][1] * vec.y + matrix[2][1] * vec.z + matrix[3][1];
	result.matrix[3][2] = matrix[0][2] * vec.x + matrix[1][2] * vec.y + matrix[2][2] * vec.z + matrix[3][2];
	result.matrix[3][3] = matrix[0][3] * vec.x + matrix[1][3] * vec.y + matrix[2][3] * vec.z + matrix[3][3];

	return result;
}

math4 math4::Rotate(float angle, vec3& vec) {
	math4 result(*this);

	float cosAngle = cos(angle);
	float sinAngle = sin(angle);

	vec3 axis(vec.Normalize());
	vec3 sup(axis * (1 - cosAngle));

	math4 rotate;
	rotate.matrix[0][0] = cosAngle + sup.x * axis.x;
	rotate.matrix[0][1] = sup.x * axis.y + sinAngle * axis.z;
	rotate.matrix[0][2] = sup.x * axis.z - sinAngle * axis.y;
	rotate.matrix[0][3] = 0;

	rotate.matrix[1][0] = sup.y * axis.x - sinAngle * axis.z;
	rotate.matrix[1][1] = cosAngle + sup.y * axis.y;
	rotate.matrix[1][2] = sup.y * axis.z + sinAngle * axis.x;
	rotate.matrix[1][3] = 0;

	rotate.matrix[2][0] = sup.z * axis.x + sinAngle * axis.y;
	rotate.matrix[2][1] = sup.z * axis.y - sinAngle * axis.x;
	rotate.matrix[2][2] = cosAngle + sup.z * axis.z;
	rotate.matrix[2][3] = 0;

	rotate.matrix[3][0] = 0;
	rotate.matrix[3][1] = 0;
	rotate.matrix[3][2] = 0;
	rotate.matrix[3][3] = 1;

	return math4(*this * rotate);
}

math4 math4::Scale(const vec3& vec) {
	math4 result(*this);

	result.matrix[0][0] *= vec.x;
	result.matrix[0][1] *= vec.x;
	result.matrix[0][2] *= vec.x;
	result.matrix[0][3] *= vec.x;

	result.matrix[1][0] *= vec.y;
	result.matrix[1][1] *= vec.y;
	result.matrix[1][2] *= vec.y;
	result.matrix[1][3] *= vec.y;

	result.matrix[2][0] *= vec.z;
	result.matrix[2][1] *= vec.z;
	result.matrix[2][2] *= vec.z;
	result.matrix[2][3] *= vec.z;

	return result;
}

vec4 math4::GetRow(int ind) {
	if (ind >= 0 && ind < 4) {
		std::vector<float> res(4);
		for (int i = 0; i < 4; i++) {
			res[i] = matrix[i][ind];
		}
		return vec4(res[0], res[1], res[2], res[3]);
	}
}

vec4 math4::GetColumn(int ind) {
	if (ind >= 0 && ind < 4) {
		vec4 res(matrix[ind][0], matrix[ind][1], matrix[ind][2], matrix[ind][3]);
		return res;
	}
}

math4 math4::Ortho(float left, float right, float bottom, float top) {
	math4 result(1.0f);
	result.matrix[0][0] = 2.0f / (right - left);
	result.matrix[1][1] = 2.0f / (top - bottom);
	result.matrix[2][2] = -1.0f;
	result.matrix[3][0] = -(right + left) / (right - left);
	result.matrix[3][1] = -(top + bottom) / (top - bottom);
	return result;
}

math4 math4::LookAt(const vec3& eye, const vec3& center, const vec3& up) {
	vec3 f ((center - eye).Normalize());
	vec3 s (f.VectorMultiplication(up).Normalize());
	vec3 u (s.VectorMultiplication(f));

	math4 result(1.0f);
	result.matrix[0][0] = s.x;
	result.matrix[1][0] = s.y;
	result.matrix[2][0] = s.z;
	result.matrix[0][1] = u.x;
	result.matrix[1][1] = u.y;
	result.matrix[2][1] = u.z;
	result.matrix[0][2] = -f.x;
	result.matrix[1][2] = -f.y;
	result.matrix[2][2] = -f.z;
	result.matrix[3][0] = -s.ScalarMultiplication(eye);
	result.matrix[3][1] = -u.ScalarMultiplication(eye);
	result.matrix[3][2] = f.ScalarMultiplication(eye);

	return result;
}

math4 math4::Perspective(float fovy, float aspect, float zNear, float zFar) {
	assert(abs(aspect - std::numeric_limits<float>::epsilon()) > static_cast<float>(0));

	float tanHalfFovy = tan(fovy / 2.0f);

	math4 result(0.0f);
	result.matrix[0][0] = 1.0f / (aspect * tanHalfFovy);
	result.matrix[1][1] = 1.0f / (tanHalfFovy);
	result.matrix[2][2] = -(zFar + zNear) / (zFar - zNear);
	result.matrix[2][3] = -1.0f;
	result.matrix[3][2] = -(2.0f * zFar * zNear) / (zFar - zNear);
	return result;
}

const bool math4::operator==(const math4& other) {
	return (matrix == other.matrix);
}

const bool math4::operator!=(const math4& other) {
	return !(matrix == other.matrix);
}
