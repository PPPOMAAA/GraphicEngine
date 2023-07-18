#include "vec4.h"

vec4::vec4(float number) : x(number), y(number), z(number), w(number) {}

vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

vec4::vec4(const vec4& other) : x(other.x), y(other.y), z(other.z), w(other.w) {}

vec4 vec4::operator+(const vec4& other) const {
	return vec4(x + other.x, y + other.y, z + other.z, w + other.w);
}

vec4& vec4::operator+=(const vec4& other) {
	*this = *this + other;
	return *this;
}

vec4 vec4::operator-(const vec4& other) const {
	return vec4(x - other.x, y - other.y, z - other.z, w - other.w);
}

vec4& vec4::operator-=(const vec4& other) {
	*this = *this - other;
	return *this;
}

float vec4::ScalarMultiplication(const vec4& other) {
	return (x * other.x) + (y * other.y) + (z * other.z) + (w * other.w);
}


vec4 vec4::operator*(float number) const {
	return vec4(x * number, y * number, z * number, w * number);
}

vec4& vec4::operator*=(float number) {
	x = x * number;
	y = y * number;
	z = z * number;
	w = w * number;
	return *this;
}

vec4 vec4::operator/(float number) const {
	if (number != 0) {
		return vec4(x / number, y / number, z / number, w / number);
	}
}

vec4& vec4::operator/=(float number) {
	if (number != 0) {
		x = x / number;
		y = y / number;
		z = z / number;
		w = w / number;
		return *this;
	}
}

float vec4::Lenght() {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
}

vec4 vec4::Normalize() {
	if (Lenght() != 0) {
		return vec4(x / Lenght(), y / Lenght(), z / Lenght(), w / Lenght());
	}
}

const bool vec4::operator==(const vec4& other) {
	return (x == other.x && y == other.y, z == other.z && w == other.w);
}

const bool vec4::operator!=(const vec4& other) {
	return !(x == other.x && y == other.y && z == other.z && w == other.w);
}