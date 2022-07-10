#include "RTConstants.hpp"

double RTConstants::ticksPerSecond;
// Starting number of units in each team
int RTConstants::teamSize;
// Initial zone radius
double RTConstants::initialZoneRadius;
// Speed of zone radius
double RTConstants::zoneSpeed;
// Damage dealt to units outside of the zone per second
double RTConstants::zoneDamagePerSecond;
// Unit spawning time
double RTConstants::spawnTime;
// Damage dealt to units trying to spawn in incorrect position per second
double RTConstants::spawnCollisionDamagePerSecond;
// Time required to perform looting actions (in seconds)
double RTConstants::lootingTime;
// Number of bot players (teams)
int RTConstants::botPlayers;
// Units' radius
double RTConstants::unitRadius;
// Max units' health
double RTConstants::unitHealth;
// Health automatically restored per second
double RTConstants::healthRegenerationPerSecond;
// Time until automatic health regeneration since last health damage (in seconds)
double RTConstants::healthRegenerationDelay;
// Max value of unit's shield
double RTConstants::maxShield;
// Initial value of unit's shield
double RTConstants::spawnShield;
// Initial number of extra lives for units
int RTConstants::extraLives;
// Zone radius after which respawning is disabled
double RTConstants::lastRespawnZoneRadius;
// Units' field of view without aiming (in degrees)
double RTConstants::fieldOfView;
// Units' view distance
double RTConstants::viewDistance;
// Whether units' view is blocked by obstacles
bool RTConstants::viewBlocking;
// Unit rotation speed without aiming (degrees per second)
double RTConstants::rotationSpeed;
// Units' movement speed while spawning
double RTConstants::spawnMovementSpeed;
// Max unit speed when walking forward
double RTConstants::maxUnitForwardSpeed;
// Max unit speed when walking backward
double RTConstants::maxUnitBackwardSpeed;
// Max unit acceleration
double RTConstants::unitAcceleration;
// Whether a unit can damage units of the same team
bool RTConstants::friendlyFire;
// Score given for killing enemy unit
double RTConstants::killScore;
// Score multiplier for damaging enemy units
double RTConstants::damageScoreMultiplier;
// Score given for every team killed before you
double RTConstants::scorePerPlace;
// List of properties of every weapon type
std::vector<model::WeaponProperties> RTConstants::weapons;
// Starting weapon with which units spawn, or None
std::optional<int> RTConstants::startingWeapon;
// Ammo for starting weapon given when unit spawns
int RTConstants::startingWeaponAmmo;
// Max number of shield potions in unit's inventory
int RTConstants::maxShieldPotionsInInventory;
// Amount of shield restored using one potion
double RTConstants::shieldPerPotion;
// Time required to perform action of using shield potion
double RTConstants::shieldPotionUseTime;
// List of properties of every sound type
std::vector<model::SoundProperties> RTConstants::sounds;
// Sound type index when moving (starting with 0), or None
std::optional<int> RTConstants::stepsSoundTypeIndex;
// Distance when steps sound will be 100% probability
double RTConstants::stepsSoundTravelDistance;
// List of obstacles on the map
std::vector<model::Obstacle> RTConstants::obstacles;