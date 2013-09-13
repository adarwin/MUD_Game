#include <vector>
#include <string>
#include "Room.h"
#include "Creature.h"
using std::cout;
using std::endl;
using std::vector;
using std::string;

Room::~Room() {
    cout << "Getting rid of room" << endl;
}

Room::Room(int name) {
    init(name, half_dirty);
}
Room::Room(int name, int state) {
    init(name, state);
}
void Room::init(int name, int state) {
    this->name = name;
    this->state = state;
    vector<Creature*> creatures;
    creatures.reserve(maxNumCreatures);
}
int Room::getState() const {
}
int Room::getName() const {
    return name;
}
string Room::getStateString() const {
    return getStateString(state);
}
bool Room::addCreature(Creature* newCreature) {
    if (creatures.size() < maxNumCreatures) {
        creatures.push_back(newCreature);
        return true;
    } else {
        return false;
    }
}
std::ostream& operator<< (std::ostream& os, const Room& room) {
    os << endl << "Room " << room.getName() << ":" << endl;
    os << "  Currently " << room.getStateString() << endl;
    if (room.north != NULL) {
        os << "  Room " << room.north->getName() << " is to the North" << endl;
    }
    if (room.south != NULL) {
        os << "  Room " << room.south->getName() << " is to the South" << endl;
    }
    if (room.east != NULL) {
        os << "  Room " << room.east->getName() << " is to the East" << endl;
    }
    if (room.west != NULL) {
        os << "  Room " << room.west->getName() << " is to the West" << endl;
    }
    os << "  Contains..." << endl;
    for (int i = 0; i < room.creatures.size(); i++) {
        os << "    " << room.creatures[i]->getStringOutput() << endl;
    }
    return os;
}
