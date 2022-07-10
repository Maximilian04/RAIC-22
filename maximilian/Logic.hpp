#include "DebugInterface.hpp"
#include "model/Game.hpp"
#include "model/Order.hpp"
#include "model/Constants.hpp"

#include "Operators.hpp"

#include <iostream>
#include <vector>

using namespace std;

class Logic {
public:
    enum State {     // Простая система:
        SEARCHE = 0, // если врагов нет, ищем
        DUEL,        // если враг один, сражаемся
        RUNAWAY      // если врагов >1, бежим
    };

    Logic();

    model::UnitOrder getOrder(const model::Game& game, DebugInterface* debugInterface, const model::Unit& unit);
private:
    State state;

    int countEnemy(const model::Game& game);
};
