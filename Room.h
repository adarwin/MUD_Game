#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
#include <vector>
#include <list>

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
        bool removeCreature(Creature*);
        std::vector<Creature*> creatures;
        void cleanRoom();
        void dirtyRoom();
        int state;
        bool isFull() const;
        static const int clean = 0;
        static const int half_dirty = 1;
        static const int dirty = 2;

    private:
        void notifyCreatures(int, int);
        static const unsigned int maxNumCreatures = 10;
        void init(int name, int state);
        int name;
};
std::ostream& operator<< (std::ostream& out, const Room& obj);
#endif
