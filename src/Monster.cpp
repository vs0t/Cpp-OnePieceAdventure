/**
 * @file Monster.cpp
 * @brief Implementation of the Monster class, representing enemy combatants in the game.
 *
 * The `Monster` class inherits from the `Combatant` class and represents enemies that the player can encounter and fight.
 * It initializes the monster with a name, health, and fight coefficient, inheriting the ability to fight from the `Combatant` class.
 *
 * **Methods**:
 * - `Monster(string name, int health, int fightCoefficient)`: Constructor to initialize the monster with a name, health, and fight coefficient. Inherits from `Combatant`.
 *
 * **Attributes**:
 * - Inherits attributes from `Combatant`: `_name`, `_health`, `_fightCoefficient`.
 *
 * @author Evan Aarons Wood
 * @version 1.0
 * @date 2024-12-06
 */


#include <Monster.hpp>

namespace chants
{
    Monster::Monster(string name, int health, int fightCoefficient) : Combatant(name, health, fightCoefficient)
    {
    }
}