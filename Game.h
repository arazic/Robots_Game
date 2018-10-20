//
// Created by ise on 02/01/18.
//

#ifndef ASSIGNMENT3_GAME_H
#define ASSIGNMENT3_GAME_H
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "Map.h"
#include "Robot.h"


/*The Game has two maps and dynamic array of robots.
 * The game contains all the functionality of the robots and the maps.
 * The main used in those methods to active the program.
*/
class Game
{
private:
    Map map1, map2;
    static int currNumOfRobots; // The exactly robots number.
    Robot** RobotsInGameArr;
    bool validPlace(int mapNum, int x, int y);

public:
    Game();
    ~Game();
    bool AddRobot(int mapNum, int x, int y);
    bool DeleteRobot(int idOfRobot);
    bool MoveRobot(int idOfRobot, char direction);
    void operatorPlus();
    void operatorPlusEqual();
    void operatorEqual();
    bool operatorEqualEqual();
    void operatorCout();
    void printRobots(int mapNum);
    void printRobotInIndex(int indOfRobot);
};
#endif //ASSIGNMENT3_GAME_H
