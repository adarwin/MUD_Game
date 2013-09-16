#include "NPC.h"
#include "PC.h"
#include <iostream>

using std::cout;
using std::endl;


NPC::NPC(int name, Room* room) : Creature(name, room) {
}

std::string NPC::getType() const {
    return "Human";
}

bool NPC::happyAboutStateChange(int previousState, int newState) const {
    return newState > previousState;
}
void NPC::issuePositiveResponse() {
    cout << "| " << getType() << " " << getName()
         << " likes dirty rooms and is happy with you for dirtying this one"
         << endl;
    cout << "|   Your respect has now increased from "
         << PC::respect << " to ";
    cout << --PC::respect << endl;
}
void NPC::issueNegativeResponse() {
    cout << "| " << getType() << " " << getName()
         << " likes dirty rooms and despises you for cleaning this one"
         << endl;
    cout << "|   Consequently, your respect has been decreased from "
         << PC::respect << " to ";
    cout << --PC::respect << endl;
}

