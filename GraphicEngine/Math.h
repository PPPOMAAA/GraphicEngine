#pragma once

#include <cmath>
#include <array>

class Vec2 {
public:
    float x, y;

    Vec2();
    Vec2(float x, float y);
    Vec2(const Vec2& other);

    Vec2 operator+(const Vec2& other) const;
    Vec2 operator-(const Vec2& other) const;
    float dot(const Vec2& other) const;
    Vec2 operator*(float scalar) const;
    Vec2 operator/(float scalar) const;
    float length() const;
    Vec2 normalize() const;
    bool operator==(const Vec2& other) const;
    bool operator!=(const Vec2& other) const;
};

class Vec3 {
public:
    float x, y, z;

    Vec3();
    Vec3(float x, float y, float z);
    Vec3(const Vec3& other);

    Vec3 operator+(const Vec3& other) const;
    Vec3 operator-(const Vec3& other) const;
    float dot(const Vec3& other) const;
    Vec3 operator*(float scalar) const;
    Vec3 operator/(float scalar) const;
    Vec3 cross(const Vec3& other) const;
    float length() const;
    Vec3 normalize() const;
    bool operator==(const Vec3& other) const;
    bool operator!=(const Vec3& other) const;
};

class Vec4 {
public:
    float x, y, z, w;

    Vec4();
    Vec4(float x, float y, float z, float w);
    Vec4(const Vec4& other);

    Vec4 operator+(const Vec4& other) const;
    Vec4 operator-(const Vec4& other) const;
    float dot(const Vec4& other) const;
    Vec4 operator*(float scalar) const;
    Vec4 operator/(float scalar) const;
    float length() const;
    Vec4 normalize() const;
    bool operator==(const Vec4& other) const;
    bool operator!=(const Vec4& other) const;
};

class Mat2 {
public:
    std::array<float, 4> elements;

    Mat2();
    Mat2(float m11, float m12, float m21, float m22);
    Mat2(const Mat2& other);

    Mat2 operator+(const Mat2& other) const;
    Mat2 operator-(const Mat2& other) const;
    Mat2 operator*(const Mat2& other) const;
    Mat2 operator*(float scalar) const;
    Mat2 operator/(float scalar) const;
    Mat2 operator+(float scalar) const;
    Mat2 operator-(float scalar) const;
    Vec2 operator*(const Vec2& vector) const;
    static Mat2 identity();
    Mat2 transpose() const;
    bool operator==(const Mat2& other) const;
    bool operator!=(const Mat2& other) const;
};

class Mat3 {
public:
    std::array<float, 9> elements;

    Mat3();
    Mat3(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33);
    Mat3(const Mat3& other);

    Mat3 operator+(const Mat3& other) const;
    Mat3 operator-(const Mat3& other) const;
    Mat3 operator*(const Mat3& other) const;
    Mat3 operator*(float scalar) const;
    Mat3 operator/(float scalar) const;
    Mat3 operator+(float scalar) const;
    Mat3 operator-(float scalar) const;
    Vec3 operator*(const Vec3& vector) const;
    static Mat3 identity();
    Mat3 transpose() const;
    bool operator==(const Mat3& other) const;
    bool operator!=(const Mat3& other) const;
};

class Mat4 {
public:
    std::array<float, 16> elements;

    Mat4();
    Mat4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24,
        float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44);
    Mat4(const Mat4& other);

    Mat4 operator+(const Mat4& other) const;
    Mat4 operator-(const Mat4& other) const;
    Mat4 operator*(const Mat4& other) const;
    Mat4 operator*(float scalar) const;
    Mat4 operator/(float scalar) const;
    Mat4 operator+(float scalar) const;
    Mat4 operator-(float scalar) const;
    Vec4 operator*(const Vec4& vector) const;
    static Mat4 identity();
    Mat4 transpose() const;
    bool operator==(const Mat4& other) const;
    bool operator!=(const Mat4& other) const;
};