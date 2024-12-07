/**
 * @file Asset.hpp
 * @brief Declaration of the Asset class, representing items in the game.
 *
 * The `Asset` class defines the properties and behavior of in-game items that the player can collect and use. 
 * These items can have various attributes, such as a name, description, value, and whether they are offensive (weapons).
 *
 * **Public Methods**:
 * - `Asset(string name, string message, int value, bool isOffensive)`: Constructor to initialize the asset with its attributes.
 * - `string GetName() const`: Returns the name of the asset.
 * - `string GetMessage() const`: Returns the description or message associated with the asset.
 * - `int GetValue() const`: Returns the value of the asset.
 * - `bool isOffensive() const`: Checks if the asset is offensive (e.g., a weapon).
 *
 * **Attributes**:
 * - `_name`: The name of the asset.
 * - `_message`: A description or message about the asset.
 * - `_value`: The value associated with the asset (e.g., its effectiveness or cost).
 * - `_isOffensive`: Whether the asset is offensive (used in combat).
 * - `hasBeenUsed`: Tracks whether the asset has been used.
 *
 * @author Evan Aarons-Wood
 * @version 1.0
 * @date 2024-12-06
 */


#pragma once

#include <string>

using namespace std;

namespace chants
{
    class Asset
    {
    private:
        string _name;
        string _message;
        int _value;
        bool _isOffensive;

    public:
        bool hasBeenUsed;
        Asset(string name, string message, int value, bool isOffensive);
        string GetName() const;
        string GetMessage() const;
        int GetValue() const;
        bool isOffensive() const;
    };
}
