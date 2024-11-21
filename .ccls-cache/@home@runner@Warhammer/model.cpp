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
    if (i != STRENGTH) { // Skip deprecated strength stat
      std::cout << statNames[i] << ": " << static_cast<int>(stats[i])
                << std::endl;
    }
  }
}
