/**
 * @file AdventureGameMap.hpp
 * @brief Declaration of the AdventureGameMap class, representing the game world map.
 *
 * The `AdventureGameMap` class manages the locations (nodes) in the game world, which the player can explore.
 * It contains methods for building the map and retrieving the list of locations.
 *
 * **Public Methods**:
 * - `AdventureGameMap()`: Constructor to initialize the map.
 * - `vector<Node> GetLocations()`: Returns the list of game locations (nodes).
 *
 * **Private Methods**:
 * - `buildMapNodes()`: Constructs the map nodes and their connections.
 *
 * @author Evan Aarons-Wood
 * @version 1.0
 * @date 2024-12-06
 */


#pragma once

#include <string>
#include <Node.hpp>

using namespace std;

namespace chants
{
    class AdventureGameMap
    {
    private:
        vector<Node> locations;

        void buildMapNodes();

    public:
        AdventureGameMap();
        vector<Node> GetLocations();
    };
}