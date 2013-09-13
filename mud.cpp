#include <iostream>
#include <string>
#include <vector>
#include "Creature.h"
#include "PC.h"
#include "Room.h"
#include "Animal.h"
#include "NPC.h"

using namespace std;

//class PC;
//class Animal;
//class NPC;

int main() {
    string input;
    PC* pc;
    /*
    vector<Room> rooms;
    rooms.reserve(10);
    Room a("a");
    Room b("b");
    Room c;
    Room d;
    Room e;
    Room f;
    Room g;
    a.south = &b;
    b.north = &a;
    b.south = &c;
    vector<Creature> creatures;
    creatures.reserve(40);
    creatures.push_back(Creature());
    creatures.push_back(Animal("Jamie"));
    for (int i = 0; i < creatures.size(); i++) {
        a.addCreature(&creatures[i]);
    }
    for (int i = 0; i < a.creatures.size(); i++) {
        cout << "Creature name = " << a.creatures[i]->getName() << endl;
    }
    cout << "Capacity = " << rooms.capacity() << endl;
    cout << "Size = " << rooms.size() << endl;
    cout << "a.south = " << a.south << endl;
    cout << "a.south->getName() = " << a.south->getName() << endl;
    cout << "Address of b = " << &b << endl;
    PC pc ("Squash");
    cout << "Enter a command: ";
    */
    // Get number of rooms
    int numRooms;
    cin >> numRooms;
    cout << "Number of rooms = " << numRooms << endl;
    // Create the rooms
    vector<Room*> rooms;
    rooms.reserve(numRooms);
    for (int i = 0; i < numRooms; i++) {
        int state, north, south, east, west;
        cin >> state >> north >> south >> east >> west;
        Room* temp = new Room(i, state);
        cout << "Room " << temp->getName() << " is " << temp->getStateString() << endl;
        if (north != -1) {
            temp->north = rooms[north];
            //cout << "  To the north is room " << temp.north->getName() << endl;
        } else {
            temp->north = NULL;
        }
        if (south != -1) {
            temp->south = rooms[south];
            //cout << "  To the south is room " << temp.south->getName() << endl;
        } else {
            temp->south = NULL;
        }
        if (east != -1) {
            temp->east = rooms[east];
            //cout << "  To the east is room " << temp.east->getName() << endl;
        } else {
            temp->east = NULL;
        }
        if (west != -1) {
            temp->west = rooms[west];
            //cout << "  To the west is room " << temp.west->getName() << endl;
        } else {
            temp->west = NULL;
        }
        rooms.push_back(temp);
    }
    // Get number of creatures
    int numCreatures;
    cin >> numCreatures;
    cout << "Number of creatures = " << numCreatures << endl;
    // Create the creatures
    vector<Creature*> creatures;
    creatures.reserve(numCreatures);
    for (int i = 0; i < numCreatures; i++) {
        int creatureType, location;
        cin >> creatureType >> location;
        Creature* newCreatureReference;
        if (creatureType == 0) {
            // PC
            pc = new PC(i, rooms[location]);
            newCreatureReference = pc;
            //PC temp(i, &rooms[location]);
            //newCreatureReference = temp;
        } else if (creatureType == 1) {
            // Animal
            newCreatureReference = new Animal(i, rooms[location]);
        } else if (creatureType == 2) {
            // NPC
            newCreatureReference = new NPC(i, rooms[location]);
        }
        cout << "Creature " << newCreatureReference->getName()
             << " is of type, " << newCreatureReference->getType()
             << " and references room " << newCreatureReference->currentRoom->getName()
             << endl;
        creatures.push_back(newCreatureReference);
        rooms[location]->addCreature(newCreatureReference);
    }
    while (cin >> input) {
        if (input == "exit") {
            break;
        } else if (input == "look") {
            pc->look();
            cout << "looked" << endl;
        }
        cout << "Enter a command: " << endl;
    }
    // Release resources
    for (int i = 0; i < rooms.size(); i++) {
        delete rooms[i];
    }
    for (int i = 0; i < creatures.size(); i++) {
        delete creatures[i];
    }
    return 0;
}
