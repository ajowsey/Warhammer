#include "battleEngine/battleEngine.h"
#include "unit.h"
#include <assert.h>
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
  Weapon boltRifle("Bolt Rifle", 1, 3, 4, 0, 1);
  Weapon plasmaPistol("Plasma Pistol", 1, 3, 7, -3, 1);

  Model scoutTemplate("Scout", 6, 4, 4, 0, 0, 1, 1, 1);
  scoutTemplate.addAvailableWeapon(boltRifle);
  scoutTemplate.addAvailableWeapon(plasmaPistol);
  scoutTemplate.selectWeapon(0); // Select bolt rifle

  Model scoutSergeant = scoutTemplate;
  scoutSergeant.selectWeapon(1); // Select plasma pistol

  Unit scoutSquad("Scout Squad");
  scoutSquad.addModel(scoutSergeant); // Add sergeant with plasma pistol
  for (int i = 0; i < 4; i++) {
    scoutSquad.addModel(scoutTemplate);
  }
  // scoutSquad.displayUnit();

  Weapon multimelta("Multi-melta", 2, 3, 8, -4, 6);
  Model hellbruteModel("Hellbrute", 6, 7, 2, 0, 0, 8, 4, 3);
  hellbruteModel.addAvailableWeapon(multimelta);
  hellbruteModel.selectWeapon(0);

  Unit hellbrute("Hellbrute");
  hellbrute.addModel(hellbruteModel);
  // hellbrute.displayUnit();

  ShootingResult result = shootingPhase(scoutSquad, hellbrute);

  std::cout << "==========================================" << std::endl;
  std::cout << "Shooting Phase Results:" << std::endl;
  std::cout << "Total Shots: " << result.totalShots << std::endl;
  std::cout << "Wounds Dealt: " << result.woundsDealt << std::endl;
  std::cout << "Models Slain: " << result.modelsSlain << std::endl;

  

  return 0;
}