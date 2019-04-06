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

    bool isFilled(int x, int y);
    void setFilled(int x, int y, bool filled);

private:
    int length, width;
    Node ***grid;

    void  initializeGrid();
    Node* getNodeAt(int x, int y);

};

#endif // MAP_H
