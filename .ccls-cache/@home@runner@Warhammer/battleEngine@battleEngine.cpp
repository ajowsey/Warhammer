#include "battleEngine.h"
#include "../weapon.h"
#include <cassert> // For unit testing
#include <cstdlib> // For rand()
#include <ctime>   // For seeding random number generator
#include <iostream>


// Function to check a hit based on Weapon Skill (WS) or Ballistic Skill (BS)
bool rollToHit(int skill, int roll) { return roll >= skill; }

bool rollToWound(int attackingWeaponStrength, int defendingArmourToughness,
                 int roll) {
  int woundRequirement;

  // Check double strength (2+ to wound)
  if (attackingWeaponStrength >= defendingArmourToughness * 2) {
    woundRequirement = 2;
  }
  // Check half strength (6+ to wound)
  else if (attackingWeaponStrength * 2 <= defendingArmourToughness) {
    woundRequirement = 6;
  }
  // Check greater strength (3+ to wound)
  else if (attackingWeaponStrength > defendingArmourToughness) {
    woundRequirement = 3;
  }
  // Check equal strength (4+ to wound)
  else if (attackingWeaponStrength == defendingArmourToughness) {
    woundRequirement = 4;
  }
  // Check lesser strength (5+ to wound)
  else { // attackingWeaponStrength < defendingArmourToughness
    woundRequirement = 5;
  }

  return roll >= woundRequirement;
}

// Function to check a save based on Armor Save (SV) and Armor Penetration (AP)
bool rollToSave(int save, int ap, int roll) { return roll >= (save - ap); }

AttackResult attackRolls(int numAttacks, int attackerWeaponSkill,
                         int attackerWeaponStrength, int attackerWeaponAp,
                         int attackerWeaponDamage, int targetToughness,
                         int targetSave, DiceRoller diceRoller) {
  AttackResult results;

  for (int i = 0; i < numAttacks; i++) {
    // Step 1: Hit roll
    int hitRoll = diceRoller();
    std::cout << "Hit Roll: " << hitRoll << std::endl;
    if (!rollToHit(attackerWeaponSkill, hitRoll)) {
      std::cout << "Missed!" << std::endl;
      continue;
    }
    results.successfulHits++;
    std::cout << "Hit!" << std::endl;

    // Step 2: Wound roll
    int woundRoll = diceRoller();
    std::cout << "Wound Roll: " << woundRoll << std::endl;
    if (!rollToWound(attackerWeaponStrength, targetToughness, woundRoll)) {
      std::cout << "Wound failed!" << std::endl;
      continue;
    }
    results.successfulWounds++;
    std::cout << "Wound successful!" << std::endl;

    // Step 3: Save roll
    int saveRoll = diceRoller();
    std::cout << "Save Roll: " << saveRoll << std::endl;
    if (rollToSave(targetSave, attackerWeaponAp, saveRoll)) {
      std::cout << "Save Successful!" << std::endl;
      continue;
    }
    results.failedSaves++;
    std::cout << "Save failed!" << std::endl;

    // Apply damage
    results.totalDamage += attackerWeaponDamage;
    std::cout << "Damage applied: " << attackerWeaponDamage << std::endl;
  }

  return results;
}

ShootingResult shootingPhase(const Unit &attackers, const Unit &defenders) {

  ShootingResult result;

  // Go through each model in the attacking unit
  for (size_t i = 0; i < attackers.getSize(); ++i) {
    const Model &attacker = attackers.getModel(i);
    const Weapon &weapon = attacker.getSelectedWeapon();

    std::cout << "==========================================" << std::endl;
    std::cout << attacker.getName() << " " << i + 1
              << ": with Weapon: " << weapon.getName() << std::endl;

    // Get defender's stats (assuming uniform unit for simplicity)
    const Model &defender = defenders.getModel(0);
    int defenderToughness = defender.get<Model::TOUGHNESS>();
    int defenderSave = defender.get<Model::SAVE>();

    // Perform attack rolls for this model's weapon
    AttackResult modelResult = attackRolls(
        weapon.getAttacks(), weapon.getSkill(), weapon.getStrength(),
        weapon.getAP(), weapon.getDamage(), defenderToughness, defenderSave);

    // Accumulate results
    result.totalShots += weapon.getAttacks();
    result.attackResults.successfulHits += modelResult.successfulHits;
    result.attackResults.successfulWounds += modelResult.successfulWounds;
    result.attackResults.failedSaves += modelResult.failedSaves;
    result.attackResults.totalDamage += modelResult.totalDamage;
    std::cout << attacker.getName() << " done. " << std::endl;
  }

  // Calculate total effect
  result.woundsDealt = result.attackResults.totalDamage;
  result.modelsSlain =
      result.woundsDealt / defenders.getModel(0).get<Model::WOUNDS>();

  return result;
}