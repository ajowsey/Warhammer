#include "unit.h"
#include <iostream>
#include <numeric>
#include <stdexcept>

Unit::Unit(const std::string &name) : unitName(name) {}

void Unit::addModel(const Model &model) { models.push_back(model); }

void Unit::removeModel(size_t index) {
  if (index >= models.size()) {
    throw std::out_of_range("Model index out of range");
  }
  models.erase(models.begin() + index);
}

const Model &Unit::getModel(size_t index) const {
  if (index >= models.size()) {
    throw std::out_of_range("Model index out of range");
  }
  return models[index];
}

void Unit::displayUnit() const {
  std::cout << "\nUnit: " << unitName << "\n";
  std::cout << "Total Models: " << models.size() << "\n";
  std::cout << "Total Wounds: " << getTotalWounds() << "\n";
  std::cout << "Remaining Wounds: " << getRemainingWounds() << "\n";
  std::cout << "Unit Strength: " << getUnitStrength() << "\n";
  std::cout << "Below 50%: " << (isBelow_50_Percent() ? "Yes" : "No") << "\n\n";

  for (size_t i = 0; i < models.size(); ++i) {
    std::cout << "Model " << i + 1 << ":\n";
    models[i].displayStats();
    std::cout << "\n";
  }
}

int Unit::getTotalWounds() const {
  return std::accumulate(models.begin(), models.end(), 0,
                         [](int sum, const Model &model) {
                           return sum + model.get<Model::WOUNDS>();
                         });
}

int Unit::getRemainingWounds() const {
  // For now, just returns total wounds. In future, track damaged models
  return getTotalWounds();
}

int Unit::getUnitStrength() const {
  return std::accumulate(
      models.begin(), models.end(), 0,
      [](int sum, const Model &model) { return sum + model.get<Model::OC>(); });
}

bool Unit::isBelow_50_Percent() const {
  if (models.empty())
    return true;
  return getRemainingWounds() < (getTotalWounds() / 2);
}
