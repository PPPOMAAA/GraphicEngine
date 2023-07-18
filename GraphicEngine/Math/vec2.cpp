#include "vec2.h"

vec2::vec2(float number): x(number), y(number) {}

vec2::vec2(float x, float y): x(x), y(y) {}

vec2::vec2(const vec2& other): x(other.x), y(other.y) {}

vec2 vec2::operator+(const vec2& other) const {
	return vec2(x + other.x, y + other.y);
}

vec2& vec2::operator+=(const vec2& other) {
	*this = *this + other;
	return *this;
}

vec2 vec2::operator-(const vec2& other) const {
	return vec2(x - other.x, y - other.y);
}

vec2& vec2::operator-=(const vec2& other) {
	*this = *this - other;
	return *this;
}

float vec2::ScalarMultiplication(const vec2& other) {
	return (x * other.x) + (y * other.y);
}


vec2 vec2::operator*(float number) const {
	return vec2(x * number, y * number);
}

vec2& vec2::operator*=(float number) {
	x = x * number;
	y = y * number;
	return *this;
}

vec2 vec2::operator/(float number) const {
	if (number != 0) {
		return vec2(x / number, y / number);
	}
}

vec2& vec2::operator/=(float number) {
	if (number != 0) {
		x = x / number;
		y = y / number;
		return *this;
	}
}

float vec2::Lenght() {
	return sqrt(pow(x, 2) + pow(y, 2));
}

vec2 vec2::Normalize() {
	if (Lenght() != 0) {
		return vec2(x / Lenght(), y / Lenght());
	}
}

const bool vec2::operator==(const vec2& other) {
	return (x == other.x && y == other.y);
}

const bool vec2::operator!=(const vec2& other) {
	return !(x == other.x && y == other.y);
}