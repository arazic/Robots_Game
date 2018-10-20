//
// Created by ise on 28/12/17.
//

#ifndef ASSIGNMENT3_MAP_H
#define ASSIGNMENT3_MAP_H
#include <iostream>

using namespace std;

/*The Map has array of values.
 * If the value is 1, there is a wall in this position.
 * The map contains all the functionality that needed.
 * The game and the robot used in those methods to active the map.
*/
class Map
{
private:
    int m_map[7][7];
public:
    void initializeMap(int map[7][7]);
    Map operator+ (const Map& other) const;
    Map& operator+= (const Map& other);
    Map& operator= (const Map& other);
    bool operator== (const Map& other) const;
    int getValue(int x, int y) const;
    friend ostream& operator<< (ostream& out, const Map& other);
};

#endif //ASSIGNMENT3_MAP_H
