#include <cmath>
#include <array>

class Vec2 {
public:
    float x, y;

    // Конструкторы
    Vec2() : x(0.0f), y(0.0f) {}
    Vec2(float x, float y) : x(x), y(y) {}
    Vec2(const Vec2& other) : x(other.x), y(other.y) {}

    // Сложение векторов
    Vec2 operator+(const Vec2& other) const {
        return Vec2(x + other.x, y + other.y);
    }

    // Вычитание векторов
    Vec2 operator-(const Vec2& other) const {
        return Vec2(x - other.x, y - other.y);
    }

    // Скалярное произведение
    float dot(const Vec2& other) const {
        return x * other.x + y * other.y;
    }

    // Умножение на число
    Vec2 operator*(float scalar) const {
        return Vec2(x * scalar, y * scalar);
    }

    // Деление на число
    Vec2 operator/(float scalar) const {
        return Vec2(x / scalar, y / scalar);
    }

    // Длина вектора
    float length() const {
        return std::sqrt(x * x + y * y);
    }

    // Нормализация вектора
    Vec2 normalize() const {
        float len = length();
        if (len != 0.0f) {
            return Vec2(x / len, y / len);
        }
        return Vec2();
    }

    // Сравнение векторов
    bool operator==(const Vec2& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vec2& other) const {
        return !(*this == other);
    }
};

class Vec3 {
public:
    float x, y, z;

    // Конструкторы
    Vec3() : x(0.0f), y(0.0f), z(0.0f) {}
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
    Vec3(const Vec3& other) : x(other.x), y(other.y), z(other.z) {}

    // Сложение векторов
    Vec3 operator+(const Vec3& other) const {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

    // Вычитание векторов
    Vec3 operator-(const Vec3& other) const {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }

    // Скалярное произведение
    float dot(const Vec3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // Умножение на число
    Vec3 operator*(float scalar) const {
        return Vec3(x * scalar, y * scalar, z * scalar);
    }

    // Деление на число
    Vec3 operator/(float scalar) const {
        return Vec3(x / scalar, y / scalar, z / scalar);
    }

    // Векторное произведение
    Vec3 cross(const Vec3& other) const {
        return Vec3(y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x);
    }

    // Длина вектора
    float length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    // Нормализация вектора
    Vec3 normalize() const {
        float len = length();
        if (len != 0.0f) {
            return Vec3(x / len, y / len, z / len);
        }
        return Vec3();
    }

    // Сравнение векторов
    bool operator==(const Vec3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator!=(const Vec3& other) const {
        return !(*this == other);
    }
};

class Vec4 {
public:
    float x, y, z, w;

    // Конструкторы
    Vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
    Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
    Vec4(const Vec4& other) : x(other.x), y(other.y), z(other.z), w(other.w) {}

    // Сложение векторов
    Vec4 operator+(const Vec4& other) const {
        return Vec4(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    // Вычитание векторов
    Vec4 operator-(const Vec4& other) const {
        return Vec4(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    // Скалярное произведение
    float dot(const Vec4& other) const {
        return x * other.x + y * other.y + z * other.z + w * other.w;
    }

    // Умножение на число
    Vec4 operator*(float scalar) const {
        return Vec4(x * scalar, y * scalar, z * scalar, w * scalar);
    }

    // Деление на число
    Vec4 operator/(float scalar) const {
        return Vec4(x / scalar, y / scalar, z / scalar, w / scalar);
    }

    // Длина вектора
    float length() const {
        return std::sqrt(x * x + y * y + z * z + w * w);
    }

    // Нормализация вектора
    Vec4 normalize() const {
        float len = length();
        if (len != 0.0f) {
            return Vec4(x / len, y / len, z / len, w / len);
        }
        return Vec4();
    }

    // Сравнение векторов
    bool operator==(const Vec4& other) const {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    bool operator!=(const Vec4& other) const {
        return !(*this == other);
    }
};

class Mat2 {
public:
    std::array<float, 4> elements;

    // Конструкторы
    Mat2() {
        elements.fill(0.0f);
    }

    Mat2(float m11, float m12, float m21, float m22) {
        elements[0] = m11;
        elements[1] = m12;
        elements[2] = m21;
        elements[3] = m22;
    }

    Mat2(const Mat2& other) {
        elements = other.elements;
    }

    // Сложение матриц
    Mat2 operator+(const Mat2& other) const {
        Mat2 result;
        for (int i = 0; i < 4; i++) {
            result.elements[i] = elements[i] + other.elements[i];
        }
        return result;
    }

    // Вычитание матриц
    Mat2 operator-(const Mat2& other) const {
        Mat2 result;
        for (int i = 0; i < 4; i++) {
            result.elements[i] = elements[i] - other.elements[i];
        }
        return result;
    }

    // Умножение матриц
    Mat2 operator*(const Mat2& other) const {
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

    // Умножение матрицы на число
    Mat2 operator*(float scalar) const {
        Mat2 result;
        for (int i = 0; i < 4; i++) {
            result.elements[i] = elements[i] * scalar;
        }
        return result;
    }

    // Деление матрицы на число
    Mat2 operator/(float scalar) const {
        Mat2 result;
        for (int i = 0; i < 4; i++) {
            result.elements[i] = elements[i] / scalar;
        }
        return result;
    }

    // Прибавление числа к матрице
    Mat2 operator+(float scalar) const {
        Mat2 result;
        for (int i = 0; i < 4; i++) {
            result.elements[i] = elements[i] + scalar;
        }
        return result;
    }

    // Вычитание числа из матрицы
    Mat2 operator-(float scalar) const {
        Mat2 result;
        for (int i = 0; i < 4; i++) {
            result.elements[i] = elements[i] - scalar;
        }
        return result;
    }

    // Умножение матрицы на вектор
    Vec2 operator*(const Vec2& vector) const {
        return Vec2(
            elements[0] * vector.x + elements[1] * vector.y,
            elements[2] * vector.x + elements[3] * vector.y
        );
    }

    // Единичная матрица
    static Mat2 identity() {
        return Mat2(1.0f, 0.0f,
                    0.0f, 1.0f);
    }

    // Транспонированная матрица
    Mat2 transpose() const {
        return Mat2(elements[0], elements[2], elements[1], elements[3]);
    }

    // Сравнение матриц
    bool operator==(const Mat2& other) const {
        for (int i = 0; i < 4; i++) {
            if (elements[i] != other.elements[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Mat2& other) const {
        return !(*this == other);
    }
};

class Mat3 {
public:
    std::array<float, 9> elements;

    // Конструкторы
    Mat3() {
        elements.fill(0.0f);
    }

    Mat3(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33) {
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

    Mat3(const Mat3& other) {
        elements = other.elements;
    }

    // Сложение матриц
    Mat3 operator+(const Mat3& other) const {
        Mat3 result;
        for (int i = 0; i < 9; i++) {
            result.elements[i] = elements[i] + other.elements[i];
        }
        return result;
    }

    // Вычитание матриц
    Mat3 operator-(const Mat3& other) const {
        Mat3 result;
        for (int i = 0; i < 9; i++) {
            result.elements[i] = elements[i] - other.elements[i];
        }
        return result;
    }

    // Умножение матриц
    Mat3 operator*(const Mat3& other) const {
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

    // Умножение матрицы на число
    Mat3 operator*(float scalar) const {
        Mat3 result;
        for (int i = 0; i < 9; i++) {
            result.elements[i] = elements[i] * scalar;
        }
        return result;
    }

    // Деление матрицы на число
    Mat3 operator/(float scalar) const {
        Mat3 result;
        for (int i = 0; i < 9; i++) {
            result.elements[i] = elements[i] / scalar;
        }
        return result;
    }

    // Прибавление числа к матрице
    Mat3 operator+(float scalar) const {
        Mat3 result;
        for (int i = 0; i < 9; i++) {
            result.elements[i] = elements[i] + scalar;
        }
        return result;
    }

    // Вычитание числа из матрицы
    Mat3 operator-(float scalar) const {
        Mat3 result;
        for (int i = 0; i < 9; i++) {
            result.elements[i] = elements[i] - scalar;
        }
        return result;
    }

    // Умножение матрицы на вектор
    Vec3 operator*(const Vec3& vector) const {
        return Vec3(
            elements[0] * vector.x + elements[1] * vector.y + elements[2] * vector.z,
            elements[3] * vector.x + elements[4] * vector.y + elements[5] * vector.z,
            elements[6] * vector.x + elements[7] * vector.y + elements[8] * vector.z
        );
    }

    // Единичная матрица
    static Mat3 identity() {
        return Mat3(1.0f, 0.0f, 0.0f,
                    0.0f, 1.0f, 0.0f, 
                    0.0f, 0.0f, 1.0f);
    }

    // Транспонированная матрица
    Mat3 transpose() const {
        return Mat3(
            elements[0], elements[3], elements[6],
            elements[1], elements[4], elements[7],
            elements[2], elements[5], elements[8]
        );
    }

    // Сравнение матриц
    bool operator==(const Mat3& other) const {
        for (int i = 0; i < 9; i++) {
            if (elements[i] != other.elements[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Mat3& other) const {
        return !(*this == other);
    }
};

class Mat4 {
public:
    std::array<float, 16> elements;

    // Конструкторы
    Mat4() {
        elements.fill(0.0f);
    }

    Mat4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24,
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

    Mat4(const Mat4& other) {
        elements = other.elements;
    }

    // Сложение матриц
    Mat4 operator+(const Mat4& other) const {
        Mat4 result;
        for (int i = 0; i < 16; i++) {
            result.elements[i] = elements[i] + other.elements[i];
        }
        return result;
    }

    // Вычитание матриц
    Mat4 operator-(const Mat4& other) const {
        Mat4 result;
        for (int i = 0; i < 16; i++) {
            result.elements[i] = elements[i] - other.elements[i];
        }
        return result;
    }

    // Умножение матриц
    Mat4 operator*(const Mat4& other) const {
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

    // Умножение матрицы на число
    Mat4 operator*(float scalar) const {
        Mat4 result;
        for (int i = 0; i < 16; i++) {
            result.elements[i] = elements[i] * scalar;
        }
        return result;
    }

    // Деление матрицы на число
    Mat4 operator/(float scalar) const {
        Mat4 result;
        for (int i = 0; i < 16; i++) {
            result.elements[i] = elements[i] / scalar;
        }
        return result;
    }

    // Прибавление числа к матрице
    Mat4 operator+(float scalar) const {
        Mat4 result;
        for (int i = 0; i < 16; i++) {
            result.elements[i] = elements[i] + scalar;
        }
        return result;
    }

    // Вычитание числа из матрицы
    Mat4 operator-(float scalar) const {
        Mat4 result;
        for (int i = 0; i < 16; i++) {
            result.elements[i] = elements[i] - scalar;
        }
        return result;
    }

    // Умножение матрицы на вектор
    Vec4 operator*(const Vec4& vector) const {
        return Vec4(
            elements[0] * vector.x + elements[1] * vector.y + elements[2] * vector.z + elements[3] * vector.w,
            elements[4] * vector.x + elements[5] * vector.y + elements[6] * vector.z + elements[7] * vector.w,
            elements[8] * vector.x + elements[9] * vector.y + elements[10] * vector.z + elements[11] * vector.w,
            elements[12] * vector.x + elements[13] * vector.y + elements[14] * vector.z + elements[15] * vector.w
        );
    }

    // Единичная матрица
    static Mat4 identity() {
        return Mat4(
            1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f
        );
    }

    // Транспонированная матрица
    Mat4 transpose() const {
        return Mat4(
            elements[0], elements[4], elements[8], elements[12],
            elements[1], elements[5], elements[9], elements[13],
            elements[2], elements[6], elements[10], elements[14],
            elements[3], elements[7], elements[11], elements[15]
        );
    }

    // Сравнение матриц
    bool operator==(const Mat4& other) const {
        for (int i = 0; i < 16; i++) {
            if (elements[i] != other.elements[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Mat4& other) const {
        return !(*this == other);
    }
};