#include <iostream>
#include "PC.h"
#include "Room.h"

using std::cout;
using std::endl;

int PC::respect = 40;

PC::PC(int name) : Creature(name) {
    //cout << "constructing the pc" << endl;
}
PC::PC(int name, Room* room) : Creature(name, room) {
    //cout << "constructing the pc" << endl;
}
PC::~PC() {
    cout << "Getting rid of PC" << endl;
}

std::string PC::getType() const {
    return "PC";
}

bool PC::happyAboutStateChange(int, int) const {
    return true;
}

void PC::increaseRespectBy(int change) {
    cout << "| Respect changed from " << respect << " to ";
    respect += change;
    cout << respect << endl;
}

void PC::look() const {
    //cout << "|" << endl;
    cout << "| PC looks around room " << currentRoom->getName() << endl;
    cout << *currentRoom;
    /*
    cout << "Room " << currentRoom->getName() << ", " << currentRoom->getStateString()
         << ", neighbors ";
    */
    /*
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
    */
}

void PC::clean() {
    cout << "| PC is attempting to clean room " << currentRoom->getName()
         << endl;
    currentRoom->cleanRoom();
}
void PC::dirty() {
    cout << "| PC is attempting to dirty room " << currentRoom->getName()
         << endl;
    currentRoom->dirtyRoom();
}

/*
void PC::issuePositiveResponse() {
}
void PC::issueNegativeResponse() {
}
*/

std::ostream& operator<< (std::ostream& os, const PC& pc) {
    os << "PC " << pc.getName() << endl;
    return os;
}
