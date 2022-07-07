#include "DebugInterface.hpp"
#include "model/Game.hpp"
#include "model/Order.hpp"
#include "model/Constants.hpp"

class Logic {
public:
    enum State {
        AGRESSIVE = 0,
    };

    Logic();

    model::UnitOrder getOrder(const model::Game& game, DebugInterface* debugInterface, const model::Unit& unit);
private:
    State state;
};
