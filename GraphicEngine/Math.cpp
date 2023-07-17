#include "Math.h"

Vec2::Vec2() : x(0.0f), y(0.0f) {}

Vec2::Vec2(float x, float y) : x(x), y(y) {}

Vec2::Vec2(const Vec2& other) : x(other.x), y(other.y) {}

Vec2 Vec2::operator+(const Vec2& other) const {
    return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::operator-(const Vec2& other) const {
    return Vec2(x - other.x, y - other.y);
}

float Vec2::dot(const Vec2& other) const {
    return x * other.x + y * other.y;
}

Vec2 Vec2::operator*(float scalar) const {
    return Vec2(x * scalar, y * scalar);
}

Vec2 Vec2::operator/(float scalar) const {
    return Vec2(x / scalar, y / scalar);
}

float Vec2::length() const {
    return std::sqrt(x * x + y * y);
}

Vec2 Vec2::normalize() const {
    float len = length();
    if (len != 0.0f) {
        return Vec2(x / len, y / len);
    }
    return Vec2();
}

bool Vec2::operator==(const Vec2& other) const {
    return x == other.x && y == other.y;
}

bool Vec2::operator!=(const Vec2& other) const {
    return !(*this == other);
}

Vec3::Vec3() : x(0.0f), y(0.0f), z(0.0f) {}

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

Vec3::Vec3(const Vec3& other) : x(other.x), y(other.y), z(other.z) {}

Vec3 Vec3::operator+(const Vec3& other) const {
    return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::operator-(const Vec3& other) const {
    return Vec3(x - other.x, y - other.y, z - other.z);
}

float Vec3::dot(const Vec3& other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vec3 Vec3::operator*(float scalar) const {
    return Vec3(x * scalar, y * scalar, z * scalar);
}

Vec3 Vec3::operator/(float scalar) const {
    return Vec3(x / scalar, y / scalar, z / scalar);
}

Vec3 Vec3::cross(const Vec3& other) const {
    return Vec3(y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x);
}

float Vec3::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

Vec3 Vec3::normalize() const {
    float len = length();
    if (len != 0.0f) {
        return Vec3(x / len, y / len, z / len);
    }
    return Vec3();
}

bool Vec3::operator==(const Vec3& other) const {
    return x == other.x && y == other.y && z == other.z;
}

bool Vec3::operator!=(const Vec3& other) const {
    return !(*this == other);
}

Vec4::Vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}

Vec4::Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

Vec4::Vec4(const Vec4& other) : x(other.x), y(other.y), z(other.z), w(other.w) {}

Vec4 Vec4::operator+(const Vec4& other) const {
    return Vec4(x + other.x, y + other.y, z + other.z, w + other.w);
}

Vec4 Vec4::operator-(const Vec4& other) const {
    return Vec4(x - other.x, y - other.y, z - other.z, w - other.w);
}

float Vec4::dot(const Vec4& other) const {
    return x * other.x + y * other.y + z * other.z + w * other.w;
}

Vec4 Vec4::operator*(float scalar) const {
    return Vec4(x * scalar, y * scalar, z * scalar, w * scalar);
}

Vec4 Vec4::operator/(float scalar) const {
    return Vec4(x / scalar, y / scalar, z / scalar, w / scalar);
}

float Vec4::length() const {
    return std::sqrt(x * x + y * y + z * z + w * w);
}

Vec4 Vec4::normalize() const {
    float len = length();
    if (len != 0.0f) {
        return Vec4(x / len, y / len, z / len, w / len);
    }
    return Vec4();
}

bool Vec4::operator==(const Vec4& other) const {
    return x == other.x && y == other.y && z == other.z && w == other.w;
}

bool Vec4::operator!=(const Vec4& other) const {
    return !(*this == other);
}

Mat2::Mat2() {
    elements.fill(0.0f);
}

Mat2::Mat2(float m11, float m12, float m21, float m22) {
    elements[0] = m11;
    elements[1] = m12;
    elements[2] = m21;
    elements[3] = m22;
}

Mat2::Mat2(const Mat2& other) {
    elements = other.elements;
}

Mat2 Mat2::operator+(const Mat2& other) const {
    Mat2 result;
    for (int i = 0; i < 4; i++) {
        result.elements[i] = elements[i] + other.elements[i];
    }
    return result;
}

Mat2 Mat2::operator-(const Mat2& other) const {
    Mat2 result;
    for (int i = 0; i < 4; i++) {
        result.elements[i] = elements[i] - other.elements[i];
    }
    return result;
}

Mat2 Mat2::operator*(const Mat2& other) const {
    Mat2 result;
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 2; col++) {
            float sum = 0.0f;
            for (int k = 0; k < 2; k++) {
                sum += elements[row * 2 + k] * other.elements[k * 2 + col];
            }
            result.elements[row * 2 + col] = sum;
        }
    }
    return result;
}

Mat2 Mat2::operator*(float scalar) const {
    Mat2 result;
    for (int i = 0; i < 4; i++) {
        result.elements[i] = elements[i] * scalar;
    }
    return result;
}

Mat2 Mat2::operator/(float scalar) const {
    Mat2 result;
    for (int i = 0; i < 4; i++) {
        result.elements[i] = elements[i] / scalar;
    }
    return result;
}

Mat2 Mat2::operator+(float scalar) const {
    Mat2 result;
    for (int i = 0; i < 4; i++) {
        result.elements[i] = elements[i] + scalar;
    }
    return result;
}

Mat2 Mat2::operator-(float scalar) const {
    Mat2 result;
    for (int i = 0; i < 4; i++) {
        result.elements[i] = elements[i] - scalar;
    }
    return result;
}

Vec2 Mat2::operator*(const Vec2& vector) const {
    return Vec2(elements[0] * vector.x + elements[1] * vector.y,
        elements[2] * vector.x + elements[3] * vector.y);
}

Mat2 Mat2::identity() {
    return Mat2(1.0f, 0.0f, 0.0f, 1.0f);
}

Mat2 Mat2::transpose() const {
    Mat2 result;
    result.elements[0] = elements[0];
    result.elements[1] = elements[2];
    result.elements[2] = elements[1];
    result.elements[3] = elements[3];
    return result;
}

bool Mat2::operator==(const Mat2& other) const {
    return elements == other.elements;
}

bool Mat2::operator!=(const Mat2& other) const {
    return !(*this == other);
}

Mat3::Mat3() {
    elements.fill(0.0f);
}

Mat3::Mat3(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33) {
    elements[0] = m11;
    elements[1] = m12;
    elements[2] = m13;
    elements[3] = m21;
    elements[4] = m22;
    elements[5] = m23;
    elements[6] = m31;
    elements[7] = m32;
    elements[8] = m33;
}

Mat3::Mat3(const Mat3& other) {
    elements = other.elements;
}

Mat3 Mat3::operator+(const Mat3& other) const {
    Mat3 result;
    for (int i = 0; i < 9; i++) {
        result.elements[i] = elements[i] + other.elements[i];
    }
    return result;
}

Mat3 Mat3::operator-(const Mat3& other) const {
    Mat3 result;
    for (int i = 0; i < 9; i++) {
        result.elements[i] = elements[i] - other.elements[i];
    }
    return result;
}

Mat3 Mat3::operator*(const Mat3& other) const {
    Mat3 result;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            float sum = 0.0f;
            for (int k = 0; k < 3; k++) {
                sum += elements[row * 3 + k] * other.elements[k * 3 + col];
            }
            result.elements[row * 3 + col] = sum;
        }
    }
    return result;
}

Mat3 Mat3::operator*(float scalar) const {
    Mat3 result;
    for (int i = 0; i < 9; i++) {
        result.elements[i] = elements[i] * scalar;
    }
    return result;
}

Mat3 Mat3::operator/(float scalar) const {
    Mat3 result;
    for (int i = 0; i < 9; i++) {
        result.elements[i] = elements[i] / scalar;
    }
    return result;
}

Mat3 Mat3::operator+(float scalar) const {
    Mat3 result;
    for (int i = 0; i < 9; i++) {
        result.elements[i] = elements[i] + scalar;
    }
    return result;
}

Mat3 Mat3::operator-(float scalar) const {
    Mat3 result;
    for (int i = 0; i < 9; i++) {
        result.elements[i] = elements[i] - scalar;
    }
    return result;
}

Vec3 Mat3::operator*(const Vec3& vector) const {
    return Vec3(elements[0] * vector.x + elements[1] * vector.y + elements[2] * vector.z,
        elements[3] * vector.x + elements[4] * vector.y + elements[5] * vector.z,
        elements[6] * vector.x + elements[7] * vector.y + elements[8] * vector.z);
}

Mat3 Mat3::identity() {
    return Mat3(1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f);
}

Mat3 Mat3::transpose() const {
    Mat3 result;
    result.elements[0] = elements[0];
    result.elements[1] = elements[3];
    result.elements[2] = elements[6];
    result.elements[3] = elements[1];
    result.elements[4] = elements[4];
    result.elements[5] = elements[7];
    result.elements[6] = elements[2];
    result.elements[7] = elements[5];
    result.elements[8] = elements[8];
    return result;
}

bool Mat3::operator==(const Mat3& other) const {
    return elements == other.elements;
}

bool Mat3::operator!=(const Mat3& other) const {
    return !(*this == other);
}

Mat4::Mat4() {
    elements.fill(0.0f);
}

Mat4::Mat4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24,
    float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44) {
    elements[0] = m11;
    elements[1] = m12;
    elements[2] = m13;
    elements[3] = m14;
    elements[4] = m21;
    elements[5] = m22;
    elements[6] = m23;
    elements[7] = m24;
    elements[8] = m31;
    elements[9] = m32;
    elements[10] = m33;
    elements[11] = m34;
    elements[12] = m41;
    elements[13] = m42;
    elements[14] = m43;
    elements[15] = m44;
}

Mat4::Mat4(const Mat4& other) {
    elements = other.elements;
}

Mat4 Mat4::operator+(const Mat4& other) const {
    Mat4 result;
    for (int i = 0; i < 16; i++) {
        result.elements[i] = elements[i] + other.elements[i];
    }
    return result;
}

Mat4 Mat4::operator-(const Mat4& other) const {
    Mat4 result;
    for (int i = 0; i < 16; i++) {
        result.elements[i] = elements[i] - other.elements[i];
    }
    return result;
}

Mat4 Mat4::operator*(const Mat4& other) const {
    Mat4 result;
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            float sum = 0.0f;
            for (int k = 0; k < 4; k++) {
                sum += elements[row * 4 + k] * other.elements[k * 4 + col];
            }
            result.elements[row * 4 + col] = sum;
        }
    }
    return result;
}

Mat4 Mat4::operator*(float scalar) const {
    Mat4 result;
    for (int i = 0; i < 16; i++) {
        result.elements[i] = elements[i] * scalar;
    }
    return result;
}

Mat4 Mat4::operator/(float scalar) const {
    Mat4 result;
    for (int i = 0; i < 16; i++) {
        result.elements[i] = elements[i] / scalar;
    }
    return result;
}

Mat4 Mat4::operator+(float scalar) const {
    Mat4 result;
    for (int i = 0; i < 16; i++) {
        result.elements[i] = elements[i] + scalar;
    }
    return result;
}

Mat4 Mat4::operator-(float scalar) const {
    Mat4 result;
    for (int i = 0; i < 16; i++) {
        result.elements[i] = elements[i] - scalar;
    }
    return result;
}

Vec4 Mat4::operator*(const Vec4& vector) const {
    return Vec4(elements[0] * vector.x + elements[1] * vector.y + elements[2] * vector.z + elements[3] * vector.w,
        elements[4] * vector.x + elements[5] * vector.y + elements[6] * vector.z + elements[7] * vector.w,
        elements[8] * vector.x + elements[9] * vector.y + elements[10] * vector.z + elements[11] * vector.w,
        elements[12] * vector.x + elements[13] * vector.y + elements[14] * vector.z + elements[15] * vector.w);
}

Mat4 Mat4::identity() {
    return Mat4(1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f);
}

Mat4 Mat4::transpose() const {
    Mat4 result;
    result.elements[0] = elements[0];
    result.elements[1] = elements[4];
    result.elements[2] = elements[8];
    result.elements[3] = elements[12];
    result.elements[4] = elements[1];
    result.elements[5] = elements[5];
    result.elements[6] = elements[9];
    result.elements[7] = elements[13];
    result.elements[8] = elements[2];
    result.elements[9] = elements[6];
    result.elements[10] = elements[10];
    result.elements[11] = elements[14];
    result.elements[12] = elements[3];
    result.elements[13] = elements[7];
    result.elements[14] = elements[11];
    result.elements[15] = elements[15];
    return result;
}

bool Mat4::operator==(const Mat4& other) const {
    return elements == other.elements;
}

bool Mat4::operator!=(const Mat4& other) const {
    return !(*this == other);
}
