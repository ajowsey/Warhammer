#pragma once
#include "unit.h"

struct AttackResult {
  int successfulHits = 0;
  int successfulWounds = 0;
  int failedSaves = 0;
  int totalDamage = 0;
};

struct ShootingResult {
  int totalShots = 0;
  int modelsSlain = 0;
  int woundsDealt = 0;
  AttackResult attackResults;
};

// Function declarations
int rollD6();
bool rollToHit(int skill, int roll);
bool rollToWound(int attackingWeaponStrength, int defendingArmourToughness,
                 int roll);
bool rollToSave(int save, int ap, int roll);
AttackResult attackRolls(int numAttacks, int attackerWeaponSkill,
                         int attackerWeaponStrength, int attackerWeaponAp,
                         int attackerWeaponDamage, int targetToughness,
                         int targetSave);
ShootingResult shootingPhase(const Unit &attackers, const Unit &defenders);