
#include "unitClass.h"
#include <cstdlib> // For rand()
#include <ctime>   // For seeding random number generator
#include <iostream>

// Constructor implementation
Unit::Unit(const std::string &newName, int newStrength, int newAgility)
    : name(newName), strength(newStrength), agility(newAgility) {}

// Getter implementations
std::string Unit::getName() const { return name; }
uint8_t Unit::getMove() const { return unitMove; }
uint8_t Unit::getToughness() const { return unitToughness; }
uint8_t Unit::getSave() const { return unitSave; }
uint8_t Unit::getWounds() const { return unitWounds; }
uint8_t Unit::getAttacks() const { return unitAttacks; }
uint8_t Unit::getOC() const { return unitOC; }
uint8_t Unit::getModelCount() const { return unitModelCount; }
uint8_t Unit::getStrength() const { return strength; }
uint8_t Unit::getAgility() const { return agility; }

// Method implementation
void Unit::displayStats() const {
  std::cout << "Name: " << name << std::endl;
  std::cout << "Strength: " << strength << std::endl;
  std::cout << "Agility: " << agility << std::endl;
}