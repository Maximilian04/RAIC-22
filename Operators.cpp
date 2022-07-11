#include "Operators.hpp"

void operator+=(Vec2& a, const Vec2& b) {
    a.x += b.x;
    a.y += b.y;
}

void operator/=(Vec2& a, const double& b) {
    a.x /= b;
    a.y /= b;
}

Vec2 operator+(const Vec2& a, const Vec2& b) {
    return Vec2(a.x + b.x, a.y + b.y);
}

Vec2 operator-(const Vec2& a, const Vec2& b) {
    return Vec2(a.x - b.x, a.y - b.y);
}

Vec2 operator*(const Vec2& a, const double& b) {
    return Vec2(a.x * b, a.y * b);
}

Vec2 operator/(const Vec2& a, const double& b) {
    return Vec2(a.x / b, a.y / b);
}

double abs(const Vec2& a) {
    return std::sqrt(a.x * a.x + a.y * a.y);
}
