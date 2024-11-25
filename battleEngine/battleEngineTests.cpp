// Example test file: battleEngineTests.cpp
#include "battleEngine.h"
#include <cassert>
#include <iostream>
#include <queue>
#include <stdexcept>
#include <vector>

class MockDiceRoller {
public:
  explicit MockDiceRoller(std::vector<int> rolls) : rolls(rolls) {}

  int operator()() {
    if (currentRoll >= rolls.size()) {
      throw std::runtime_error("Not enough mock dice rolls provided");
    }
    return rolls[currentRoll++];
  }

private:
  std::vector<int> rolls;
  size_t currentRoll = 0;
};

void testAttackRolls() {
  // Test case 1: All rolls succeed
  {
    // Hit on 3+, Wound on 4+, Save on 3+
    std::vector<int> rolls = {
        5, // Hit roll (≥3, success)
        5, // Wound roll (≥4, success)
        2  // Save roll (<3, fail)
    };

    MockDiceRoller diceRoller(rolls);

    AttackResult result = attackRolls(1, // 1 attack
                                      3, // WS/BS 3+
                                      4, // Strength 4
                                      0, // AP 0
                                      1, // Damage 1
                                      4, // Toughness 4
                                      3, // Save 3+
                                      diceRoller);

    assert(result.successfulHits == 1);
    assert(result.successfulWounds == 1);
    assert(result.failedSaves == 1);
    assert(result.totalDamage == 1);
  }

  // Test case 2: Failed hit roll
  {
    std::vector<int> rolls = {
        2}; // Hit roll fails, no wound or save rolls needed

    MockDiceRoller diceRoller(rolls);

    AttackResult result = attackRolls(1, // 1 attack
                                      3, // WS/BS 3+
                                      4, // Strength 4
                                      0, // AP 0
                                      1, // Damage 1
                                      4, // Toughness 4
                                      3, // Save 3+
                                      diceRoller);

    assert(result.successfulHits == 0);
    assert(result.successfulWounds == 0);
    assert(result.failedSaves == 0);
    assert(result.totalDamage == 0);
  }

  // Test case 3: Multiple attacks
  {
    std::vector<int> rolls = {
        6, 6, 2, // First attack: hit, wound, fail save
        2,       // Second attack: miss
        4, 3,    // Third attack: hit, fail wound
        5, 5, 5  // Fourth attack: hit, wound, make save
    };

    MockDiceRoller diceRoller(rolls);

    AttackResult result = attackRolls(4, // 4 attacks
                                      3, // WS/BS 3+
                                      4, // Strength 4
                                      0, // AP 0
                                      2, // Damage 2
                                      4, // Toughness 4
                                      3, // Save 3+
                                      diceRoller);

    assert(result.successfulHits == 3);
    assert(result.successfulWounds == 2);
    assert(result.failedSaves == 1);
    assert(result.totalDamage == 2);
  }

  std::cout << "All attack roll tests passed!" << std::endl;
}

int testMain() {
  testAttackRolls();
  return 0;
}