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

    for(int row = 0; row < length; row++){
        for(int col = 0; col < width; col++){
            grid[row][col] = new Node(row,col);
        }
    }
}

/* sets all nodes back to default state */
void Map::reset(){
    for(int row = 0; row < length; row++){
        for(int col = 0; col < width; col++){
            grid[row][col]->setPath(false);
            grid[row][col]->setWall(false);
            grid[row][col]->setAccessed(false);
            grid[row][col]->setEditable(true);
            grid[row][col]->setParent(nullptr);
        }
    }
}

void Map::setWall(int row, int col, bool filled){
    Node* target = getNodeAt(row, col);
    target->setWall(filled);
}

bool Map::isWall(int row, int col){
    Node* target = getNodeAt(row, col);
    return target->isWall();
}

Node* Map::getNodeAt(int row, int col){
    if(row < 0 || row >= MAP_LENGTH)
        return nullptr;

    if(col < 0 || col >= MAP_WIDTH)
        return nullptr;

    return this->grid[row][col];
}
