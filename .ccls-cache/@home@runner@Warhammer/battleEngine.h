#pragma once
#include "unitClass.h"
#include <cassert>
#include <iostream>

// Constants for wound roll requirements
const int STRENGTH_WOUND_DIFF_2_PLUS = 2;       // S >= T+2
const int STRENGTH_WOUND_DIFF_1 = 3;            // S = T+1
const int STRENGTH_WOUND_DIFF_0 = 4;            // S = T
const int STRENGTH_WOUND_DIFF_NEG_1 = 5;        // S = T-1
const int STRENGTH_WOUND_DIFF_HALF_OR_LESS = 6; // S <= T/2eam>

struct AttackResult {
    int successfulHits = 0;
    int successfulWounds = 0;
    int failedSaves = 0;
    int totalDamage = 0;
};

// Function to simulate a single D6 roll
int rollD6();
bool rollToHit(int skill, int roll);
bool rollToWound(int attackingWeaponStrength, int defendingArmourToughness,
                 int roll);
bool rollToSave(int save, int ap, int roll);


AttackResult attackRolls(int numAttacks, int attackerWeaponSkill,
                                  int attackerWeaponStrength,
                                  int attackerWeaponAp,
                                  int attackerWeaponDamage, int targetToughness,
                                  int targetSave);