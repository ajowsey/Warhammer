
#include "unitClass.h"
#include <cstdlib> // For rand()
#include <ctime>   // For seeding random number generator
#include <iostream>

// Constructor implementation
Unit::Unit(const std::string &newName, int newStrength, int newAgility)
    : name(newName), strength(newStrength), agility(newAgility) {}

// Getter implementations
std::string Unit::getName() const { return name; }
uint8_t Unit::getStrength() const { return strength; }
uint8_t Unit::getAgility() const { return agility; }

// Method implementation
void Unit::displayStats() const {
  std::cout << "Name: " << name << std::endl;
  std::cout << "Strength: " << strength << std::endl;
  std::cout << "Agility: " << agility << std::endl;
}