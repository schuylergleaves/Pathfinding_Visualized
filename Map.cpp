#include "Map.h"

/* Constructor */
Map::Map(int length, int width)
{
    this->length = length;
    this->width  = width;

    this->initializeGrid();
}

/* Grid is 3D array of pointers to nodes */
void Map::initializeGrid(){
    grid = new Node**[length];
    for(int i = 0; i < length; i++){
        grid[i] = new Node*[width];
    }

    for(int x = 0; x < length; x++){
        for(int y = 0; y < width; y++){
            grid[x][y] = new Node(x,y);
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
