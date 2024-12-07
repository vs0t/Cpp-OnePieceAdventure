/**
 * @file Player.hpp
 * @brief Declaration of the Player class, representing the player character in the game.
 *
 * The `Player` class inherits from `Combatant` and represents the player in the game. It includes methods for managing
 * the player's inventory, interacting with assets, and attacking monsters. The player can collect items from nodes,
 * view and remove assets, and engage in combat with monsters.
 *
 * **Public Methods**:
 * - `Player(string name, int health, int fightCoefficient)`: Constructor to initialize the player with a name, health, and fight coefficient.
 * - `void AddAsset(Asset asset)`: Adds an asset to the player's inventory.
 * - `void ViewInventory()`: Displays the player's current inventory.
 * - `void RemoveAsset(const string& assetName)`: Removes an asset from the player's inventory.
 * - `void UseAsset(const string& assetName)`: Uses a specified asset from the inventory.
 * - `void CollectItems(Node& node)`: Collects assets from a given node and adds them to the player's inventory.
 * - `void AttackMonster(Monster& monster, Node& node)`: Attacks a specified monster using available assets.
 * - `const vector<Asset>& GetAssets() const`: Returns a reference to the player's list of assets.
 *
 * **Attributes**:
 * - `_assets`: A vector that stores the assets (items) the player has collected.
 *
 * @author Evan Aarons Wood
 * @version 1.0
 * @date 2024-12-06
 */


#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include "Combatant.hpp"
#include "Asset.hpp"
#include "Node.hpp"
#include "Monster.hpp"

using std::string;
using std::vector;

namespace chants
{
    class Player : public Combatant
    {
    public:
        Player(string name, int health, int fightCoefficient);
        void AddAsset(Asset asset);
        void ViewInventory();
        void RemoveAsset(const std::string& assetName);
        void UseAsset(const std::string& assetName);
        void CollectItems(Node& node);
        void AttackMonster(Monster& monster, Node& node); // Updated declaration
        const vector<Asset>& GetAssets() const;

    private:
        vector<Asset> _assets; // Store assets as objects
    };
}

#endif // PLAYER_HPP
