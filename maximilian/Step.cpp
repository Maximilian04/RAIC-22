#include "Step.hpp"

Step::Step(Step* par, int _rotate, double _boostDir, bool _shoot) :
    prevStep(par), rotate(_rotate), boostDir(_boostDir), shoot(_shoot), vel(0, 0), pos(0, 0),
    projectiles(par->projectiles), health(par->health) {
    par->nextSteps.push_back(this);

    angle = par->angle + RTConstants::rotationSpeed / RTConstants::ticksPerSecond * (double)rotate; //TODO rotate in aim is different
    vel = par->vel + model::Vec2(cos(boostDir), sin(boostDir)) * (RTConstants::unitAcceleration / RTConstants::ticksPerSecond);

    Vec2 circleCenter = Vec2(cos(angle), sin(angle)) * ((RTConstants::maxUnitForwardSpeed - RTConstants::maxUnitBackwardSpeed) / 2);
    double circleRadius = (RTConstants::maxUnitForwardSpeed + RTConstants::maxUnitBackwardSpeed) / 2;
    Vec2 velNormed = vel - circleCenter; //TODO speed in aim is different
    if (abs(velNormed) > circleRadius) {
        velNormed *= circleRadius / abs(velNormed);
    }
    vel = velNormed + circleCenter;

    pos = par->pos + vel / RTConstants::ticksPerSecond;

    for (model::Projectile& bullet : projectiles) {
        bullet.position += bullet.velocity / RTConstants::ticksPerSecond;

        if (abs(bullet.position - pos) < RTConstants::unitRadius) {
            health -= RTConstants::weapons[bullet.weaponTypeIndex].projectileDamage;
        }
    };
}

Step::Step(const model::Unit& unit, const model::Game& game) :
    prevStep(nullptr), pos(unit.position), vel(unit.velocity), angle(atan2(unit.direction.x, unit.direction.y)),
    projectiles(game.projectiles), health(unit.health) {

}

double Step::leaveTheBestHealth() {
    if (nextSteps.size() == 0) {
        return health;
    } else if (nextSteps.size() == 1) {
        return nextSteps[0]->leaveTheBestHealth();
    } else {
        vector<double> childrensHealth;
        double bestHealthI = 0;
        for (int i = 0; i < nextSteps.size(); ++i) {
            childrensHealth.push_back(nextSteps[i]->leaveTheBestHealth());
            if (childrensHealth[i] > childrensHealth[bestHealthI]) {
                bestHealthI = i;
            }
        }

        Step* left = nextSteps[bestHealthI];
        for (int i = 0; i < nextSteps.size(); ++i) {
            if (i == bestHealthI) continue;
            delete nextSteps[i];
        }

        nextSteps.clear();
        nextSteps.push_back(left);
    }
}

Vec2 Step::getActVelocity() {
    if (nextSteps.size() == 0) {
        std::cout << "ERR831?" << endl;
        return Vec2(0, 0);
    }
    if (nextSteps.size() > 1) {
        std::cout << "ERR832?" << endl;
        return vel;
    }

    return nextSteps[0]->vel;
}

Step::~Step() {
    for (Step* next : nextSteps) {
        delete next;
    }
}