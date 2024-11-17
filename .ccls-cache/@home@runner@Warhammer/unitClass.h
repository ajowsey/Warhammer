#pragma once
#include <cstdlib> // For rand()
#include <ctime>   // For seeding random number generator
#include <iostream>
#include <stdint.h>

#include <string>
class Unit {
private:
  std::string name;
  uint8_t strength;
  uint8_t agility;
  uint8_t unitModeCount;
  uint8_t unitMove;
  uint8_t unitToughness;
  

public:
  // Constructor
  Unit(const std::string &newName, int newStrength, int newAgility);
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
