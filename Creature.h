#ifndef CREATURE_H
#define CREATURE_H
#include <string>

class Room;

class Creature {
    public:
        Creature(int);
        Creature(int, Room*);
        ~Creature();
        int getName() const;
        virtual void issuePositiveResponse() const;
        virtual void issueNegativeResponse() const;
        virtual void look() const;
        Room* currentRoom;
        virtual std::string getType() const;
        std::string getStringOutput() const;

    private:
        void init(int name, Room* room);
        int name;
        //string description;
};
#endif
