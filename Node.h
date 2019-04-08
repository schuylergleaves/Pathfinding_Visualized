#ifndef NODE_H
#define NODE_H

/*
 * This data structure will represent a node in the map.
 */
struct Node {
    /* Member Variables */
    int  row,col;
    bool editable, wall, accessed, path;

    //parent is used to determine the path to an object within pathfinding algorithms
    Node* parent = nullptr;

    /*
     * CONSTRUCTORS
     */
    Node(int row, int col){
        this->row = row;
        this->col = col;

        this->wall     = false;
        this->accessed = false;
        this->editable = true;
        this->path     = false;

    }

    Node(int row, int col, bool editable){
        this->row = row;
        this->col = col;

        this->wall     = false;
        this->accessed = false;
        this->editable = editable;
        this->path     = false;
    }

    Node(){
        this->row = -1;
        this->col = -1;

        this->wall     = false;
        this->accessed = false;
        this->editable = false;
        this->path     = false;
    }



    /*
     * FUNCTIONS
     */
    int getRow(){
        return this->row;
    }

    int getCol(){
        return this->col;
    }

    bool isWall(){
        return this->wall;
    }

    bool isEditable(){
        return this->editable;
    }

    bool isAccessed(){
        return this->accessed;
    }

    bool isPath(){
        return this->path;
    }

    void setEditable(bool editable){
        this->editable = editable;
    }

    void setWall(bool wall){
        if(this->isEditable())
            this->wall = wall;
    }

    void setAccessed(bool accessed){
        if(this->isEditable())
            this->accessed = accessed;
    }

    void setPath(bool path){
        if(this->isEditable())
            this->path = path;
    }

    void setParent(Node* parent){
        this->parent = parent;
    }

    Node* getParent(){
        return this->parent;
    }
};

#endif // NODE_H
