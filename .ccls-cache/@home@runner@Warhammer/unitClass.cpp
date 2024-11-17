
#include "unitClass.h"
#include <cstdlib> // For rand()
#include <ctime>   // For seeding random number generator
#include <iostream>

// Constructor implementation
Unit::Unit(const std::string &newName) : name(newName) {}

// Getter implementations
std::string Unit::getName() const { return name; }
uint8_t Unit::getMove() const { return unitMove; }
uint8_t Unit::getWounds() const { return unitWounds; }
uint8_t Unit::getAttacks() const { return unitAttacks; }
uint8_t Unit::getOC() const { return unitOC; }
uint8_t Unit::getModelCount() const { return unitModelCount; }

// Method implementation
void Unit::displayStats() const {
  std::cout << "Name: " << name << std::endl;
  std::cout << "Wounds: " << unitWounds << std::endl;
}