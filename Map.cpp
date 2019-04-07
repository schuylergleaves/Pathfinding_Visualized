#include "Map.h"

/* Constructor */
Map::Map(int length, int width)
{
    this->length = length;
    this->width  = width;

    this->initializeGrid();
}

/* Grid is 3D array of pointers to nodes
   These nodes will be created with x and y equal to their rectangle counterparts */
void Map::initializeGrid(){
    grid = new Node**[length];
    for(int i = 0; i < length; i++){
        grid[i] = new Node*[width];
    }

    for(int i = 0; i < length; i++){
        for(int j = 0; j < width; j++){
            grid[i][j] = new Node(i,j);
        }
    }
}

void Map::setFilled(int x, int y, bool filled){
    Node* target = getNodeAt(x, y);
    target->setFilled(filled);
}

bool Map::isFilled(int x, int y){
    Node* target = getNodeAt(x, y);
    return target->isFilled();
}

Node* Map::getNodeAt(int x, int y){
    return this->grid[x][y];
}
