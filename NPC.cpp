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
    cout << "| " << getStringOutput()
         << " bakes you a cake for dirtying the room" << endl;
    PC::increaseRespectBy(1);
    /*
    cout << "|   Your respect has now increased from "
         << PC::respect << " to ";
    cout << ++PC::respect << endl;
    */
}
void NPC::issueNegativeResponse() {
    cout << "| " << getStringOutput() << " stabs you for cleaning the room"
         << endl;
    PC::increaseRespectBy(-1);
    /*
    cout << "|   Consequently, your respect has been decreased from "
         << PC::respect << " to ";
    cout << --PC::respect << endl;
    */
}

