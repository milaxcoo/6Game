#include <iostream>
#include "Characters1.h"
#include "Arena1.h"


using namespace std;

int main() {
    system("chcp 65001");

    string prey_name, predator_name;

    srand(time(NULL));

    Characters prey("prey", Point2D(5, 20), true);
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