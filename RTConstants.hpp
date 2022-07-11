#pragma once

#include "Stream.hpp"
#include "model/Obstacle.hpp"
#include "model/SoundProperties.hpp"
#include "model/Vec2.hpp"
#include "model/WeaponProperties.hpp"

#include <optional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

class RTConstants {
public:
    // Number of ticks per game second
    static double ticksPerSecond;
    // Starting number of units in each team
    static int teamSize;
    // Initial zone radius
    static double initialZoneRadius;
    // Speed of zone radius
    static double zoneSpeed;
    // Damage dealt to units outside of the zone per second
    static double zoneDamagePerSecond;
    // Unit spawning time
    static double spawnTime;
    // Damage dealt to units trying to spawn in incorrect position per second
    static double spawnCollisionDamagePerSecond;
    // Time required to perform looting actions (in seconds)
    static double lootingTime;
    // Number of bot players (teams)
    static int botPlayers;
    // Units' radius
    static double unitRadius;
    // Max units' health
    static double unitHealth;
    // Health automatically restored per second
    static double healthRegenerationPerSecond;
    // Time until automatic health regeneration since last health damage (in seconds)
    static double healthRegenerationDelay;
    // Max value of unit's shield
    static double maxShield;
    // Initial value of unit's shield
    static double spawnShield;
    // Initial number of extra lives for units
    static int extraLives;
    // Zone radius after which respawning is disabled
    static double lastRespawnZoneRadius;
    // Units' field of view without aiming (in degrees)
    static double fieldOfView;
    // Units' view distance
    static double viewDistance;
    // Whether units' view is blocked by obstacles
    static bool viewBlocking;
    // Unit rotation speed without aiming (degrees per second)
    static double rotationSpeed;
    // Units' movement speed while spawning
    static double spawnMovementSpeed;
    // Max unit speed when walking forward
    static double maxUnitForwardSpeed;
    // Max unit speed when walking backward
    static double maxUnitBackwardSpeed;
    // Max unit acceleration
    static double unitAcceleration;
    // Whether a unit can damage units of the same team
    static bool friendlyFire;
    // Score given for killing enemy unit
    static double killScore;
    // Score multiplier for damaging enemy units
    static double damageScoreMultiplier;
    // Score given for every team killed before you
    static double scorePerPlace;
    // List of properties of every weapon type
    static std::vector<model::WeaponProperties> weapons;
    // Starting weapon with which units spawn, or None
    static std::optional<int> startingWeapon;
    // Ammo for starting weapon given when unit spawns
    static int startingWeaponAmmo;
    // Max number of shield potions in unit's inventory
    static int maxShieldPotionsInInventory;
    // Amount of shield restored using one potion
    static double shieldPerPotion;
    // Time required to perform action of using shield potion
    static double shieldPotionUseTime;
    // List of properties of every sound type
    static std::vector<model::SoundProperties> sounds;
    // Sound type index when moving (starting with 0), or None
    static std::optional<int> stepsSoundTypeIndex;
    // Distance when steps sound will be 100% probability
    static double stepsSoundTravelDistance;
    // List of obstacles on the map
    static std::vector<model::Obstacle> obstacles;
};