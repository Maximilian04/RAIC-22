#include "RTConstants.hpp"
#include "Operators.hpp"

#include "DebugInterface.hpp"
#include "model/Game.hpp"
#include "model/Order.hpp"

#include <vector>
#include <cmath>
#include <iostream>
#include <functional>

#define MODIF (3.0)

using namespace std;

class Step {
public:
    Step(Step* par, int _rotate, double _boostDir, bool _shoot); // use with "new"
    Step(const model::Unit& unit, const model::Game& game); // DO NOT use with "new"
    ~Step();

    double leaveTheBest(function<double(Step&)> metric);
    Vec2 getActVelocity();

    double getHealth();
    Vec2 getPos();

    int rotate;
    double boostDir; // radians
    bool shoot;
private:
    double angle; // radians
    model::Vec2 vel, pos;
    vector<model::Projectile> projectiles;
    double health;

    Step* prevStep;
    vector<Step*> nextSteps;
};
