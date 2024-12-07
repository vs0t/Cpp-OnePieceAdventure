/**
 * @file Monster.hpp
 * @brief Declaration of the Monster class, representing a combatant that is an enemy in the game.
 *
 * The `Monster` class inherits from the `Combatant` class and represents enemies that the player can encounter and fight.
 * It initializes the monster with its name, health, and fight coefficient, inheriting the ability to fight from the `Combatant` class.
 *
 * **Public Methods**:
 * - `Monster(string name, int health, int fightCoefficient)`: Constructor to initialize the monster with a name, health, and fight coefficient.
 *
 * **Attributes**:
 * - Inherits attributes from `Combatant`: `_name`, `_health`, `_fightCoefficient`.
 *
 * @author Evan Aarons Wood
 * @version 1.0
 * @date 2024-12-06
 */


#pragma once

#include <string>
#include <Combatant.hpp>

using namespace std;

namespace chants
{
    class Monster : public Combatant
    {
    public:
        Monster(string name, int health, int fightCoefficient);
    };
}