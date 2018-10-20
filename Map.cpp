//
// Created by ise on 28/12/17.
//
#include "Map.h"

using namespace std;

/*Initialize the map with the beginning values
 * The function get array with values and initialize the current map  */
void Map::initializeMap(int map[7][7])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            m_map[i][j] = map[i][j];
        }
    }
}

/*The function implement the operator + to map's object.
 * It get map dereference and it copy the walls from the parameter map to a new map.
 * It return the new map after the merge */
Map Map::operator+ (const Map& other) const
{
    Map ans;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (this->m_map[i][j] == 0 && other.m_map[i][j] == 0)
                ans.m_map[i][j] = 0;
            if (this->m_map[i][j] == 1 && other.m_map[i][j] == 1)
                ans.m_map[i][j] = 1;
            if ((this->m_map[i][j] == 1 && other.m_map[i][j] == 0) || (this->m_map[i][j] == 0 && other.m_map[i][j] == 1))
                ans.m_map[i][j] = 1;
        }
    }
    return ans;
}

/*The function implement the operator += to map's object.
 * It get map dereference and copy the walls to the current map.
 * It return dereference to the current map.
 * In this way it changes the map that the operator active on */
Map& Map::operator+= (const Map& other)
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (other.m_map[i][j] == 1)
            {
                this->m_map[i][j] = 1;
            }
        }
    }
    return *this;
}

/*The function implement the operator = to map's object.
 * It get map dereference and copy all the values to the current map.
 * It return dereference to the current map
 * In this way it changes the map that the operator active on */
Map& Map::operator= (const Map& other)
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            this->m_map[i][j] = other.m_map[i][j];
        }
    }
    return *this;
}

/*The function implement the operator == to map's object.
 * It get map parameter and check if all the values are the same
 * like the current map values.
 * It return True if the maps are identical or False otherwise */
bool Map::operator== (const Map& other) const
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if(this->m_map[i][j] != other.m_map[i][j])
                return false;
        }
    }
    return true;
}

/*The function get a current position in the map.
 * The function return the map's value in the same position,
 * Or -1 if the position is not in the map board */
int Map::getValue(int x, int y) const
{
    if ((x < 7 && x >= 0) && (y < 7 && y >= 0))
        return this->m_map[y][x];
    return -1;
}


/*The function implement the operator << to map's object.
 * It get Ostream object and map dereference and print the map's values. */

ostream& operator<< (ostream& out, const Map& m)
{
    out<< "["<< m.m_map[0][0] << " "<<m.m_map[0][1] << " "<<m.m_map[0][2] << " "<<m.m_map[0][3] << " "<<m.m_map[0][4]<< " "<<m.m_map[0][5] << " "<<m.m_map[0][6]<< "]\n"
       << "["<<m.m_map[1][0] << " "<<m.m_map[1][1] << " "<<m.m_map[1][2] << " "<<m.m_map[1][3] << " "<<m.m_map[1][4]<< " "<<m.m_map[1][5] << " "<<m.m_map[1][6]<< "]\n"
       << "["<<m.m_map[2][0] << " "<<m.m_map[2][1] << " "<<m.m_map[2][2] << " "<<m.m_map[2][3] << " "<<m.m_map[2][4]<< " "<<m.m_map[2][5] << " "<<m.m_map[2][6]<< "]\n"
       << "["<<m.m_map[3][0] << " "<<m.m_map[3][1] << " "<<m.m_map[3][2] << " "<<m.m_map[3][3] << " "<<m.m_map[3][4]<< " "<<m.m_map[3][5] << " "<<m.m_map[3][6]<< "]\n"
       << "["<<m.m_map[4][0] << " "<<m.m_map[4][1] << " "<<m.m_map[4][2] << " "<<m.m_map[4][3] << " "<<m.m_map[4][4]<< " "<<m.m_map[4][5] << " "<<m.m_map[4][6]<< "]\n"
       << "["<<m.m_map[5][0] << " "<<m.m_map[5][1] << " "<<m.m_map[5][2] << " "<<m.m_map[5][3] << " "<<m.m_map[5][4]<< " "<<m.m_map[5][5] << " "<<m.m_map[5][6]<< "]\n"
       << "["<<m.m_map[6][0] << " "<<m.m_map[6][1] << " "<<m.m_map[6][2] << " "<<m.m_map[6][3] << " "<<m.m_map[6][4]<< " "<<m.m_map[6][5] << " "<<m.m_map[6][6]<< "]\n";
    return out;
}
