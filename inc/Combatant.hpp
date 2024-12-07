/**
 * @file Combatant.hpp
 * @brief Declaration of the Combatant class, representing characters that can engage in combat.
 *
 * The `Combatant` class defines the properties and behaviors of characters in the game that can participate in combat,
 * including the ability to fight and track health. This class serves as the base class for both players and monsters.
 *
 * **Public Methods**:
 * - `Combatant(string name, int health, int coefficient)`: Constructor to initialize the combatant with a name, health, and fight coefficient.
 * - `int Fight()`: Calculates and returns the combatant's attack value based on their fight coefficient.
 * - `string GetName()`: Returns the name of the combatant.
 * - `int GetHealth()`: Returns the health of the combatant.
 *
 * **Attributes**:
 * - `_name`: The name of the combatant.
 * - `_health`: The health of the combatant, representing their vitality in combat.
 * - `_fightCoefficient`: A coefficient that influences the combatant's attack value.
 *
 * @author Evan Aarons Wood
 * @version 1.0
 * @date 2024-12-06
 */


#pragma once
#include <string>
using namespace std;

namespace chants
{
    class Combatant
    {
    protected:
        string _name;
        int _health;
        int _fightCoefficient;

    public:
        Combatant(string name, int health, int coefficient);
        int Fight();
        string GetName();
        int GetHealth();
    };
}