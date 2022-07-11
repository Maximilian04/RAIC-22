#include "RTConstants.hpp"
#include "Operators.hpp"

#include "DebugInterface.hpp"
#include "model/Game.hpp"
#include "model/Order.hpp"

#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class Step {
public:
    Step(Step* par, int _rotate, double _boostDir, bool _shoot); // use with "new"
    Step(const model::Unit& unit, const model::Game& game); // DO NOT use with "new"
    ~Step();

    double leaveTheBestHealth();
    Vec2 getActVelocity();

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
