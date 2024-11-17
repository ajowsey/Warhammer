#include "unitClass.h"
#include <cstdlib> // For rand()
#include <ctime>   // For seeding random number generator
#include <iostream>

// Function to simulate a single D6 roll
int rollD6() { return rand() % 6 + 1; }

// Function to check a hit based on Weapon Skill (WS) or Ballistic Skill (BS)
bool rollToHit(int skill) { return rollD6() >= skill; }

// Function to check a wound based on Strength (S) and Toughness (T)
bool rollToWound(int strength, int toughness) {
  int roll = rollD6();
  if (strength >= 2 * toughness)
    return roll >= 2;
  if (strength > toughness)
    return roll >= 3;
  if (strength == toughness)
    return roll >= 4;
  if (strength < toughness)
    return roll >= 5;
  return roll >= 6; // strength <= T / 2
}

// Function to check a save based on Armor Save (SV) and Armor Penetration (AP)
bool rollToSave(int save, int ap) { return rollD6() >= (save - ap); }

// Main battle function
void battleSimulation(int numAttacks, int ws, int strength, int ap, int damage,
                      int toughness, int save) {
  srand(time(0)); // Seed random number generator
  int successfulWounds = 0;

  // Roll for hits
  for (int i = 0; i < numAttacks; i++) {
    if (rollToHit(ws)) {
      // Roll to wound
      if (rollToWound(strength, toughness)) {
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

int main() {

  int numAttacks = 5;
  int ws = 4;        // Hitting on a 4+
  int strength = 4;  // Strength of the weapon
  int ap = -1;       // Armor Penetration
  int damage = 2;    // Damage dealt per unsaved wound
  int toughness = 3; // Toughness of the target
  int save = 5;      // Save characteristic of the target

  battleSimulation(numAttacks, ws, strength, ap, damage, toughness, save);

  Unit hero("Aragorn", 10, 8);
  hero.displayStats();
  return 0;
}
