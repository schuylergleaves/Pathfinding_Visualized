#ifndef MAP_H
#define MAP_H

#include "Node.h"
#include "Constants.h"

/*
 * The Map will hold all the nodes (and info) representing the current program state.
 */
class Map
{

public:
    Map(int length, int width);

    bool isWall(int row, int col);
    void setWall(int row, int col, bool filled);

    Node* getNodeAt(int row, int col);

private:
    int length, width;
    Node ***grid;

    void  initializeGrid();
};

#endif // MAP_H
