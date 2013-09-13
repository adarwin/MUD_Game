#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
#include <vector>

class Creature;

class Room {
    public:
        Room(int name);
        Room(int name, int state);
        ~Room();
        Room *north;
        Room *south;
        Room *east;
        Room *west;
        int getState() const;
        int getName() const;
        std::string getStateString() const;
        static std::string getStateString(int state) {
            std::string output = "";
            if (state == dirty) {
                output = "dirty";
            } else if (state == half_dirty) {
                output = "half-dirty";
            } else if (state == clean) {
                output = "clean";
            }
            return output;
        }
        bool addCreature(Creature*);
        std::vector<Creature*> creatures;

    private:
        static const int maxNumCreatures = 10;
        void init(int name, int state);
        int state;
        int name;
        static const int dirty = 0;
        static const int half_dirty = 1;
        static const int clean = 2;
};
std::ostream& operator<< (std::ostream& out, const Room& obj);
#endif
