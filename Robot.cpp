//
// Created by ise on 29/12/17.
//
#include "Robot.h"

using namespace std;

/*static parameter that keep the next free id to the next robot.
 * The first Id is 1 */
int Robot::nextIdOfRobots = 1;

/* Destructor to the robot*/
Robot::~Robot()
{
    m_id = 0;
    m_map = 0;
    m_x = 0;
    m_y = 0;
}

/* getter to the X position */
int Robot::GetX() const
{
    return m_x;
}


/* getter to the Y position */
int Robot::GetY() const
{
    return m_y;
}


/* getter to the id of the robot */
int Robot::GetId() const
{
    return m_id;
}


/* getter to the number map that the robot in it */
int Robot::GetMap() const
{
    return m_map;
}

/* setter to the X position */
void Robot::SetX(int x)
{
    m_x = x;
}

/* setter to the Y position */
void Robot::SetY(int y)
{
    m_y = y;
}

/*The function move the robot if it by the rules.
 * It get the wanted direction to move.
 * If the robot already get out from the board map- it won't move.
 * else it will move to the wanted direction */
bool Robot::MoveRobot(char direction)
{
    if (m_x == -1 || m_y == -1)
    {
        return false;
    }

    switch(direction)
    {
        case 'U':
            m_y--;
            break;
        case 'D':
            m_y++;
            break;
        case 'L':
            m_x--;
            break;
        case 'R':
            m_x++;
            break;
        default:
            break;
    }
    return true;
}
