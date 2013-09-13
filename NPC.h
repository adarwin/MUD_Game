#ifndef NPC_H
#define NPC_H

#include "Creature.h"
#include <string>

class Room;

class NPC : public Creature {
    public:
        NPC(int, Room*);
        std::string getType() const;
    private:
};

#endif
