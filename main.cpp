#include <iostream>
#include "Game.h"

using namespace std;

int main()
{

    bool contin = true;
    Game* currGame = new Game();
    int mapNum, x, y, idOfRobot;
    char direction;

    while (contin)
    {
        cout << "Robot control menu:\n" <<"1.Add robot\n" <<"2.Delete robot\n" <<
             "3.Move robot\n" << "4.Operator +\n" << "5.Operator +=\n" <<
             "6.Operator =\n" << "7.Operator ==\n" <<  "8.Operator <<\n" << "9.Quit\n" << std::endl;
        cout << "Input your option: ";
        int option;
        cin >> option;

        switch (option)
        {
            case 1:
                cout << "Enter MAP number: ";
                cin >> mapNum;
                cout << "Enter coordinates (X, Y): ";
                cin >> x;
                cin >> y;
                currGame->AddRobot(mapNum, x, y);
                break;
            case 2:
                cout << "Enter Robot number: ";
                cin >> idOfRobot;
                currGame->DeleteRobot(idOfRobot);
                break;
            case 3:
                cout << "Enter Robot number: ";
                cin >> idOfRobot;
                cout << "Enter direction: ";
                cin >> direction;
                currGame->MoveRobot(idOfRobot, direction);
                break;
            case 4:
                currGame->operatorPlus();
                break;
            case 5:
                currGame->operatorPlusEqual();
                break;
            case 6:
                currGame->operatorEqual();
                break;
            case 7:
                if(currGame->operatorEqualEqual() == 0)
                    cout << "False" << std::endl;
                else
                    cout << "True" << std::endl;
                break;
            case 8:
                currGame->operatorCout();
                break;
            case 9:
                contin = false;
                delete(currGame);
                break;
            default:
                cout << "The option you type: " << option << " is not a valid option" << std::endl;
                cout << "Try again:" << std::endl;
        }
    }

    return 0;
}