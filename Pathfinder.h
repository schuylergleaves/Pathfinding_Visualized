#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "Map.h"
#include "Constants.h"
#include "QMainWindow"
#include "queue"
#include <QTimer>
#include <QObject>

/*
 * The pathfinder object will perform the selected pathfinding algorithm on the map.
 */
class Pathfinder : public QObject
{

public:
    Pathfinder(Map *map, QMainWindow *mainpage);
    void Run(Algorithm algorithm);

private:
    Map *map;
    QMainWindow *mainpage;

    /* algorithm implementations */
    Node* Breadth_First();

    /* helper functions */
    std::vector<Node*> getAdjecentNodes(Node* node);
    std::vector<Node*> generatePath(Node* pathEnd);
    void setPathNodes(std::vector<Node*> path);
};

#endif // PATHFINDER_H
