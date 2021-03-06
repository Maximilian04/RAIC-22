#include "DebugInterface.hpp"
#include "model/Game.hpp"
#include "model/Order.hpp"
#include "model/Constants.hpp"

#include <cmath>

using namespace model;

void operator+=(Vec2& a, const Vec2& b);
void operator*=(Vec2& a, const double& b);
void operator/=(Vec2& a, const double& b);
Vec2 operator+(const Vec2& a, const Vec2& b);
Vec2 operator-(const Vec2& a, const Vec2& b);
Vec2 operator*(const Vec2& a, const double& b);
Vec2 operator/(const Vec2& a, const double& b);

double abs(const Vec2& a);
