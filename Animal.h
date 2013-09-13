#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
#include "Creature.h"

class Animal : public Creature {
    public:
        Animal(int);
        Animal(int, Room*);
        std::string getType() const;
    private:
};
#endif
