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
        virtual void issuePositiveResponse();
        virtual void issueNegativeResponse();
        virtual void look() const;
        Room* currentRoom;
        virtual std::string getType() const;
        std::string getStringOutput() const;
        virtual void clean();
        virtual bool happyAboutStateChange(int, int) const = 0;
        bool moveToRoom(Room*);
        bool respondToStateChange(int, int);
        void leaveRoom();
        void fixRoom();

    private:
        void init(int name, Room* room);
        int name;
        //string description;
};
#endif
