#pragma once
#include "model.h"
#include <memory>
#include <string>
#include <vector>

class Unit {
public:
  // Constructor
  Unit(const std::string &unitName = "");

  // Add/Remove models
  void addModel(const Model &model);
  void removeModel(size_t index);

  // Getters
  size_t getSize() const { return models.size(); }
  std::string getName() const { return unitName; }
  const Model &getModel(size_t index) const;

  // Unit-wide operations
  void displayUnit() const;
  int getTotalWounds() const;
  int getRemainingWounds() const;
  int getUnitStrength() const; // Total number of models × their individual OC

  // Utility functions
  bool isDestroyed() const { return models.empty(); }
  bool isBelow_50_Percent() const;

  // Unit coherency check (models must be within 2" of another model)
  bool hasCoherency() const { return true; } // Placeholder for now

private:
  std::string unitName;
  std::vector<Model> models;
};

