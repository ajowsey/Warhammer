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
    STAT_COUNT
  };

  Model(const std::string &newName = "", uint8_t newMove = 0,
        uint8_t newToughness = 0, uint8_t newSave = 0, uint8_t newInvuln = 0,
        uint8_t newFeelNoPain = 0, uint8_t newWounds = 0,
        uint8_t newAttacks = 0, uint8_t newOC = 0);

  void addAvailableWeapon(const Weapon &weapon);
  void selectWeapon(size_t index);
  const Weapon &getSelectedWeapon() const { return *selectedWeapon; }
  const std::vector<Weapon> &getAvailableWeapons() const {
    return availableWeapons;
  }

  template <StatType T> uint8_t get() const { return stats[T]; }

  std::string getName() const { return name; }
  void displayStats() const;

private:
  std::string name;
  std::array<uint8_t, STAT_COUNT> stats;
  std::vector<Weapon> availableWeapons;
  std::shared_ptr<Weapon> selectedWeapon;
  static constexpr const char *statNames[] = {
      "Movement",     "Toughness", "Save",    "Invulnerable Save",
      "Feel No Pain", "Wounds",    "Attacks", "Objective Control"};
};