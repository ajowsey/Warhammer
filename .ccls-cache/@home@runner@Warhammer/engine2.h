#pragma once

// Function to simulate a single D6 roll
int rollD6();
bool rollToHit(int skill);
bool rollToWound(int strength, int toughness);
bool rollToSave(int save, int ap);

void battleSimulation(int numAttacks, int ws, int strength, int ap, int damage,
                      int toughness, int save);