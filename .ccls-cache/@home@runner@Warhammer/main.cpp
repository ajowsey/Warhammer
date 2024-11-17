#include "battleEngine.h"
#include "unitClass.h"
#include <cstdlib> // For rand()
#include <ctime>   // For seeding random number generator
#include <iostream>

// Unit tests for rollToWound function
void runUnitTests() {
  // Seed the random number generator for consistent results during testing
  srand(42); // Fixed seed for predictable unit test results

  // Test case: Strength equals Toughness (roll needed >= 4)
  assert(rollToWound(4, 4, 0) == false);

  // Print confirmation if tests pass
  std::cout << "All unit tests passed!" << std::endl;
}

int main() {

  runUnitTests();

  int numAttacks = 5;
  int ws = 4;        // Hitting on a 4+
  int strength = 4;  // Strength of the weapon
  int ap = -1;       // Armor Penetration
  int damage = 2;    // Damage dealt per unsaved wound
  int toughness = 3; // Toughness of the target
  int save = 5;      // Save characteristic of the target

  attackRolls(numAttacks, ws, strength, ap, damage, toughness, save);

  Unit hero("Aragorn");
  hero.displayStats();
  return 0;
}
