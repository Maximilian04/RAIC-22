#include "Operators.hpp"

void operator+=(Vec2& a, const Vec2& b) {
    a.x += b.x;
    a.y += b.y;
}