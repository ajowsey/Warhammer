#include <cassert> // For unit testing
#include <cstdlib> // For rand()
#include <ctime>   // For seeding random number generator
#include <iostream>

// Function to simulate a single D6 roll
int rollD6() { return rand() % 6 + 1; }

// Function to check a hit based on Weapon Skill (WS) or Ballistic Skill (BS)
bool rollToHit(int skill) { return rollD6() >= skill; }

// Function to check a wound based on Strength (S) and Toughness (T)
bool rollToWound(int strength, int toughness, int roll) {
  int woundRequirement;

  switch (strength - toughness) {
  case 0:
    woundRequirement = 4;
    break;
  case 1:
    woundRequirement = 3;
    break;
  case 2:
  case 3:
  case 4:
  case 5:
    woundRequirement = 2;
    break;
  case -1:
    woundRequirement = 5;
    break;
  default:
    woundRequirement = (strength < toughness) ? 6 : 2;
    break;
  }
  return roll >= woundRequirement;
}

// Function to check a save based on Armor Save (SV) and Armor Penetration (AP)
bool rollToSave(int save, int ap) { return rollD6() >= (save - ap); }

// Main battle function
void attackRolls(int numAttacks, int ws, int strength, int ap, int damage,
                 int toughness, int save) {
  srand(time(0)); // Seed random number generator

  int successfulWounds = 0;

  // Roll for hits
  for (int i = 0; i < numAttacks; i++) {
    if (rollToHit(ws)) {
      // Roll to wound
      if (rollToWound(strength, toughness, rollD6())) {
        // Roll for saving throw
        if (!rollToSave(save, ap)) {
          // Defender failed the save, apply damage
          std::cout << "Hit! Damage dealt: " << damage << "\n";
          successfulWounds++;
        } else {
          std::cout << "Save successful!\n";
        }
      } else {
        std::cout << "Failed to wound.\n";
      }
    } else {
      std::cout << "Missed.\n";
    }
  }

  std::cout << "Total successful wounds: " << successfulWounds << "\n";
}
