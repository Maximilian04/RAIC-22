#include "MyStrategy.hpp"
#include <exception>

MyStrategy::MyStrategy(const model::Constants& constants) {
    RTConstants::ticksPerSecond = constants.ticksPerSecond;
    RTConstants::teamSize = constants.teamSize;
    RTConstants::initialZoneRadius = constants.initialZoneRadius;
    RTConstants::zoneSpeed = constants.zoneSpeed;
    RTConstants::zoneDamagePerSecond = constants.zoneDamagePerSecond;
    RTConstants::spawnTime = constants.spawnTime;
    RTConstants::spawnCollisionDamagePerSecond = constants.spawnCollisionDamagePerSecond;
    RTConstants::lootingTime = constants.lootingTime;
    RTConstants::botPlayers = constants.botPlayers;
    RTConstants::unitRadius = constants.unitRadius;
    RTConstants::unitHealth = constants.unitHealth;
    RTConstants::healthRegenerationPerSecond = constants.healthRegenerationPerSecond;
    RTConstants::healthRegenerationDelay = constants.healthRegenerationDelay;
    RTConstants::maxShield = constants.maxShield;
    RTConstants::spawnShield = constants.spawnShield;
    RTConstants::extraLives = constants.extraLives;
    RTConstants::lastRespawnZoneRadius = constants.lastRespawnZoneRadius;
    RTConstants::fieldOfView = constants.fieldOfView;
    RTConstants::viewDistance = constants.viewDistance;
    RTConstants::viewBlocking = constants.viewBlocking;
    RTConstants::rotationSpeed = constants.rotationSpeed;
    RTConstants::spawnMovementSpeed = constants.spawnMovementSpeed;
    RTConstants::maxUnitForwardSpeed = constants.maxUnitForwardSpeed;
    RTConstants::maxUnitBackwardSpeed = constants.maxUnitBackwardSpeed;
    RTConstants::unitAcceleration = constants.unitAcceleration;
    RTConstants::friendlyFire = constants.friendlyFire;
    RTConstants::killScore = constants.killScore;
    RTConstants::damageScoreMultiplier = constants.damageScoreMultiplier;
    RTConstants::scorePerPlace = constants.scorePerPlace;
    RTConstants::weapons = constants.weapons;
    RTConstants::startingWeapon = constants.startingWeapon;
    RTConstants::startingWeaponAmmo = constants.startingWeaponAmmo;
    RTConstants::maxShieldPotionsInInventory = constants.maxShieldPotionsInInventory;
    RTConstants::shieldPerPotion = constants.shieldPerPotion;
    RTConstants::shieldPotionUseTime = constants.shieldPotionUseTime;
    RTConstants::sounds = constants.sounds;
    RTConstants::stepsSoundTypeIndex = constants.stepsSoundTypeIndex;
    RTConstants::stepsSoundTravelDistance = constants.stepsSoundTravelDistance;
    RTConstants::obstacles = constants.obstacles;
}

model::Order MyStrategy::getOrder(const model::Game& game, DebugInterface* debugInterface) {
    std::unordered_map<int, model::UnitOrder> actions;

    for (auto& unit : game.units) {
        if (unit.playerId != game.myId)
            continue;

        //std::shared_ptr<model::ActionOrder::Aim> aim = std::make_shared<model::ActionOrder::Aim>(true);
        //std::optional<std::shared_ptr<model::ActionOrder>> action = std::make_optional(aim);
        //
        //model::UnitOrder order({ -unit.position.x, -unit.position.y }, { -unit.direction.y, unit.direction.x }, action);
        //actions.insert({ unit.id, order });

        actions.insert({ unit.id, logic.getOrder(game, debugInterface, unit) });
    }
    return model::Order(actions);
}

void MyStrategy::debugUpdate(DebugInterface& debugInterface) {}

void MyStrategy::finish() {}