#pragma once
#include <cstdlib> // For rand()
#include <ctime>   // For seeding random number generator
#include <iostream>
#include <stdint.h>
#include <string>

class Model {
private:
  std::string name;
  uint8_t modelStrength;
  uint8_t modelMove;
  uint8_t modelToughness;
  uint8_t modelSave = 5;
  uint8_t modelInvuln = 7;
  uint8_t modelFeelNoPain = 7;
  uint8_t modelWounds;
  uint8_t modelAttacks;
  uint8_t modelOC;

public:
  // Constructor
  Model(const std::string &newName, uint8_t newMove, uint8_t newToughness,
        uint8_t newSave, uint8_t newInvuln, uint8_t newFeelNoPain,
        uint8_t newWounds, uint8_t newAttacks, uint8_t newOC);
  Model();
  // Getters
  std::string getName() const;
  uint8_t getMove() const;
  uint8_t getToughness() const;
  uint8_t getSave() const;
  uint8_t getInvuln() const;
  uint8_t getFeelNoPain() const;
  uint8_t getWounds() const;
  uint8_t getAttacks() const;
  uint8_t getOC() const;
  uint8_t getModelCount() const;

  // Legacy, delete later
  uint8_t getStrength() const;

  // Methods
  void displayStats() const;
  bool updateModelCount();
};