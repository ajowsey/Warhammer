#pragma once
#include "weapon.h"
#include <array>
#include <memory>
#include <string>
#include <vector>

class Model {
public:
  enum StatType {
    MOVE,
    TOUGHNESS,
    SAVE,
    INVULN,
    FEEL_NO_PAIN,
    WOUNDS,
    ATTACKS,
    OC,
    STRENGTH, // Deprecated
    STAT_COUNT
  };

  Model(const std::string &newName = "", uint8_t newMove = 0,
        uint8_t newToughness = 0, uint8_t newSave = 0, uint8_t newInvuln = 0,
        uint8_t newFeelNoPain = 0, uint8_t newWounds = 0,
        uint8_t newAttacks = 0, uint8_t newOC = 0);

  template <StatType T> uint8_t get() const { return stats[T]; }
  std::string getName() const { return name; }
  void displayStats() const;
  template <StatType T> void set(uint8_t value) { stats[T] = value; }
  void setName(const std::string &newName) { name = newName; }

  void addAvailableWeapon(const Weapon &weapon);
  void selectWeapon(size_t index);
  const Weapon &getSelectedWeapon() const { return *selectedWeapon; }
  const std::vector<Weapon> &getAvailableWeapons() const {
    return availableWeapons;
  }

private:
  std::string name;
  std::array<uint8_t, STAT_COUNT> stats;
  static constexpr const char *statNames[] = {
      "Movement",          "Toughness",         "Save",
      "Invulnerable Save", "Feel No Pain",      "Wounds",
      "Attacks",           "Objective Control", "Strength"};

  std::vector<Weapon> availableWeapons;
  std::shared_ptr<Weapon> selectedWeapon;
};
