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
    cout << "constructing a creature object" << endl;
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
int Creature::getName() const {
    return name;
}
void Creature::issuePositiveResponse() const {
    cout << "This is a positive response" << endl;
}
void Creature::issueNegativeResponse() const {
    cout << "This is a negative response" << endl;
}

std::string Creature::getType() const {
    return "Creature";
}
std::string Creature::getStringOutput() const {
    //cout << "Getting string output from creature" << endl;
    stringstream ss;
    ss << getType() << " " << getName();
    return ss.str();
}
