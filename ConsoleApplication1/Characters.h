#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#include "Point2D.h"

using namespace std;

class Character {
	string name;
	Point2D location;

public:
	Character(const std::string& name, const Point2D& location) : name(name), location(location) {}

	void MoveTo(int x, int y) {
		location.setPoint(x, y);
	}

	Point2D getLocation() {
		return location;
	}

};

class Prey : public Character {
    /*friend ostream& operator<<(ostream&, const Arena&);
    friend Predator;
    friend class Arena;*/
    

public:
    Prey(const std::string& name, const Point2D& location) : Character(name, location) {   }

    void MoveTo(int x, int y) {
        location.setPoint(x, y);
    }

    //void AutoMove(const Arena&, int z);

    /*friend ostream& operator<<(ostream& out, const Prey&);
    friend bool check(const Prey& prey, const Predator& predator);
    friend bool check1(const Prey& prey, const Predator& predator);*/
    int getx() {
        return location.x;
    }
    int gety() {
        return location.y;
    }
};
ostream& operator<<(ostream& out, const Prey& p) {
    out << "Имя жертвы - " << p.name << "Координаты жертвы - " << p.location << endl;
    return out;
}

class Predator : public Character {
private:
    /*friend Prey;
    friend class Arena;
    friend ostream& operator<<(ostream&, const Arena&);*/
  

public:
    Predator(const std::string& name, const Point2D& location) : Character(name, location) {   }

    void MoveTo(int x, int y) {
        location.setPoint(x, y);
    }
    void AutoMove(const Arena&, int z);
    friend ostream& operator<<(ostream&, const Predator&);
    friend bool check(const Prey& prey, const Predator& predator);
    friend bool check1(const Prey& prey, const Predator& predator);
};