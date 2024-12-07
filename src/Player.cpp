/**
 * @file Player.cpp
 * @brief Implementation of the Player class, representing the player character in the game.
 *
 * The `Player` class inherits from `Combatant` and defines the player's actions in the game, including managing the inventory,
 * using assets, attacking monsters, and collecting items. The player can interact with the world by acquiring assets, using 
 * weapons, and engaging in combat with enemies.
 *
 * **Methods**:
 * - `Player(string name, int health, int fightCoefficient)`: Constructor to initialize the player with a name, health, and fight coefficient.
 * - `void AddAsset(Asset asset)`: Adds an asset to the player's inventory, ensuring no duplicates.
 * - `void ViewInventory()`: Displays the player's current inventory.
 * - `void RemoveAsset(const string& assetName)`: Removes an asset from the player's inventory by name.
 * - `void UseAsset(const string& assetName)`: Marks an asset as used by the player.
 * - `void CollectItems(Node& node)`: Collects assets from a given node and adds them to the player's inventory.
 * - `void AttackMonster(Monster& monster, Node& node)`: Attacks a specified monster using the available assets.
 * - `const vector<Asset>& GetAssets() const`: Returns the player's list of assets.
 *
 * **Attributes**:
 * - `_assets`: A vector that stores the assets (items) the player has collected.
 *
 * @author Evan Aarons Wood
 * @version 1.0
 * @date 2024-12-06
 */


#include <algorithm>
#include <iostream>
#include "Player.hpp"

namespace chants
{
    Player::Player(string name, int health, int fightCoefficient)
        : Combatant(name, health, fightCoefficient) {}

    void Player::AddAsset(Asset asset)
    {
        // Check for duplicates before adding
        auto it = std::find_if(_assets.begin(), _assets.end(),
            [&asset](const Asset& a) { return a.GetName() == asset.GetName(); });

        if (it == _assets.end()) {
            _assets.push_back(asset);
        }
    }

    void Player::ViewInventory()
    {
        std::cout << "Inventory:" << std::endl;
        for (const auto& asset : _assets)
        {
            std::cout << "- " << asset.GetName() << ": " << asset.GetMessage() << std::endl;
        }
    }

    
    void Player::RemoveAsset(const std::string& assetName)
    {
        _assets.erase(std::remove_if(_assets.begin(), _assets.end(),
            [&assetName](const Asset& asset) { return asset.GetName() == assetName; }),
            _assets.end());
    }

    void Player::UseAsset(const std::string& assetName)
    {
        auto it = std::find_if(_assets.begin(), _assets.end(),
            [&assetName](const Asset& asset) { return asset.GetName() == assetName; });

        if (it != _assets.end())
        {
            // Use the asset
            it->hasBeenUsed = true;
            std::cout << "Used asset: " << it->GetName() << std::endl;
        }
    }

    void Player::CollectItems(Node& node)
    {
        auto items = node.GetAssets();
        for (auto& item : items)
        {
            AddAsset(*item); // Use AddAsset to prevent duplicates
            node.RemoveAsset(item->GetName()); // Remove item from node after collection
        }
    }

    void Player::AttackMonster(Monster& monster, Node& node)
    {
        // Display available weapons
        std::cout << "Available weapons: ";
        for (const auto& asset : _assets)
        {
            if (asset.isOffensive())
            {
                std::cout << asset.GetName() << " ";
            }
        }
        std::cout << std::endl;

        std::cout << "Specify weapon or ability to use (or press enter to skip): ";
        std::string weaponName;
        std::getline(std::cin, weaponName);

        chants::Asset* weapon = nullptr;
        if (!weaponName.empty())
        {
            for (auto& asset : _assets)
            {
                if (asset.GetName() == weaponName && asset.isOffensive())
                {
                    weapon = &asset;
                    break;
                }
            }
        }

        // Implement attack logic here
        bool playerWins = true; // Placeholder for actual combat logic

        if (playerWins)
        {
            std::cout << "Player wins the fight against " << monster.GetName() << "!" << std::endl;
            node.RemoveMonster(monster.GetName()); // Remove monster from node after defeat
        }
    }

    const vector<Asset>& Player::GetAssets() const
    {
        return _assets;
    }
}
