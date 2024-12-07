/**
 * @file Asset.cpp
 * @brief Implementation of the Asset class, representing in-game items.
 *
 * The `Asset` class defines the properties and behaviors of items in the game. These items can be collected by the player
 * and used in various ways. Assets have attributes like a name, description, value, and a flag indicating whether they are 
 * offensive (weapons) or not.
 *
 * **Methods**:
 * - `Asset(string name, string message, int value, bool isOffensive)`: Constructor to initialize an asset with its name, description, value, and whether it is offensive.
 * - `string GetName() const`: Returns the name of the asset.
 * - `string GetMessage() const`: Returns the description or message associated with the asset.
 * - `int GetValue() const`: Returns the value of the asset.
 * - `bool isOffensive() const`: Returns whether the asset is offensive (e.g., a weapon).
 *
 * **Attributes**:
 * - `_name`: The name of the asset.
 * - `_message`: The description or message about the asset.
 * - `_value`: The value or effectiveness of the asset.
 * - `_isOffensive`: Whether the asset is offensive (used for combat).
 * - `hasBeenUsed`: Tracks if the asset has been used.
 *
 * @author Evan Aarons Wood
 * @version 1.0
 * @date 2024-12-06
 */


#include "Asset.hpp"

namespace chants
{
    Asset::Asset(string name, string message, int value, bool isOffensive)
        : _name(name), _message(message), _value(value), _isOffensive(isOffensive), hasBeenUsed(false) {}

    string Asset::GetName() const
    {
        return _name;
    }

    string Asset::GetMessage() const
    {
        return _message;
    }

    int Asset::GetValue() const
    {
        return _value;
    }

    bool Asset::isOffensive() const
    {
        return _isOffensive;
    }
}
