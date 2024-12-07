/**
 * @file game.cpp
 * @brief Implementation of the Adventure Game, featuring player exploration, asset collection, and monster battles.
 *
 * This file contains the main logic for a text-based adventure game where the player navigates through various nodes,
 * collects assets, and battles monsters. The game is set in a world inspired by One Piece, with different locations
 * representing towns, villages, and other points of interest. The player can explore these locations, collect useful items,
 * and engage in battles with powerful enemies. The goal is to defeat all monsters and win the game.
 *
 * Key Features:
 * - **Node System**: The world is divided into interconnected nodes (locations). Each node has descriptions, assets, and monsters.
 * - **Player Actions**: The player can move between nodes, attack monsters, collect assets, and view inventory.
 * - **Combat System**: The player battles monsters using various weapons and abilities. The outcome depends on the player and monster's attack values.
 * - **Asset Collection**: The player can collect and use assets found at nodes. Assets include offensive and healing items like weapons, potions, and fruits.
 * - **Monster Defeat**: The game tracks the status of monsters in each node. When all monsters are defeated, the player wins.
 *
 * **Classes Involved**:
 * - `chants::Node`: Represents locations in the game world, each with a description, assets, and monsters.
 * - `chants::Player`: Represents the player, with attributes such as health and inventory, and the ability to fight and interact with assets.
 * - `chants::Asset`: Represents items in the game, such as weapons and healing items.
 * - `chants::Monster`: Represents the monsters the player will encounter and fight throughout the game.
 *
 * **Game Loop**:
 * - The player starts in the "Fuschia Village" and can travel to different locations connected by paths.
 * - The game continues until all monsters are defeated, or the player chooses to exit.
 *
 * @author Evan Aarons-Wood
 * @version 1.0
 * @date 2024-12-06
 */

#include "Player.hpp"
#include "Node.hpp"
#include "Asset.hpp"
#include "Monster.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm> // Include algorithm for std::all_of

using namespace std;

// ANSI color codes for text formatting
#define COLOR_RED 31
#define COLOR_GREEN 32
#define COLOR_YELLOW 33
#define COLOR_BLUE 34
#define COLOR_MAGENTA 35
#define COLOR_CYAN 36

// Function to set text color
string ChangeColor(int color_code) {
    return "\033[1;" + to_string(color_code) + "m";
}

// Function to reset text color
string ResetColor() {
    return "\033[0m";
}

int FindNode(string loc, vector<chants::Node> *gameMap);
int Battle(chants::Player player, chants::Monster monster, const chants::Asset* weapon = nullptr); // Updated to use const
std::string getCommandName(const std::string &str);
std::string getCommandArgument(const std::string &str);
bool isNumber(const std::string& s);

void DisplayNodeInfo(const chants::Node& node) {
    cout << ChangeColor(COLOR_MAGENTA) << "Location: " << node.GetName() << ResetColor() << endl;
    cout << node.GetDescription() << endl;

    cout << "There are paths here ..." << endl;
    for (const auto& connection : node.GetConnections()) {
        cout << connection->GetId() << " " << connection->GetName() << endl;
    }

    for (const auto& asset : node.GetAssets()) {
        cout << "Asset at this node: " << asset->GetName() << " " << asset->GetMessage() << " " << asset->GetValue() << endl;
    }

    for (const auto& monster : node.GetMonsters()) {
        cout << "Monster at this node: " << monster->GetName() << endl;
    }
}

bool AllMonstersDefeated(const vector<chants::Node>& gameMap) {
    return std::all_of(gameMap.begin(), gameMap.end(), [](const chants::Node& node) {
        return node.GetMonsters().empty();
    });
}

int main()
{
    vector<chants::Node> gameMap;

    // build all nodes
    chants::Node fuschiaVillage(0, "Fuschia Village");
    fuschiaVillage.SetDescription("A peaceful village where Luffy grew up, known for its windmill and friendly people.\n");

    chants::Node shellTown(1, "Shell Town");
    shellTown.SetDescription("A marine base town where Captain Morgan rules with an iron fist.\n");

    chants::Node orangeTown(2, "Orange Town");
    orangeTown.SetDescription("A town terrorized by the pirate Buggy the Clown.\n");

    chants::Node syrupVillage(3, "Syrup Village");
    syrupVillage.SetDescription("A quiet village with a long nose boy dreaming of adventure.\n");

    chants::Node baratie(4, "Baratie");
    baratie.SetDescription("A floating restaurant on the sea, known for its delicious food and fierce chefs.\n");

    chants::Node arlongPark(5, "Arlong Park");
    arlongPark.SetDescription("A stronghold of the fish-man Arlong, who oppresses the nearby village.\n");

    chants::Node loguetown(6, "Loguetown");
    loguetown.SetDescription("The town of beginnings and endings, where the Pirate King was born and executed.\n");

    // connect nodes paths
    fuschiaVillage.AddConnection(&shellTown);
    fuschiaVillage.AddConnection(&orangeTown);

    shellTown.AddConnection(&fuschiaVillage);
    shellTown.AddConnection(&syrupVillage);

    orangeTown.AddConnection(&fuschiaVillage);
    orangeTown.AddConnection(&baratie);

    syrupVillage.AddConnection(&shellTown);
    syrupVillage.AddConnection(&baratie);

    baratie.AddConnection(&orangeTown);
    baratie.AddConnection(&syrupVillage);
    baratie.AddConnection(&arlongPark);

    arlongPark.AddConnection(&baratie);
    arlongPark.AddConnection(&loguetown);

    loguetown.AddConnection(&arlongPark);

    // build map in same order as Node Ids above.
    // The index of each node in the vector must match its id.
    gameMap.push_back(fuschiaVillage);
    gameMap.push_back(shellTown);
    gameMap.push_back(orangeTown);
    gameMap.push_back(syrupVillage);
    gameMap.push_back(baratie);
    gameMap.push_back(arlongPark);
    gameMap.push_back(loguetown);

    // build assets
    chants::Asset legendarySword("Yoru", "A legendary black blade wielded by the greatest swordsman.", 500, true);
    chants::Asset devilFruit("Gomu Gomu no Mi", "A mysterious fruit that grants rubber-like abilities.", 300, true);
    chants::Asset map("Grand Line Map", "A map showing the way to the Grand Line.", 100, false);
    chants::Asset logPose("Log Pose", "A navigational tool essential for Grand Line travel.", 150, false);
    chants::Asset meat("Meat", "A delicious piece of meat to restore energy.", 50, false);
    chants::Asset healingPotion("Healing Potion", "A potion that restores health.", 200, false);
    chants::Asset slingshot("Slingshot", "A simple weapon for ranged attacks.", 100, true);
    chants::Asset pistol("Pistol", "A firearm for ranged combat.", 250, true);
    chants::Asset giantHammer("Giant Hammer", "A massive hammer for powerful attacks.", 300, true);
    chants::Asset devilFruit2("Mera Mera no Mi", "A fruit that grants fire-based abilities.", 350, true);

    // randomly add assets to nodes
    int numOfNodes = gameMap.size();

    srand(time(nullptr)); // seed the random number generator
    int randNode = rand() % numOfNodes;
    gameMap[randNode].AddAsset(&legendarySword);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddAsset(&devilFruit);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddAsset(&map);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddAsset(&logPose);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddAsset(&meat);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddAsset(&healingPotion);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddAsset(&slingshot);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddAsset(&pistol);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddAsset(&giantHammer);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddAsset(&devilFruit2);

    // build monsters
    chants::Monster buggy("Buggy the Clown", 3000, 100);
    chants::Monster arlong("Arlong", 4000, 150);
    chants::Monster kuro("Captain Kuro", 3500, 120);
    chants::Monster donKrieg("Don Krieg", 4500, 130);
    chants::Monster alvida("Alvida", 2500, 90);
    chants::Monster smoker("Smoker", 5000, 160);
    chants::Monster marine("Marine", 2000, 80);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddMonster(&buggy);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddMonster(&arlong);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddMonster(&kuro);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddMonster(&donKrieg);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddMonster(&alvida);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddMonster(&smoker);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddMonster(&marine);

    // get ready to play game below
    int nodePointer = 0; // start at Fuschia Village
    string input;
    chants::Player player("Luffy", 10000, 200); // Example player

    // +++++++++ game loop ++++++++++
    while (true)
    {
        // show current node info
        DisplayNodeInfo(gameMap[nodePointer]);

        cout << "\nGo to node? e(x)it, (v)iew inventory, (a)ttack monster, (t)ake item: ";
        getline(cin, input);

        // exit app?
        if (input == "x")
            break;

        if (input == "v")
        {
            player.ViewInventory();
            continue;
        }

        int nodeAddr = -1;
        if (isNumber(input))
        {
            nodeAddr = stoi(input);
        }

        bool validConnection = false;
        for (chants::Node *node : gameMap[nodePointer].GetConnections())
        {
            if (node->GetId() == nodeAddr)
            {
                validConnection = true;
            }
        }

        int dir = -1;
        if (validConnection)
        {
            dir = FindNode(input, &gameMap);
            nodePointer = dir;
        }

        // if player wants to take an asset (t hammer)
        if (input.length() > 1 && input[0] == 't')
        {
            string assetName = getCommandArgument(input);
            const chants::Asset* targetAsset = nullptr; // Use const pointer
            for (const auto& asset : gameMap[nodePointer].GetAssets()) // Use const auto&
            {
                if (asset->GetName() == assetName)
                {
                    targetAsset = asset;
                    break;
                }
            }

            if (targetAsset)
            {
                player.AddAsset(*targetAsset);
                gameMap[nodePointer].RemoveAsset(targetAsset->GetName());
                cout << ChangeColor(COLOR_GREEN) << "Collected: " << targetAsset->GetName() << ResetColor() << endl;
            }
            else
            {
                cout << "Asset not found!" << endl;
            }
        }

        // if player wants to attack a monster (a kraken)
        if (input.length() > 1 && input[0] == 'a')
        {
            string monsterName = getCommandArgument(input);
            chants::Monster* targetMonster = nullptr;
            for (auto& monster : gameMap[nodePointer].GetMonsters())
            {
                if (monster->GetName() == monsterName)
                {
                    targetMonster = monster;
                    break;
                }
            }

            if (targetMonster)
            {
                cout << "Available weapons: ";
                for (auto& asset : player.GetAssets())
                {
                    if (asset.isOffensive())
                    {
                        cout << asset.GetName() << " ";
                    }
                }
                cout << endl;

                cout << "Specify weapon or ability to use (or press enter to skip): ";
                string weaponName;
                getline(cin, weaponName);

                const chants::Asset* weapon = nullptr; // Use const pointer
                if (!weaponName.empty())
                {
                    for (auto& asset : player.GetAssets())
                    {
                        if (asset.GetName() == weaponName && asset.isOffensive())
                        {
                            weapon = &asset;
                            break;
                        }
                    }
                }

                int battleResult = Battle(player, *targetMonster, weapon);
                if (battleResult == 1) // Player wins
                {
                    gameMap[nodePointer].RemoveMonster(targetMonster->GetName());
                }
            }
            else
            {
                cout << "Monster not found!" << endl;
            }
        }

        // if player wants to drop an asset (d hammer)
        if (input.length() > 1 && input[0] == 'd')
        {
            string lastWord = getCommandArgument(input);
            // Implement logic to drop asset
        }

        // if player wants to inspect an asset (i hammer)
        if (input.length() > 1 && input[0] == 'i')
        {
            string lastWord = getCommandArgument(input);
            // Implement logic to inspect asset
        }

        if (!validConnection && input[0] != 't' && input[0] != 'a')
        {
            cout << "Not a valid node address\n";
        }

        // Check if all monsters are defeated
        if (AllMonstersDefeated(gameMap)) {
            cout << ChangeColor(COLOR_BLUE) << "Congratulations! You have defeated all the monsters and won the game!" << ResetColor() << endl;
            break;
        }

        cout << endl;
    }
    return 0;
}

int FindNode(string loc, vector<chants::Node> *gameMap)
{
    int intLoc = -1;
    if (isNumber(loc))
    {
        intLoc = stoi(loc);
    }
    for (chants::Node node : *gameMap)
    {
        if (node.GetName() == loc || node.GetId() == intLoc)
            return node.GetId();
    }
    return -1;
}

int Battle(chants::Player player, chants::Monster monster, const chants::Asset* weapon) // Updated to use const
{
    srand(time(nullptr));

    int playerAttackValue = player.Fight();
    if (weapon && weapon->isOffensive())
    {
        playerAttackValue += weapon->GetValue();
        cout << ChangeColor(COLOR_RED) << "Using " << weapon->GetName() << " to attack!" << ResetColor() << endl;
    }

    int monsterAttackValue = monster.Fight();

    cout << "Player attacks " << monster.GetName() << " with value: " << playerAttackValue << endl;
    cout << monster.GetName() << " attacks back with value: " << monsterAttackValue << endl;

    if (playerAttackValue > monsterAttackValue)
    {
        cout << "Player wins the fight!" << endl;
        return 1; // Player wins
    }
    else if (playerAttackValue < monsterAttackValue)
    {
        cout << "Player loses the fight!" << endl;
        return -1; // Player loses
    }
    else
    {
        cout << "It's a draw!" << endl;
        return 0; // Draw
    }
}

std::string getCommandName(const std::string &str)
{
    // Trim leading spaces
    std::string trimmed = str;
    trimmed.erase(0, trimmed.find_first_not_of(' '));

    // Find the position of the first space
    size_t pos = trimmed.find_first_of(' ');

    // Extract the command name
    if (pos == std::string::npos)
    {
        return trimmed; // No spaces found, return the whole string
    }
    else
    {
        return trimmed.substr(0, pos);
    }
}

std::string getCommandArgument(const std::string &str)
{
    // Trim leading spaces
    std::string trimmed = str;
    trimmed.erase(0, trimmed.find_first_not_of(' '));

    // Find the position of the first space
    size_t pos = trimmed.find_first_of(' ');

    // Extract the command argument
    if (pos == std::string::npos)
    {
        return ""; // No argument found
    }
    else
    {
        return trimmed.substr(pos + 1);
    }
}

bool isNumber(const std::string& s)
{
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}
