#include "model.h"
#include <cstdlib> // For rand()
#include <ctime>   // For seeding random number generator
#include <iostream>
#include <stdint.h>
#include <string>

// Constructor implementation
Model::Model(const std::string &newName, uint8_t newMove, uint8_t newToughness,
             uint8_t newSave, uint8_t newInvuln, uint8_t newFeelNoPain,
             uint8_t newWounds, uint8_t newAttacks, uint8_t newOC)
    : name(newName), modelMove(newMove), modelToughness(newToughness),
      modelSave(newSave), modelInvuln(newInvuln),
      modelFeelNoPain(newFeelNoPain), modelWounds(newWounds),
      modelAttacks(newAttacks), modelOC(newOC) {}

Model::Model(){};

// Getter implementations
std::string Model::getName() const { return name; }
uint8_t Model::getMove() const { return modelMove; }
uint8_t Model::getToughness() const { return modelToughness; }
uint8_t Model::getSave() const { return modelSave; }
uint8_t Model::getInvuln() const { return modelInvuln; }
uint8_t Model::getFeelNoPain() const { return modelFeelNoPain; }
uint8_t Model::getWounds() const { return modelWounds; }
uint8_t Model::getAttacks() const { return modelAttacks; }
uint8_t Model::getOC() const { return modelOC; }

// Depreciate this once the weapons are implemented
uint8_t Model::getStrength() const { return modelStrength; }

// Method implementation
void Model::displayStats() const {
  std::cout << "Name: " << name << std::endl;
  std::cout << "Movement: " << modelMove << std::endl;
  std::cout << "Toughness: " << modelToughness << std::endl;
  std::cout << "Save: " << modelSave << std::endl;
  std::cout << "Wounds: " << modelWounds << std::endl;
  std::cout << "Attacks: " << modelAttacks << std::endl;
  std::cout << "OC: " << modelOC << std::endl;
  std::cout << "Strength: " << modelStrength << std::endl;
}