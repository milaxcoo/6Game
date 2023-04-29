#include <iostream>
#include "Arena1.h"
#include <cassert>

using namespace std;

int main() {
    system("chcp 65001");

    string prey_name, predator_name;

    srand(time(NULL));

    Characters prey("prey", Point2D(5, 20), false); 
    Characters predator("predator", Point2D(3, 10), true);

    Characters* characters[2] = { &prey, &predator };

    Arena1 arena(30, 30, characters);

    cout << arena;

    for (int i = 0; i <= 40; i++) {
        arena.clearStep();

        Point2D prevPreyLocation(prey.getLocation());
        Point2D prevPredLocation(predator.getLocation());

        prey.autoMove();
        predator.autoMove();

        //unit test
        assert(prey.getLocation().getX() >= 0 && prey.getLocation().getX() <= 30);
        assert(prey.getLocation().getY() >= 0 && prey.getLocation().getY() <= 30);
        assert(predator.getLocation().getX() >= 0 && predator.getLocation().getX() <= 30);
        assert(predator.getLocation().getY() >= 0 && predator.getLocation().getY() <= 30);

        if (arena.checkOverRun())
        {
            prey.moveTo(prevPreyLocation);
            predator.moveTo(prevPredLocation);
        }

        cout << arena;

        system("timeout /t 1");

        system("cls");

        
    }

    cout << "Enter a name for your prey: ";

    cin >> prey_name;
    cout << "Enter a name for your predator: ";
    cin >> predator_name;

    cout << "За кого хотите играть? (0-жертва, 1-хищник)" << endl;
    int sideChoice;
    cin >> sideChoice;

    bool preyNpc = true;

    if (sideChoice == 0) {
        preyNpc = false;
    }
    else if (sideChoice == 1) {
        preyNpc = true;
    }
    else {
        cout << "Неверный ввод" << endl;
        return 0;
    }

}

//google test
TEST(Characters, move) {
    Characters prey("prey", Point2D(5, 20), false);
    Characters predator("predator", Point2D(3, 10), true);

    prey.autoMove();
    predator.autoMove();

    assert(prey.getLocation().getX() >= 0 && prey.getLocation().getX() <= 30);
    assert(prey.getLocation().getY() >= 0 && prey.getLocation().getY() <= 30);
    assert(predator.getLocation().getX() >= 0 && predator.getLocation().getX() <= 30);
    assert(predator.getLocation().getY() >= 0 && predator.getLocation().getY() <= 30);
}
