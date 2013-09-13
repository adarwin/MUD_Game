#include <iostream>
#include "PC.h"
#include "Room.h"

using std::cout;
using std::endl;

PC::PC(int name) : Creature(name) {
    cout << "constructing the pc" << endl;
}
PC::PC(int name, Room* room) : Creature(name, room) {
    cout << "constructing the pc" << endl;
}
PC::~PC() {
    cout << "Getting rid of PC" << endl;
}

std::string PC::getType() const {
    return "PC";
}

void PC::look() const {
    cout << *currentRoom;
    /*
    cout << "Room " << currentRoom->getName() << ", " << currentRoom->getStateString()
         << ", neighbors ";
    */
    if (currentRoom->north != 0) {
        cout << currentRoom->north->getName() << " to the North, ";
    }
    if (currentRoom->south != NULL) {
        cout << currentRoom->south->getName() << " to the South, ";
    }
    if (currentRoom->east != 0) {
        cout << currentRoom->east->getName() << " to the East, ";
    }
    if (currentRoom->west != 0) {
        cout << currentRoom->west->getName() << " to the West, ";
    }
    cout << "contains:" << endl;
    for (int i = 0; i < currentRoom->creatures.size(); i++) {
        cout << currentRoom->creatures[i]->getName() << endl;
    }
}
std::ostream& operator<< (std::ostream& os, const PC& pc) {
    os << "PC " << pc.getName() << endl;
    return os;
}
