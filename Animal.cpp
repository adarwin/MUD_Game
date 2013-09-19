#include "Animal.h"
#include <string>
#include <iostream>
#include "PC.h"

using std::endl;
using std::cout;

Animal::Animal(int name) : Creature(name) {
}

Animal::Animal(int name, Room* currentRoom) : Creature(name, currentRoom) {
}

std::string Animal::getType() const {
    return "Animal";
}

bool Animal::happyAboutStateChange(int previousState, int newState) const {
    return newState < previousState;
}

void Animal::issuePositiveResponse() {
    cout << "| " << getStringOutput()
         << " wags its tail at you for cleaning the room" << endl;
    PC::increaseRespectBy(1);
    /*
    cout << "|   Your respect has now increased from "
         << PC::respect << " to ";
    cout << ++PC::respect << endl;
    */
}

void Animal::issueNegativeResponse() {
    cout << "| " << getStringOutput() << " bites you for dirtying the room"
         << endl;
    PC::increaseRespectBy(-1);
    /*
    cout << "|   Consequently, your respect has decreased from "
         << PC::respect << " to ";
    cout << --PC::respect << endl;
    */
}
