#include "Logic.hpp"

Logic::Logic() : state(State::AGRESSIVE) {

}

model::UnitOrder Logic::getOrder(const model::Game& game, DebugInterface* debugInterface, const model::Unit& unit) {
    std::shared_ptr<model::ActionOrder::Aim> aim = std::make_shared<model::ActionOrder::Aim>(true);
    std::optional<std::shared_ptr<model::ActionOrder>> action = std::make_optional(aim);

    model::UnitOrder order({ -unit.position.x, -unit.position.y }, { -unit.direction.y, unit.direction.x }, action);

    return order;
}
