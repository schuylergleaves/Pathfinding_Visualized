#include "Pathfinder.h"

/* constructor */
Pathfinder::Pathfinder(Map *map, QMainWindow *mainpage)
{
    this->map      = map;
    this->mainpage = mainpage;
}

void Pathfinder::Run(Algorithm algorithm){
    Node* pathEnd;
    switch(algorithm){
        case BREADTH_FIRST:
            pathEnd = this->Breadth_First();
            break;
    }

    //generate path returned from algo and set properties of nodes within (so UI can update them)
    std::vector<Node*> path = generatePath(pathEnd);
    setPathNodes(path);

    //update page to reflect new path
    mainpage->update();

}





/*
 * =====================================
 * ===== ALGORITHM IMPLEMENTATIONS =====
 * =====================================
 */

Node* Pathfinder::Breadth_First(){

    //setting up visited array
    bool **visited = new bool*[MAP_LENGTH];

    for(int i = 0; i < MAP_LENGTH; i++)
        visited[i] = new bool[MAP_WIDTH];

    for(int i = 0; i < MAP_LENGTH; i++)
        for(int j = 0; j < MAP_WIDTH; j++)
            visited[i][j] = false;

    //setup pointers to start and end
    Node *start = map->getNodeAt(STARTNODE_ROW, STARTNODE_COL);
    Node *end   = map->getNodeAt(ENDNODE_ROW, ENDNODE_COL);

    //add start to queue
    std::queue<Node*> queue;
    queue.push(start);

    //BFS logic
    while(!queue.empty()){
        Node *curr = queue.front();
        visited[STARTNODE_ROW][STARTNODE_COL] = true;
        queue.pop();

        if(curr == end){
            return end;
        }

        for(auto &node: getAdjecentNodes(curr)){
            if(!visited[node->getRow()][node->getCol()]){
                visited[node->getRow()][node->getCol()] = true;
                node->setParent(curr);
                queue.push(node);

                //set accessed so that UI can render node as being accessed
                //node->setAccessed(true);
            }
        }
    }
}





/*
 * ============================
 * ===== HELPER FUNCTIONS =====
 * ============================
 */

/* will return all adjacent (and valid to be used in path) nodes to a given node */
std::vector<Node*> Pathfinder::getAdjecentNodes(Node* node){
    std::vector<Node*> adjacentNodes;

    int nodeRow = node->getRow();
    int nodeCol = node->getCol();

    /* ALLOWS DIAGONAL PATHS */
//    //checks 8 surrounding nodes and adds to adjacent if they are valid (ie: not walls)
//    for(int row = nodeRow - 1; row < nodeRow + 2; row++){
//        for(int col = nodeCol - 1; col < nodeCol + 2; col++){
//            Node* possible = map->getNodeAt(row, col);

//            if(possible != nullptr && possible != node && !possible->isWall())
//                adjacentNodes.push_back(possible);
//        }
//    }

    /* DOES NOT ALLOW DIAGONAL PATHS */
    Node *up    = map->getNodeAt(nodeRow - 1, nodeCol);
    Node *right = map->getNodeAt(nodeRow, nodeCol + 1);
    Node *down  = map->getNodeAt(nodeRow + 1, nodeCol);
    Node *left  = map->getNodeAt(nodeRow, nodeCol - 1);

    if(up != nullptr && !up->isWall())
        adjacentNodes.push_back(up);

    if(right != nullptr && !right->isWall())
        adjacentNodes.push_back(right);

    if(down != nullptr && !down->isWall())
        adjacentNodes.push_back(down);

    if(left != nullptr && !left->isWall())
        adjacentNodes.push_back(left);


    return adjacentNodes;
}

/* returns array of nodes within a path by going backwards from end node */
std::vector<Node*> Pathfinder::generatePath(Node* pathEnd){
    std::vector<Node*> pathNodes;

    Node* itr = pathEnd;
    while(itr != nullptr){
        pathNodes.push_back(itr);
        itr = itr->getParent();
    }

    return pathNodes;
}

/* sets path property of all nodes within this path */
void Pathfinder::setPathNodes(std::vector<Node*> path){
    for(auto &node: path)
        node->setPath(true);
}
