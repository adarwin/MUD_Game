#include "Animal.h"
#include <string>
#include <iostream>

using std::endl;

Animal::Animal(int name) : Creature(name) {
}

Animal::Animal(int name, Room* currentRoom) : Creature(name, currentRoom) {
}

std::string Animal::getType() const {
    return "Animal";
}
