// modelClass.cpp
#include "model.h"
#include <iostream>

Model::Model(const std::string &newName, uint8_t newMove, uint8_t newToughness,
             uint8_t newSave, uint8_t newInvuln, uint8_t newFeelNoPain,
             uint8_t newWounds, uint8_t newAttacks, uint8_t newOC)
    : name(newName) {
  stats[MOVE] = newMove;
  stats[TOUGHNESS] = newToughness;
  stats[SAVE] = newSave;
  stats[INVULN] = newInvuln;
  stats[FEEL_NO_PAIN] = newFeelNoPain;
  stats[WOUNDS] = newWounds;
  stats[ATTACKS] = newAttacks;
  stats[OC] = newOC;
  stats[STRENGTH] = 0; // Deprecated
}

void Model::displayStats() const {
  std::cout << "Name: " << name << std::endl;
  for (size_t i = 0; i < STAT_COUNT; ++i) {
    std::cout << statNames[i] << ": " << static_cast<int>(stats[i])
              << std::endl;
  }

  if (selectedWeapon) {
    std::cout << "Selected Weapon: " << selectedWeapon->getName() << std::endl;
  }

  if (!availableWeapons.empty()) {
    std::cout << "Available Weapons:" << std::endl;
    for (size_t i = 0; i < availableWeapons.size(); ++i) {
      std::cout << "  " << i + 1 << ". " << availableWeapons[i].getName()
                << std::endl;
    }
  }
}

void Model::addAvailableWeapon(const Weapon &weapon) {
  availableWeapons.push_back(weapon);
  if (!selectedWeapon && !availableWeapons.empty()) {
    selectedWeapon = std::make_shared<Weapon>(availableWeapons[0]);
  }
}
void Model::selectWeapon(size_t index) {
    if (index >= availableWeapons.size()) {
        throw std::out_of_range("Weapon index out of range");
    }
    selectedWeapon = std::make_shared<Weapon>(availableWeapons[index]);
}
