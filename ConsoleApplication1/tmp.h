#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <Windows.h>

using namespace std;

class Character {
	string name;
	Point2D location;

public:
	Character(const std::string& name, const Point2D& location) : name(name), location(location) {}

	void MoveTo(int x, int y) {
		location.setPoint(x, y);
	}


};

