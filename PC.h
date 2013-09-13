#ifndef PC_H
#define PC_H
#include "Creature.h"
#include <string>

class PC : public Creature {
    public:
        int specialInt;
        PC(int);
        PC(int, Room*);
        ~PC();
        std::string getType() const;
        void look() const;
        std::string getStringOutput() const;
    private:
};
#endif
