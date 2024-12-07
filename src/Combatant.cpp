/**
 * @file Combatant.cpp
 * @brief Implementation of the Combatant class, representing characters that can engage in combat.
 *
 * The `Combatant` class defines the properties and behaviors of characters in the game that can participate in combat.
 * This includes the ability to calculate a fight value based on a given fight coefficient, as well as methods for retrieving
 * the combatant's name and health.
 *
 * **Methods**:
 * - `Combatant(string name, int health, int fightCoefficient)`: Constructor to initialize the combatant with a name, health, and fight coefficient.
 * - `string GetName()`: Returns the name of the combatant.
 * - `int GetHealth()`: Returns the health of the combatant.
 * - `int Fight()`: Calculates and returns the combatant's fight value based on the fight coefficient. It simulates multiple attack values and returns the average.
 *
 * **Attributes**:
 * - `_name`: The name of the combatant.
 * - `_health`: The health of the combatant, representing their vitality.
 * - `_fightCoefficient`: A coefficient that influences the combatant's attack value.
 *
 * @author Evan Aarons Wood
 * @version 1.0
 * @date 2024-12-06
 */


#include <Combatant.hpp>
#include <time.h>
using namespace std;

namespace chants
{
    Combatant::Combatant(string name, int health, int fightCoefficient)
    {
        _name = name;
        _health = health;
        _fightCoefficient = fightCoefficient;
    }

    string Combatant::GetName()
    {
        return _name;
    }

    int Combatant::GetHealth()
    {
        return _health;
    }

    /// @brief Average fight value over several interations
    /// @return
    int Combatant::Fight()
    {
        int subTotal = 0;
        srand(time(nullptr));
        for (int i = 0; i < _fightCoefficient; i++)
        {
            subTotal += rand() % _fightCoefficient;
        }
        float Total = subTotal / _fightCoefficient;
        return (int)Total;
    }
}
