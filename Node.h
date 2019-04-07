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

    Node(){
        this->x = -1;
        this->y = -1;
    }

    int getX(){
        return this->x;
    }

    int getY(){
        return this->y;
    }

    bool isFilled(){
        return this->full;
    }

    void setFilled(bool full){
        this->full = full;
    }
};

#endif // NODE_H
