#include <vector>
#include <string>
#include <list>
#include "Room.h"
#include "Creature.h"
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::list;

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
    return state;
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
bool Room::removeCreature(Creature* targetCreature) {
    for (vector<Creature*>::iterator iterator = creatures.begin();
         iterator < creatures.end();
         iterator++) {
        if (*iterator == targetCreature) {
            creatures.erase(iterator);
            return true;
        }
    }
    return false;
}
void Room::cleanRoom() {
    bool shouldNotify = true;
    int previousState = state;
    if (state == dirty) {
        state = half_dirty;
    } else if (state == half_dirty) {
        state = clean;
    } else {
        shouldNotify = false;
        cout << "| Failed to clean the room because it was already "
             << getStateString(clean) << endl;
    }
    if (shouldNotify) {
        cout << "| Room " << name << " successfully cleaned and is now "
             << getStateString(state) << endl;
        notifyCreatures(previousState, state);
    }
}
void Room::notifyCreatures(int previousState, int newState) {
    unsigned int numCreatures = creatures.size();
    vector<Creature*> removeList;
    for (unsigned int i = 0; i < numCreatures; i++) {
        if (creatures[i]->getType() != "PC") {
            if (creatures[i]->respondToStateChange(previousState, newState)) {
                removeList.push_back(creatures[i]);
            }
        }
    }
    for (unsigned int i = 0; i < removeList.size(); i++) {
        removeList.at(i)->leaveRoom();
    }
}
void Room::dirtyRoom() {
    bool shouldNotify = true;
    int previousState = state;
    if (state == clean) {
        state = half_dirty;
    } else if (state == half_dirty) {
        state = dirty;
    } else {
        shouldNotify = false;
        cout << "| Failed to dirty the room because it was already "
             << getStateString(dirty) << endl;
    }
    if (shouldNotify) {
        cout << "| Room " << name << " successfully dirtied and is now "
             << getStateString(state) << endl;
        notifyCreatures(previousState, state);
    }
}
std::ostream& operator<< (std::ostream& out, const Room& room) {
    out << "| Room " << room.getName() << ", currently "
        << room.getStateString() << ":" << endl;
    if (room.north != NULL) {
        out << "|   To the North, lies room " << room.north->getName() << endl;
    }
    if (room.south != NULL) {
        out << "|   To the South, exists room " << room.south->getName()
            << endl;
    }
    if (room.east != NULL) {
        out << "|   To the East, is room " << room.east->getName() << endl;
    }
    if (room.west != NULL) {
        out << "|   To the West, is situated room " << room.west->getName()
            << endl;
    }
    out << "|   Contains..." << endl;
    for (unsigned int i = 0; i < room.creatures.size(); i++) {
        out << "|     " << room.creatures[i]->getStringOutput() << endl;
    }
    return out;
}
