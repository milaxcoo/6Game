#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include "Arena.h"

using namespace std;

int main() {
    system("chcp 65001");

    string prey_name, predator_name;

    srand(time(NULL));

    Prey prey("prey", Point2D(5, 20), true);
    Predator predator("predator", Point2D(3, 10), true);

    Arena arena(30, 20, &prey, &predator);

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
    if (sideChoice == 0) preyNpc = false;

    Prey prey(prey_name, Point2D(1, 1), preyNpc);
    Predator predator(predator_name, Point2D(7, 1), !preyNpc);

    prey.autoMove();
    predator.autoMove();


    Arena arena(10, 10, &prey, &predator);
    cout << arena << endl;


    while (1) {
       
       if (sideChoice == 0) {
           if (check(prey, predator)) {
               
               predator.moveTo(prey.getX(), prey.getY());
               
               cout << arena;
               cout << "\n!!!!!! ХИЩНИК ПОБЕДИЛ !!!!!!" << endl;
               return 0;
           }
           else {
               prey.autoMove(arena, sideChoice);
               predator.autoMove(arena, sideChoice);
               cout << arena << endl;
           }
       }
       
       else {
           if (check1(prey, predator)) {
               cout << "\n!!!!!! ХИЩНИК ПОБЕДИЛ !!!!!!" << endl;
               return 0;
           }
           else {
               prey.autoMove(arena, sideChoice);
               predator.autoMove(arena, sideChoice);
               cout << arena << endl;
           }
       }
    }



    return 0;
}

bool check(Prey& prey, Predator& predator) {
    return prey.getx() == predator.getx() && prey.gety() == predator.gety();
}

bool check1(Prey& prey, Predator& predator) {
    return prey.getx() == predator.getx() && prey.gety() == predator.gety();
}

