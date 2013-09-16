#include <iostream>
#include "Creature.h"
#include "Room.h"
#include <sstream>

using namespace std;

Creature::Creature(int name) {
    init(name, 0);
}
Creature::Creature(int name, Room* room) {
    init(name, room);
}
void Creature::init(int name, Room* room) {
    //cout << "constructing a creature object" << endl;
    this->name = name;
    this->currentRoom = room;
}
Creature::~Creature() {
    cout << "Getting rid of the creature object" << endl;
}

void Creature::look() const {
    cout << "Creature: " << name << " looks around room "
         << currentRoom->getName() << endl;
}
void Creature::clean() {
    currentRoom->cleanRoom();
    //cout << "| Creature " << name << " cleaned the room" << endl;
}
int Creature::getName() const {
    return name;
}
void Creature::issuePositiveResponse() {
    cout << "This is a positive response" << endl;
}
void Creature::issueNegativeResponse() {
    cout << "This is a negative response" << endl;
}

std::string Creature::getType() const {
    return "Creature";
}
//bool Creature::happyAboutStateChange(int previousState, int newState) const {
//}
void Creature::moveToRoom(Room* newRoom) {
    if (newRoom != NULL) {
        bool removalSuccessful = currentRoom->removeCreature(this);
        if (!removalSuccessful) {
            cout << "| Failed to remove " << getStringOutput()
                 << " from room " << currentRoom->getName() << endl;
        }
        cout << "| " << getStringOutput() << " moves from room "
             << currentRoom->getName() << " to room " << newRoom->getName()
             << endl;
        currentRoom = newRoom;
        bool additionSuccessful = currentRoom->addCreature(this);
        if (!additionSuccessful) {
            cout << "| Failed to add " << getStringOutput()
                 << " to room " << currentRoom->getName() << endl;
        }
    } else {
        cout << "| Cannot move " << getStringOutput()
             << " to the desired 'room' because it does not exist" << endl;
    }
}
std::string Creature::getStringOutput() const {
    stringstream ss;
    ss << getType();
    if (getType() != "PC") {
        ss << " " << getName();
    }
    return ss.str();
}
