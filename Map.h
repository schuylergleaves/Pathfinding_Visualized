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

    bool isFilled(int x, int y);
    void setFilled(int x, int y, bool filled);

    Node* getNodeAt(int x, int y);

private:
    int length, width;
    Node ***grid;

    void  initializeGrid();
};

#endif // MAP_H
