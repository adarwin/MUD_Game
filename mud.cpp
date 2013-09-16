#include <iostream>
#include <string>
#include <vector>
#include "Creature.h"
#include "PC.h"
#include "Room.h"
#include "Animal.h"
#include "NPC.h"

using namespace std;


int main() {
    PC* pc;
    cout << endl << " -------------------------------"
         << endl << "| Reading from standard input..." << endl;

    // Get number of rooms
    int numRooms;
    cin >> numRooms;
    cout << "|" << endl;
    cout << "|   Apparently, there should be " << numRooms
         << " rooms, with names 0 - " << numRooms-1 << endl;

    // Create the rooms
    vector<Room*> rooms;
    rooms.reserve(numRooms);
    for (int i = 0; i < numRooms; i++) {
        rooms[i] = new Room(i);
    }
    cout << "|    ---------------------" << endl
         << "|...| Let's get to that..." << endl;
    for (int i = 0; i < numRooms; i++) {
        int state, north, south, east, west;
        cin >> state >> north >> south >> east >> west;
        cout << "|...|   Creating room " << i << " with state: " << state << endl;
        //Room* temp = new Room(i, state);
        Room* temp = rooms[i];
        temp->state = state;
        //cout << "Room " << temp->getName() << " is " << temp->getStateString() << endl;
        if (north != -1) {
            temp->north = rooms[north];
            cout << "|...|     ...with neighbor to the North: room "
                 << temp->north->getName() << endl;
            //cout << "  To the north is room " << temp.north->getName() << endl;
        } else {
            temp->north = NULL;
        }
        if (south != -1) {
            temp->south = rooms[south];//rooms[south];
            cout << "|...|     ...with neighbor to the South: room "
                 << temp->south->getName() << endl;
            //cout << "  To the south is room " << temp.south->getName() << endl;
        } else {
            temp->south = NULL;
        }
        if (east != -1) {
            temp->east = rooms[east];
            cout << "|...|     ...with neighbor to the East: room "
                 << temp->east->getName() << endl;
            //cout << "  To the east is room " << temp.east->getName() << endl;
        } else {
            temp->east = NULL;
        }
        if (west != -1) {
            temp->west = rooms[west];
            cout << "|...|     ...with neighbor to the West: room "
                 << temp->west->getName() << endl;
            //cout << "  To the west is room " << temp.west->getName() << endl;
        } else {
            temp->west = NULL;
        }
        rooms[i] = temp;//.push_back(temp);
    }
    cout << "|...| Done creating rooms!" << endl
         << "|    ---------------------" << endl;
    // Get number of creatures
    int numCreatures;
    cin >> numCreatures;
    cout << "|" << endl;
    cout << "|   The input seems to indicate we should " << endl
         << "|   create " << numCreatures
         << " creatures with names 0 - " << numCreatures-1 << endl;
    // Create the creatures
    vector<Creature*> creatures;
    creatures.reserve(numCreatures);
    cout << "|    --------------------" << endl
         << "|...| Alright, here goes!" << endl;
    for (int i = 0; i < numCreatures; i++) {
        int creatureType, location;
        cin >> creatureType >> location;
        Creature* newCreatureReference;
        cout << "|...|   Creating creature, ";
        if (creatureType == 0) {
            // PC
            cout << "PC " << i;
            pc = new PC(i, rooms[location]);
            newCreatureReference = pc;
            //PC temp(i, &rooms[location]);
            //newCreatureReference = temp;
        } else if (creatureType == 1) {
            // Animal
            cout << "Animal " << i;
            newCreatureReference = new Animal(i, rooms[location]);
        } else if (creatureType == 2) {
            // NPC
            cout << "NPC " << i;
            newCreatureReference = new NPC(i, rooms[location]);
        }
        cout << " and assigning it to room " << location << endl;
        /*
        cout << "Creature " << newCreatureReference->getName()
             << " is of type, " << newCreatureReference->getType()
             << " and references room " << newCreatureReference->currentRoom->getName()
             << endl;
        */
        creatures.push_back(newCreatureReference);
        rooms[location]->addCreature(newCreatureReference);
    }
    cout << "|...| Finished making the creatures!" << endl
         << "|    -------------------------------" << endl;
    cout << "|" << endl;
    cout << "| Finished reading input" << endl
         << " ----------------------------" << endl;

    cout << endl;
    cout << " -----------------" << endl
         << "| Beginning game " << endl;
    string input;
    while (cin >> input) {
        cout << "|" << endl;
        cout << "| Command: " << input << endl;
        if (input == "exit") {
            break;
        } else if (input == "look") {
            pc->look();
            //cout << "looked" << endl;
        } else if (input == "clean") {
            pc->clean();
        } else if (input == "dirty") {
            pc->dirty();
        } else if (input == "north") {
            pc->moveToRoom(pc->currentRoom->north);
        } else if (input == "south") {
            pc->moveToRoom(pc->currentRoom->south);
        } else if (input == "east") {
            pc->moveToRoom(pc->currentRoom->east);
        } else if (input == "west") {
            pc->moveToRoom(pc->currentRoom->west);
        }
        //cout << "Enter a command: " << endl;
    }
    cout << "| Ending Game..." << endl
         << " ---------------" << endl;
    // Release resources
    for (int i = 0; i < numRooms; i++) {
        delete rooms[i];
    }
    for (unsigned int i = 0; i < numCreatures; i++) {
        delete creatures[i];
    }
    return 0;
}
