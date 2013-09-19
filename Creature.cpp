#include <iostream>
#include "Creature.h"
#include "Room.h"
#include <sstream>
#include <cstdlib>

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
    cout << "| Getting rid of " << getStringOutput() << endl;
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
bool Creature::respondToStateChange(int previousState, int newState) {
    /*
    bool willLeaveRoomIfUpset = newState == Room::clean ||
                                newState == Room::dirty;
                                */
    if (happyAboutStateChange(previousState, newState)) {
        issuePositiveResponse();
    } else {
        issueNegativeResponse();
        //if (willLeaveRoomIfUpset) {
            //cout << "| Creature should leave the room" << endl;
            return true;
            //leaveRoom();
        //}
    }
    return false;
}
void Creature::leaveRoom() {
    vector<Room*> availableRooms;
    availableRooms.reserve(4);
    if (currentRoom->north != NULL && !currentRoom->north->isFull()) {
        availableRooms.push_back(currentRoom->north);
    }
    if (currentRoom->south != NULL && !currentRoom->south->isFull()) {
        availableRooms.push_back(currentRoom->south);
    }
    if (currentRoom->east != NULL && !currentRoom->east->isFull()) {
        availableRooms.push_back(currentRoom->east);
    }
    if (currentRoom->west != NULL && !currentRoom->west->isFull()) {
        availableRooms.push_back(currentRoom->west);
    }
    if (availableRooms.size() == 0) {
        // No rooms available
        currentRoom->removeCreature(this);
        cout << "| All neighboring rooms are full. " << getStringOutput()
             << " drills a whole in the roof and escapes from the world"
             << endl;
    } else {
        int choice = rand() % availableRooms.size();
        moveToRoom(availableRooms[choice]);
        fixRoom();
    }
}
void Creature::fixRoom() {
    currentRoom->state = Room::half_dirty;
}
bool Creature::moveToRoom(Room* newRoom) {
    bool roomFull = false;
    if (newRoom != NULL) {
        if (!newRoom->isFull()) {
            bool additionSuccessful = newRoom->addCreature(this);
            if (!additionSuccessful) {
                cout << "| Failed to add " << getStringOutput()
                     << " to room " << newRoom->getName() << endl;
            }
            bool removalSuccessful = currentRoom->removeCreature(this);
            if (!removalSuccessful) {
                cout << "| Failed to remove " << getStringOutput()
                     << " from room " << currentRoom->getName() << endl;
            }
            cout << "| " << getStringOutput() << " moves from room "
                 << currentRoom->getName() << " to room " << newRoom->getName()
                 << endl;
            currentRoom = newRoom;
        } else {
            // Room is full, try another
            cout << "| " << getStringOutput() << " cannot move to room "
                 << newRoom->getName() << " because it is full" << endl;
            roomFull = true;
        }
    } else {
        cout << "| " << getStringOutput() << " cannot move to the desired "
             << "'room' because it does not exist" << endl;
    }
    return roomFull;
}
std::string Creature::getStringOutput() const {
    stringstream ss;
    ss << getType();
    if (getType() != "PC") {
        ss << " " << getName();
    }
    return ss.str();
}
