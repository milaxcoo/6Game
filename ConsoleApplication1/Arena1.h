#include <iostream>
#include "Characters1.h"

class Arena1 {
    int length, width;
    Characters** characters;
    int view_length, view_width;
    char** field;
public:

    Arena1(int l, int w, Characters** characters);
    void clearStep();
    bool checkOverRun();
    ~Arena1();
    friend std::ostream& operator<<(std::ostream&, const Arena1&);
};

bool check(const Characters& prey, const Characters& predator) {
    if (prey.location.x == predator.location.x && abs(prey.location.y - predator.location.y) <= 5) {
        return 1;
    }
    else if (prey.location.y == predator.location.y && abs(prey.location.x - predator.location.x) <= 5) {
        return 1;
    }
    else return 0;
}
