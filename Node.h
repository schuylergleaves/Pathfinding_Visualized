#ifndef NODE_H
#define NODE_H

/*
 * This data structure will represent a node in the map.
 */
struct Node {
    int  x,y;
    bool full;

    Node(int x, int y){
        this->x = x;
        this->y = y;
        this->full = false;
    }

    bool isFull(){
        return this->full;
    }

    void setFull(bool full){
        this->full = full;
    }
};

#endif // NODE_H
