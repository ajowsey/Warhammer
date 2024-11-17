#pragma once
#include "model.h"
#include <cstdlib> // For rand()
#include <ctime>   // For seeding random number generator
#include <iostream>
#include <stdint.h>

#include <string>
class Unit : private Model {
private:
  std::string name;

public:
  uint8_t unitModelCount;
  uint8_t unitMove;
  uint8_t unitToughness;
  uint8_t unitSaveModifier = 0;
  uint8_t unitInvulnModifier = 0;
  uint8_t unitFeelNoPainModifier = 0;
  uint8_t unitWounds;
  uint8_t unitAttacks;
  uint8_t unitOC;

  // Constructor
  Unit(const std::string &newName);
  // Getters
  std::string getName() const;
  uint8_t getMove() const;
  uint8_t getToughness() const;
  uint8_t getSave() const;
  uint8_t getWounds() const;
  uint8_t getAttacks() const;
  uint8_t getOC() const;
  uint8_t getModelCount() const;

  // Legacy, delete later
  uint8_t getStrength() const;
  uint8_t getAgility() const;

  // Methods
  void displayStats() const;
  bool updateModelCount();
};
