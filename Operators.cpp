#include "Operators.hpp"

void operator+=(Vec2& a, const Vec2& b) {
    a.x += b.x;
    a.y += b.y;
}

void operator/=(Vec2& a, const double& b) {
    a.x /= b;
    a.y /= b;
}