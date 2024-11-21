#pragma once
#include <string>

class Weapon {
public:
    Weapon(const std::string& name = "", 
           int attacks = 1,
           int skill = 4,
           int strength = 4,
           int ap = 0,
           int damage = 1)
        : weaponName(name)
        , attacks(attacks)
        , skill(skill)
        , strength(strength)
        , ap(ap)
        , damage(damage) {}

    std::string getName() const { return weaponName; }
    int getAttacks() const { return attacks; }
    int getSkill() const { return skill; }
    int getStrength() const { return strength; }
    int getAP() const { return ap; }
    int getDamage() const { return damage; }

private:
    std::string weaponName;
    int attacks;
    int skill;
    int strength;
    int ap;
    int damage;
};