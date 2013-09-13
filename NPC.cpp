#include "NPC.h"

NPC::NPC(int name, Room* room) : Creature(name, room) {
}

std::string NPC::getType() const {
    return "NPC";
}
