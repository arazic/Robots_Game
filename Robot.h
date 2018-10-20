
//
// Created by ise on 29/12/17.
//
#ifndef ASSIGNMENT3_ROBOT_H
#define ASSIGNMENT3_ROBOT_H
#include <iostream>

/*The Robot has id, number of map it inside and a position.
 * It also has static parameter of the next id robot.
 * The robot contains all the functionality that needed.
 * The game and the map used in those methods to active the robot.
*/
class Robot
{

private:
    int m_id;
    int m_map;
    int m_x;
    int m_y;
    static int nextIdOfRobots;
public:
    Robot(int map, int x, int y): m_map(map), m_x(x), m_y(y)
    {m_id = nextIdOfRobots;
        nextIdOfRobots++;}
    ~Robot();
    int GetId() const;
    int GetMap() const;
    int GetX() const;
    int GetY() const;
    void SetX(int x);
    void SetY(int y);
    bool MoveRobot(char direction);

};


#endif //ASSIGNMENT3_ROBOT_H
