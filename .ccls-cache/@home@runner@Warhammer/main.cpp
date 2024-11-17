#include "battleEngine.h"
#include "unitClass.h"
#include <cstdlib> // For rand()
#include <ctime>   // For seeding random number generator
#include <iostream>

// Unit tests for rollToWound function
void runUnitTests() {
  // Test double strength cases (2+)
  assert(rollToWound(8, 4, 2) == true);  // S=2×T
  assert(rollToWound(10, 4, 2) == true); // S>2×T
  assert(rollToWound(8, 4, 1) == false);

  // Test half strength cases (6+)
  assert(rollToWound(2, 5, 6) == true); // S≤T/2
  assert(rollToWound(2, 5, 5) == false);

  // Test greater strength cases (3+)
  assert(rollToWound(5, 4, 3) == true); // S>T
  assert(rollToWound(5, 4, 2) == false);

  // Test equal strength cases (4+)
  assert(rollToWound(4, 4, 4) == true); // S=T
  assert(rollToWound(4, 4, 3) == false);

  // Test lesser strength cases (5+)
  assert(rollToWound(3, 4, 5) == true); // S<T
  assert(rollToWound(3, 4, 4) == false);

  std::cout << "All unit tests passed!" << std::endl;
}

int main() {

  runUnitTests();

  int numAttacks = 5;
  int attackerWeaponSkill = 4;    // Hitting on a 4+
  int attackerWeaponStrength = 4; // Strength of the weapon
  int attackerWeaponAp = -1;      // Armor Penetration
  int attackerWeaponDamage = 2;   // Damage dealt per unsaved wound
  int targetToughness = 3;        // Toughness of the target
  int targetSave = 5;             // Save characteristic of the target

  attackRolls(numAttacks, attackerWeaponSkill, attackerWeaponStrength,
              attackerWeaponAp, attackerWeaponDamage, targetToughness,
              targetSave);

  Unit hero("Aragorn");
  hero.displayStats();
  return 0;
}
