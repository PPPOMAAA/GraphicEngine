#include "vec3.h"

vec3::vec3(float number) : x(number), y(number), z(number) {}

vec3::vec3(float x, float y, float z) : x(x), y(y), z(z) {}

vec3::vec3(const vec3& other) : x(other.x), y(other.y), z(other.z) {}

vec3 vec3::operator+(const vec3& other) const {
	return vec3(x + other.x, y + other.y, z + other.z);
}

vec3& vec3::operator+=(const vec3& other) {
	*this = *this + other;
	return *this;
}

vec3 vec3::operator-(const vec3& other) const {
	return vec3(x - other.x, y - other.y, z - other.z);
}

vec3& vec3::operator-=(const vec3& other) {
	*this = *this - other;
	return *this;
}

float vec3::ScalarMultiplication(const vec3& other) {
	return (x * other.x) + (y * other.y) + (z * other.z);
}


vec3 vec3::operator*(float number) const {
	return vec3(x * number, y * number, z * number);
}

vec3& vec3::operator*=(float number) {
	x = x * number;
	y = y * number;
	z = z * number;
	return *this;
}

vec3 vec3::operator/(float number) const {
	if (number != 0) {
		return vec3(x / number, y / number, z / number);
	}
}

vec3& vec3::operator/=(float number) {
	if (number != 0) {
		x = x / number;
		y = y / number;
		z = z / number;
		return *this;
	}
}

vec3 vec3::VectorMultiplication(const vec3& other) {
	return vec3(y * other.z - other.y * z, z * other.x - other.z * x, x * other.y - other.x * y);
}

float vec3::Lenght() {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

vec3 vec3::Normalize() {
	if (Lenght() != 0) {
		return vec3(x / Lenght(), y / Lenght(), z / Lenght());
	}
}

const bool vec3::operator==(const vec3& other) {
	return (x == other.x && y == other.y && z == other.z);
}

const bool vec3::operator!=(const vec3& other) {
	return !(x == other.x && y == other.y && z == other.z);
}
