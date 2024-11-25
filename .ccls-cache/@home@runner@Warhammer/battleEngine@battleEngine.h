#pragma once
#include <functional>
#include "../unit.h"

// Type alias for dice roller function
using DiceRoller = std::function<int()>;

// Default dice roller function
inline int defaultD6() { 
    return rand() % 6 + 1; 
}

struct AttackResult {
    int successfulHits = 0;
    int successfulWounds = 0;
    int failedSaves = 0;
    int totalDamage = 0;
};

// Modified functions to accept a dice roller
bool rollToHit(int skill, int roll);
bool rollToWound(int attackingWeaponStrength, int defendingArmourToughness, int roll);
bool rollToSave(int save, int ap, int roll);

// New version that accepts a dice roller function
AttackResult attackRolls(int numAttacks, 
                        int attackerWeaponSkill,
                        int attackerWeaponStrength,
                        int attackerWeaponAp,
                        int attackerWeaponDamage, 
                        int targetToughness,
                        int targetSave,
                        DiceRoller diceRoller = defaultD6);


struct ShootingResult {
  int totalShots = 0;
  int modelsSlain = 0;
  int woundsDealt = 0;
  AttackResult attackResults;
};

// Function declarations
ShootingResult shootingPhase(const Unit &attackers, const Unit &defenders);