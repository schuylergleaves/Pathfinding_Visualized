#ifndef MAP_H
#define MAP_H

#include "Node.h"

/*
 * The Map will hold all the nodes (and info) representing the current program state.
 */
class Map
{

public:
    Map(int length, int width);

private:
    int length, width;

};

#endif // MAP_H
