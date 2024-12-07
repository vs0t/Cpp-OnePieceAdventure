/**
 * @file Node.cpp
 * @brief Implementation of the Node class, representing locations in the game world.
 *
 * The `Node` class defines the properties and behaviors of locations (nodes) within the game world. Each node has an ID,
 * name, description, and may contain connections to other nodes, assets, and monsters. Nodes are the core building blocks
 * of the game map, and they allow for player movement and interactions.
 *
 * **Methods**:
 * - `Node(int id, string name, string description)`: Constructor to initialize a node with an ID, name, and description.
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


#include "Node.hpp"
#include <algorithm>

namespace chants
{
    Node::Node(int id, string name, string description) : _id(id), _name(name), _description(description) {}

    int Node::GetId()
    {
        return _id;
    }

    void Node::SetId(int id)
    {
        _id = id;
    }

    string Node::GetName() const
    {
        return _name;
    }

    string Node::GetDescription() const
    {
        return _description;
    }

    void Node::SetDescription(const string& description)
    {
        _description = description;
    }

    void Node::AddConnection(Node *conn)
    {
        _connections.push_back(conn);
    }

    vector<Node *> Node::GetConnections() const
    {
        return _connections;
    }

    Node *Node::GetAConnection(int connId)
    {
        for (auto conn : _connections)
        {
            if (conn->GetId() == connId)
            {
                return conn;
            }
        }
        return nullptr;
    }

    void Node::AddAsset(Asset *asset)
    {
        _assets.push_back(asset);
    }

    const vector<Asset *> Node::GetAssets() const // Updated to match header
    {
        return _assets;
    }

    void Node::RemoveAsset(const string& assetName)
    {
        _assets.erase(std::remove_if(_assets.begin(), _assets.end(),
            [&assetName](Asset* asset) { return asset->GetName() == assetName; }),
            _assets.end());
    }

    void Node::AddMonster(Monster *monster)
    {
        _monsters.push_back(monster);
    }

    vector<Monster *> Node::GetMonsters() const
    {
        return _monsters;
    }

    void Node::RemoveMonster(const string& monsterName)
    {
        _monsters.erase(std::remove_if(_monsters.begin(), _monsters.end(),
            [&monsterName](Monster* monster) { return monster->GetName() == monsterName; }),
            _monsters.end());
    }

    bool Node::operator==(const Node &rhs) const
    {
        return _id == rhs._id;
    }
}
