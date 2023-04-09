#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include "Point2D.h"

class Characters {
public:
    std::string name;
    Point2D location;
    bool npc;

    Characters(std::string name, Point2D location, bool npc) : name(name), location(location), npc(npc) {  }
    virtual void autoMove() = 0;
    void moveTo(Point2D location) {
        this->location = location;
    }
    Point2D getLocation() {
        return location;
    }
    Point2D setLocation(Point2D location) {
        return this->location = location;
    }
    std::string getName() {
        return name;
    }
    bool getNpc() {
        return npc;
    }
    void setNpc(bool npc) {
        this->npc = npc;
    }
    void setName(std::string name) {
        this->name = name;
    }
    friend std::ostream& operator<<(std::ostream& out, const Characters& character) {
        out << character.name << " " << character.location;
        return out;
    }
};

class Prey : public Characters {
public:
    Prey(std::string name, Point2D location, bool npc) : Characters(name, location, npc) {  }
    void autoMove() {
        int x = location.getX();
        int y = location.getY();
        int direction = rand() % 4;
        switch (direction) {
        case 0:
            x++;
            break;
        case 1:
            x--;
            break;
        case 2:
            y++;
            break;
        case 3:
            y--;
            break;
        }
        location.setPoint(x, y);
    }
};

class Predator : public Characters {
public:
    Predator(std::string name, Point2D location, bool npc) : Characters(name, location, npc) {  }
    void autoMove() {
        int x = location.getX();
        int y = location.getY();
        int direction = rand() % 4;
        switch (direction) {
        case 0:
            x++;
            break;
        case 1:
            x--;
            break;
        case 2:
            y++;
            break;
        case 3:
            y--;
            break;
        }
        location.setPoint(x, y);
    }
};
