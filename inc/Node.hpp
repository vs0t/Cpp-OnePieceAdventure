/**
 * @file Node.hpp
 * @brief Declaration of the Node class, representing locations in the game world.
 *
 * The `Node` class defines the properties and behaviors of locations (nodes) within the game world. Each node has an ID,
 * name, description, and may contain connections to other nodes, assets, and monsters. Nodes are the core building blocks
 * of the game map, and they allow for player movement and interactions.
 *
 * **Public Methods**:
 * - `Node(int id, string name, string description = "")`: Constructor to initialize a node with an ID, name, and optional description.
 * - `int GetId()`: Returns the ID of the node.
 * - `void SetId(int id)`: Sets the ID of the node.
 * - `string GetName() const`: Returns the name of the node.
 * - `string GetDescription() const`: Returns the description of the node.
 * - `void SetDescription(const string& description)`: Sets the description of the node.
 * - `void AddConnection(Node *conn)`: Adds a connection to another node.
 * - `vector<Node *> GetConnections() const`: Returns a list of connected nodes.
 * - `Node *GetAConnection(int connId)`: Retrieves a specific connected node by its ID.
 * - `void AddAsset(Asset *asset)`: Adds an asset to the node.
 * - `const vector<Asset *> GetAssets() const`: Returns a list of assets at the node.
 * - `void RemoveAsset(const string& assetName)`: Removes an asset from the node.
 * - `void AddMonster(Monster *monster)`: Adds a monster to the node.
 * - `vector<Monster *> GetMonsters() const`: Returns a list of monsters at the node.
 * - `void RemoveMonster(const string& monsterName)`: Removes a monster from the node.
 * - `bool operator==(const Node &rhs) const`: Compares two nodes for equality based on their IDs.
 *
 * **Attributes**:
 * - `_id`: The unique identifier for the node.
 * - `_name`: The name of the node (location).
 * - `_description`: The description of the node.
 * - `_connections`: A list of other nodes connected to this node.
 * - `_assets`: A list of assets located at this node.
 * - `_monsters`: A list of monsters found at this node.
 *
 * @author Evan Aarons Wood
 * @version 1.0
 * @date 2024-12-06
 */


#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <vector>
#include "Asset.hpp"
#include "Monster.hpp"

using std::string;
using std::vector;

namespace chants
{
    class Node
    {
    public:
        Node(int id, string name, string description = ""); // Updated constructor
        int GetId();
        void SetId(int id);
        string GetName() const;
        string GetDescription() const; // Getter for description
        void SetDescription(const string& description); // Setter for description
        void AddConnection(Node *conn);
        vector<Node *> GetConnections() const;
        Node *GetAConnection(int connId);
        void AddAsset(Asset *asset);
        const vector<Asset *> GetAssets() const; // Updated to return const vector
        void RemoveAsset(const string& assetName);
        void AddMonster(Monster *monster);
        vector<Monster *> GetMonsters() const;
        void RemoveMonster(const string& monsterName);
        bool operator==(const Node &rhs) const;

    private:
        int _id;
        string _name;
        string _description; // Added description member
        vector<Node *> _connections;
        vector<Asset *> _assets;
        vector<Monster *> _monsters;
    };
}

#endif // NODE_HPP
