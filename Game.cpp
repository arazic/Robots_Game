//
// Created by ise on 02/01/18.
//
#include "Game.h"


using namespace std;

/*static parameter that count the robot's number.
 * The parameter start to count from 0. */
int Game::currNumOfRobots = 0;

/* Initial values to the first map. */
int init1_map [7][7] = {{1, 1, 1, 1, 1 ,1, 1},
                        {1, 0, 0, 0, 1 ,0, 1},
                        {0, 0, 1, 1, 1, 0, 1},
                        {1, 0, 0, 0, 0, 0, 1},
                        {1, 1, 1, 0, 1, 0, 1},
                        {1, 0, 0, 0, 0, 0, 1},
                        {1, 0, 1, 1, 1, 1, 1}};

/* Initial values to the second map. */
int init2_map [7][7] = {{1 ,1 ,1 ,0 ,1 ,1 ,1},
                        {1 ,0 ,0 ,0 ,0 ,0 ,1},
                        {1 ,0 ,1 ,0 ,1 ,0 ,1},
                        {0 ,0 ,0 ,0 ,0 ,0 ,0},
                        {1 ,0 ,0 ,0 ,0 ,0 ,1},
                        {1 ,0 ,0 ,0 ,0 ,0 ,1},
                        {1 ,1 ,1 ,1 ,0 ,1 ,1}};



/* Constructor to the game.
 * Initial the maps values
 *  and make the robot's array to point on NULL */

Game::Game(){
    map1.initializeMap(init1_map);
    map2.initializeMap(init2_map);

    RobotsInGameArr = NULL;
}

/* Destructor to the game.
 * Destruct all the robots in the robot's array.
 * In the end destruct the array's pointer*/
Game::~Game(){
    if(RobotsInGameArr!=NULL){
        for (int i = 0; i < currNumOfRobots; i++)
        {
            delete(RobotsInGameArr[i]);
        }
        free(RobotsInGameArr);
    }
}

/* The function add robot to the game.
 * It get the number of the map that the robot should play in and the position coordinate (x.y).
 * It check if it legal place and if it is-it expend the array to the new size
 * and add the robot to the end of the array (to save the array sorted).
 * It return True if the added function success or false otherwise.*/
bool Game::AddRobot(int mapNum, int new_x, int new_y)
{
    if (validPlace(mapNum, new_x, new_y))
    {
        currNumOfRobots++;
        RobotsInGameArr = (Robot**)realloc(this->RobotsInGameArr, (currNumOfRobots) * sizeof(Robot*));
        if (RobotsInGameArr != NULL)
        {
            RobotsInGameArr[currNumOfRobots - 1] = new Robot(mapNum, new_x, new_y);
            cout << "New ";
            printRobotInIndex(currNumOfRobots - 1);
            return true;
        }
        currNumOfRobots--;
    }
    return false;
}

/* The function  robot to the game.
 * It get the number of the robot we should delete.
 * It check if the robot indeed exist. If it is, it delete the current robot.
 * It shift all the rest array to the left (to keep the array sorted), and decrease
 * the array to the new size.
 * It return True if the delete function success or false otherwise.*/
bool Game::DeleteRobot(int idOfRobot)
{
    if (RobotsInGameArr != NULL)
    {
        for (int i = 0; i < currNumOfRobots; i++)
        {
            if (this->RobotsInGameArr[i]->GetId() == idOfRobot)
            {
                if (this->RobotsInGameArr[i]->GetX() != -1 && this->RobotsInGameArr[i]->GetY() != -1)
                {
                    cout << "Deleted ";
                    printRobotInIndex(i);
                    delete(this->RobotsInGameArr[i]);
                    for (int j = i; j < currNumOfRobots - 1; j++)
                    {
                        this->RobotsInGameArr[j] = this->RobotsInGameArr[j + 1];
                    }
                    currNumOfRobots--;
                    this->RobotsInGameArr[currNumOfRobots] = NULL;
                    RobotsInGameArr = (Robot**)realloc(this->RobotsInGameArr, (currNumOfRobots) * sizeof(Robot*));

                    return true;
                }
            }
        }
    }
    return false;
}

/* The function move robot to another place in the game.
 * It get id's robot and direction to move.
 * It check if the robot indeed inside the map (not in (-1,-1) position).
 * If it is, it check if the new place is legal. If It is it moved the robot.
 * It return True if the move function success or false otherwise.*/
bool Game::MoveRobot(int idOfRobot, char direction)
{
    if (RobotsInGameArr != NULL)
    {
        for (int i = 0; i < currNumOfRobots; i++)
        {
            if (this->RobotsInGameArr[i]->GetId() == idOfRobot)
            {
                if (validPlace(this->RobotsInGameArr[i]->GetMap(), this->RobotsInGameArr[i]->GetX(), this->RobotsInGameArr[i]->GetY()))
                {
                    int x = this->RobotsInGameArr[i]->GetX();
                    int y = this->RobotsInGameArr[i]->GetY();
                    switch (direction)
                    {
                        case 'U':
                            y--;
                            break;
                        case 'D':
                            y++;
                            break;
                        case 'L':
                            x--;
                            break;
                        case 'R':
                            x++;
                            break;
                        default:
                            cout << "Not valid direction" << std::endl;
                            break;
                    }

                    if (validPlace(this->RobotsInGameArr[i]->GetMap(), x, y))
                    {
                        if (this->RobotsInGameArr[i]->MoveRobot(direction))
                        {
                            printRobotInIndex(i);
                            return true;
                        }
                    }
                    else if (x < 0 || y < 0 || x > 6 || y > 6)
                    {
                        this->RobotsInGameArr[i]->SetX(-1);
                        this->RobotsInGameArr[i]->SetY(-1);
                    }
                }
                printRobotInIndex(i);
            }
        }
    }
    return false;
}


/* The function check if some place is legal.
 * It get map number and a position (x and y coordinates).
 * It check if indeed inside the map limits and if there is no wall in this place (there is no 1).
 * It return True if the place in legal and false otherwise.*/
bool Game::validPlace(int mapNum, int new_x, int new_y)
{
    if (new_x < 0 || new_y < 0 || new_x > 6 || new_y > 6)
    {
        cout << "Invalid location" << std::endl;
        cout << "\n";
        return false;
    }
    if (mapNum == 1)
    {
        if (map1.getValue(new_x, new_y) == 1)
        {
            cout << "Invalid location: " << new_x << ", " << new_y << " contains a wall" << std::endl;
            cout << "\n";
            return false;
        }
        return true;
    }
    else
    {
        if (map2.getValue(new_x, new_y) == 1)
        {
            cout << "Invalid location: " << new_x << ", " << new_y << " contains a wall" << std::endl;
            cout << "\n";
            return false;
        }
        return true;
    }
}

/* The function print the robots array or part of it.
 * It get map number or zero.
 * If it get valid map number it will print the robots in this map.
 * If it will get zero it will print all the robots (in the two maps).*/
void Game::printRobots(int mapNum)
{
    if (mapNum == 0)
    {
        for (int i = 0; i < currNumOfRobots; i++)
        {
            cout << "Robot: " << RobotsInGameArr[i]->GetId() << "  Map: " <<RobotsInGameArr[i]->GetMap() << "  GPS: " << RobotsInGameArr[i]->GetX()
                 << "," << RobotsInGameArr[i]->GetY() << std::endl;
        }
    }
    if (mapNum == 1)
    {
        for (int i = 0; i < currNumOfRobots; i++)
        {
            if (RobotsInGameArr[i]->GetMap() == 1)
                cout << "Robot: " << RobotsInGameArr[i]->GetId() << "  Map: " <<RobotsInGameArr[i]->GetMap() << "  GPS: " << RobotsInGameArr[i]->GetX()
                     << "," << RobotsInGameArr[i]->GetY() << std::endl;
        }
    }
    else
    {
        for (int i = 0; i < currNumOfRobots; i++)
        {
            if (RobotsInGameArr[i]->GetMap() == 2)
                cout << "Robot: " << RobotsInGameArr[i]->GetId() << "  Map: " <<RobotsInGameArr[i]->GetMap() << "  GPS: " << RobotsInGameArr[i]->GetX()
                     << "," << RobotsInGameArr[i]->GetY() << std::endl;
        }
    }
}

/* The function print current robot.
 * It get robot id and print it .*/
void Game::printRobotInIndex(int indOfRobot)
{
    cout << "Robot: " << RobotsInGameArr[indOfRobot]->GetId() << "  Map: " <<RobotsInGameArr[indOfRobot]->GetMap() << "  GPS: "
         << RobotsInGameArr[indOfRobot]->GetX() << "," << RobotsInGameArr[indOfRobot]->GetY() << std::endl;
    cout << std::endl;
}

/*The function implement the operator + to map's object.
 * It ask the user on which map to do the operation.
 * It does not save the map after the print*/
void Game::operatorPlus()
{
    int mapNum;
    Map newMap;
    cout << "Which is the left map? press 1/2: ";
    cin >> mapNum;
    if (mapNum == 1)
    {
        newMap = map1 + map2;
        cout << newMap;
    }
    else
    {
        newMap = map2 + map1;
        cout << newMap;
    }
    for (int i = 0; i < currNumOfRobots; i++)
    {
        if (newMap.getValue(RobotsInGameArr[i]->GetX(), RobotsInGameArr[i]->GetY()) == 0)
        {
            printRobotInIndex(i);
        }
    }
}

/*The function implement the operator += to map's object.
 * It ask the user on which map to do the operation.
 * It change the map as it supposed to in the operator function
 * It delete the robots that where on a wall */
void Game::operatorPlusEqual()
{
    int mapNum;
    cout << "Which is the map to add to? press 1/2: ";
    cin >> mapNum;
    if (mapNum == 1)
    {
        map1 += map2;
        for (int i = 0; i < currNumOfRobots; i++)
        {
            if (RobotsInGameArr[i]->GetMap() == 1)
            {
                if (map1.getValue(RobotsInGameArr[i]->GetX(), RobotsInGameArr[i]->GetY()) == 1)
                {
                    DeleteRobot(RobotsInGameArr[i]->GetId());
                    i--;
                }
            }
        }
    }
    else
    {
        map2 += map1;
        for (int i = 0; i < currNumOfRobots; i++)
        {
            if (RobotsInGameArr[i]->GetMap() == 2)
            {
                if (map2.getValue(RobotsInGameArr[i]->GetX(), RobotsInGameArr[i]->GetY()) == 1)
                {
                    DeleteRobot(RobotsInGameArr[i]->GetId());
                    i--;
                }
            }
        }
    }
}

/*The function implement the operator = to map's object.
 * It ask the user on which map to do the operation.
 * It change the map as it supposed to in the operator function
 * It delete the robots that where on a wall */
void Game::operatorEqual()
{
    int mapNum;
    cout << "Which map to copy to? press 1/2: ";
    cin >> mapNum;
    if (mapNum == 1)
    {
        map1 = map2;
        for (int i = 0; i < currNumOfRobots; i++)
        {
            if (RobotsInGameArr[i]->GetMap() == 1)
            {
                if (map1.getValue(RobotsInGameArr[i]->GetX(), RobotsInGameArr[i]->GetY()) == 1)
                {
                    DeleteRobot(RobotsInGameArr[i]->GetId());
                    i--;
                }
            }
        }
    }
    else
    {
        map2 = map1;
        for (int i = 0; i < currNumOfRobots; i++)
        {
            if (RobotsInGameArr[i]->GetMap() == 2)
            {
                if (map2.getValue(RobotsInGameArr[i]->GetX(), RobotsInGameArr[i]->GetY()) == 1)
                {
                    DeleteRobot(RobotsInGameArr[i]->GetId());
                    i--;
                }
            }
        }
    }
}

/*The function implement the operator == to map's object.
 * It return True if the maps are identical or False otherwise */
bool Game::operatorEqualEqual()
{
    return map1 == map2;
}


/*The function implement the operator << to map's object.
 * It ask the user on which map to do the operation.
 * It print the map's values. */
void Game::operatorCout()
{
    int mapNum;
    cout << "Please enter map number: ";
    cin >> mapNum;
    if (mapNum == 1)
    {
        cout << map1;
        cout << std::endl;
    }
    else
    {
        cout << map2;
        cout << std::endl;
    }
    printRobots(mapNum);
}
