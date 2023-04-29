#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include "Point2D.h"

//google test
#include "gtest/gtest.h"

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

TEST(Characters, Prey) {
    Point2D location(0, 0);
    Prey prey("Prey", location, false);
    EXPECT_EQ(prey.getName(), "Prey");
    EXPECT_EQ(prey.getLocation(), location);
    EXPECT_EQ(prey.getNpc(), false);
    prey.setName("Prey2");
    EXPECT_EQ(prey.getName(), "Prey2");
    prey.setLocation(Point2D(1, 1));
    EXPECT_EQ(prey.getLocation(), Point2D(1, 1));
    prey.setNpc(true);
    EXPECT_EQ(prey.getNpc(), true);
    prey.moveTo(Point2D(2, 2));
    EXPECT_EQ(prey.getLocation(), Point2D(2, 2));
    prey.autoMove();
    EXPECT_EQ(prey.getLocation(), Point2D(2, 2));
}

TEST(Characters, Predator) {
    Point2D location(0, 0);
    Predator predator("Predator", location, false);
    EXPECT_EQ(predator.getName(), "Predator");
    EXPECT_EQ(predator.getLocation(), location);
    EXPECT_EQ(predator.getNpc(), false);
    predator.setName("Predator2");
    EXPECT_EQ(predator.getName(), "Predator2");
    predator.setLocation(Point2D(1, 1));
    EXPECT_EQ(predator.getLocation(), Point2D(1, 1));
    predator.setNpc(true);
    EXPECT_EQ(predator.getNpc(), true);
    predator.moveTo(Point2D(2, 2));
    EXPECT_EQ(predator.getLocation(), Point2D(2, 2));
    predator.autoMove();
    EXPECT_EQ(predator.getLocation(), Point2D(2, 2));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}