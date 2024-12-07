/**
 * @file AdventureGameMap.cpp
 * @brief Implementation of the AdventureGameMap class, managing the game world map and locations.
 *
 * The `AdventureGameMap` class defines the map of locations (nodes) in the game, builds the connections between them,
 * and provides methods for accessing the locations. The game world consists of various locations, each with descriptions
 * and paths connecting them. This file includes the constructor and logic for constructing the game map.
 *
 * **Methods**:
 * - `AdventureGameMap()`: Constructor that initializes the game map and builds all nodes and their connections.
 * - `void buildMapNodes()`: Private method that defines the nodes (locations) and connects them.
 * - `vector<Node> GetLocations()`: Returns a list of all the game locations (nodes).
 *
 * **Game World Setup**:
 * - Locations: Fuschia Village, Shell Town, Orange Town, Syrup Village, Baratie, Arlong Park, Loguetown.
 * - Each location has a description and is connected to other locations.
 *
 * @author Evan Aarons-Wood
 * @version 1.0
 * @date 2024-12-06
 */


#include <AdventureGameMap.hpp>

namespace chants
{
    AdventureGameMap::AdventureGameMap()
    {
        buildMapNodes();

        // Possible assets:
        // Yoru
        // Gomu Gomu no Mi
        // Grand Line Map
        // Log Pose
        // Meat
        // Healing Potion
        // Slingshot
        // Pistol
        // Giant Hammer
        // Mera Mera no Mi

        // Possible monsters:
        // Buggy the Clown
        // Arlong
        // Captain Kuro
        // Don Krieg
        // Alvida
        // Smoker
        // Marine
    }

    void AdventureGameMap::buildMapNodes()
    {
        // build all nodes
        Node fuschiaVillage(0, "Fuschia Village");
        fuschiaVillage.SetDescription("A peaceful village where Luffy grew up, known for its windmill and friendly people.\n");

        Node shellTown(1, "Shell Town");
        shellTown.SetDescription("A marine base town where Captain Morgan rules with an iron fist.\n");

        Node orangeTown(2, "Orange Town");
        orangeTown.SetDescription("A town terrorized by the pirate Buggy the Clown.\n");

        Node syrupVillage(3, "Syrup Village");
        syrupVillage.SetDescription("A quiet village with a long nose boy dreaming of adventure.\n");

        Node baratie(4, "Baratie");
        baratie.SetDescription("A floating restaurant on the sea, known for its delicious food and fierce chefs.\n");

        Node arlongPark(5, "Arlong Park");
        arlongPark.SetDescription("A stronghold of the fish-man Arlong, who oppresses the nearby village.\n");

        Node loguetown(6, "Loguetown");
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
        locations.push_back(fuschiaVillage);
        locations.push_back(shellTown);
        locations.push_back(orangeTown);
        locations.push_back(syrupVillage);
        locations.push_back(baratie);
        locations.push_back(arlongPark);
        locations.push_back(loguetown);
    }

    vector<Node> AdventureGameMap::GetLocations()
    {
        return locations;
    }

}
