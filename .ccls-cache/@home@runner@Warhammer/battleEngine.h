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

// Function to simulate a single D6 roll
int rollD6();
bool rollToHit(int skill);
bool rollToWound(int strength, int toughness, int roll);
bool rollToSave(int save, int ap);

void attackRolls(int numAttacks, int ws, int strength, int ap, int damage,
                 int toughness, int save);

// Function declarations (from original code)
