#include "Logic.hpp"

Logic::Logic() : state(State::SEARCHE) {

}

model::UnitOrder Logic::getOrder(const model::Game& game, DebugInterface* debugInterface, const model::Unit& unit) {
    model::Vec2 targetVelocity(-unit.position.x, -unit.position.y);
    model::Vec2 targetDirection(-unit.direction.y, unit.direction.x);

    for (bool decided = false; !decided;) switch (state) {
    case State::SEARCHE:
        if (game.units.size() > 1) {
            state = State::DUEL;
            break;
        }

        targetVelocity = model::Vec2(-unit.position.x, -unit.position.y);
        targetDirection = model::Vec2(-unit.position.x, -unit.position.y);
        decided = true;
        break;
    case State::DUEL:
        if (game.units.size() > 2) {
            state = State::RUNAWAY;
            break;
        }
        if (game.units.size() < 2) {
            state = State::SEARCHE;
            break;
        }
        const model::Unit* enemyPtr;
        for (const model::Unit& u : game.units) {
            if (u.id != unit.id) {
                enemyPtr = &u;
            }
        }

        targetVelocity = model::Vec2(enemyPtr->position.x - unit.position.x, enemyPtr->position.y - unit.position.y);
        targetDirection = model::Vec2(enemyPtr->position.x - unit.position.x, enemyPtr->position.y - unit.position.y);

        decided = true;
        break;
    case State::RUNAWAY:
        vector<const model::Unit*> enemyPtrs;
        for (const model::Unit& u : game.units) {
            if (u.id != unit.id) {
                enemyPtrs.push_back(&u);
            }
        }

        model::Vec2 averageEnemyPos(0., 0.);
        for (const model::Unit* enemyPtr : enemyPtrs) {
            averageEnemyPos += enemyPtr->position;
        }
        averageEnemyPos /= enemyPtrs.size();

        targetVelocity = model::Vec2(-(averageEnemyPos.x - unit.position.x), -(averageEnemyPos.y - unit.position.y));
        targetDirection = model::Vec2(averageEnemyPos.x - unit.position.x, averageEnemyPos.y - unit.position.y);

        decided = true;
        break;
    }


    std::shared_ptr<model::ActionOrder::Aim> aim = std::make_shared<model::ActionOrder::Aim>(true);
    std::optional<std::shared_ptr<model::ActionOrder>> action = std::make_optional(aim);

    model::UnitOrder order(targetVelocity, targetDirection, action);

    return order;
}
