#include "Visualization.h"
#include "ui_Visualization.h"

/* Constructor */
Visualization::Visualization(QWidget *parent) : QMainWindow(parent), ui(new Ui::Visualization)
{
    ui->setupUi(this);
    this->init();
}

/* Destructor */
Visualization::~Visualization()
{
    delete ui;
}

/* Initialization */
void Visualization::init(){
    //map init - creates all nodes; set start & end nodes
    map = new Map(MAP_LENGTH, MAP_WIDTH);

    //create rectangle for each node in map
    rectangles = new QRect*[MAP_LENGTH];
    for(int i = 0; i < MAP_LENGTH; i++){
        rectangles[i] = new QRect[MAP_WIDTH];
    }

    for(int row = 0; row < MAP_LENGTH; row++){
        for(int col = 0; col < MAP_LENGTH; col++){
            //creates grid based on starting x and y, and current position in map
            rectangles[row][col] = QRect(MAP_STARTING_X + (col * RECT_WIDTH), MAP_STARTING_Y + (row * RECT_WIDTH), RECT_WIDTH, RECT_WIDTH);
        }
    }

    //pathfinder inti - must pass pointer to this so that pathfinder can update ui
    pathfinder = new Pathfinder(map, this);
}




/*
 * ========================
 * ===== UI FUNCTIONS =====
 * ========================
 */

/* draws grid map to UI (converting each node into a rectangle of relavent color) */
void Visualization::drawMap(QPainter *painter){
    painter->setPen(Qt::black);

    for(int row = 0; row < MAP_LENGTH; row++){
        for(int col = 0; col < MAP_WIDTH; col++){
            Node* target = map->getNodeAt(row, col);

            painter->drawRect(rectangles[row][col]);

            if(target->isWall())
                painter->fillRect(rectangles[row][col], Qt::black);

            if(target->isAccessed())
                painter->fillRect(rectangles[row][col], Qt::lightGray);

            if(target->isPath())
                painter->fillRect(rectangles[row][col], Qt::blue);
        }
    }

    //handle start rectangle
    map->getNodeAt(STARTNODE_ROW, STARTNODE_COL)->setEditable(false);
    painter->fillRect(rectangles[STARTNODE_ROW][STARTNODE_COL], Qt::green);

    //handle end rectangle
    map->getNodeAt(ENDNODE_ROW, ENDNODE_COL)->setEditable(false);
    painter->fillRect(rectangles[ENDNODE_ROW][ENDNODE_COL], Qt::red);
}





/*
 * ==============================
 * ===== UI ACTION HANDLERS =====
 * ==============================
 */

void Visualization::on_btnGenerate_clicked()
{
    shouldGenerateMap = true;
    this->update();
}

void Visualization::on_btnRun_clicked()
{
    pathfinder->Run(BREADTH_FIRST);
}

void Visualization::on_btnReset_clicked()
{
    map->reset();
    this->update();
}





/*
 * =============================
 * ===== QT EVENT HANDLERS =====
 * =============================
 */

/* passes painter onto map to draw - called on UI update() */
void Visualization::paintEvent(QPaintEvent *){
    if(shouldGenerateMap){
        QPainter painter(this);
        drawMap(&painter);
    }
}

/* handles editing nodes when user drags mouse over rectangles */
void Visualization::mouseMoveEvent(QMouseEvent *e){
    for(int i = 0; i < MAP_LENGTH; i++){
        for(int j = 0; j < MAP_WIDTH; j++){
            if(rectangles[i][j].contains(e->pos())){
                //left click => fill node
                if(e->buttons() == Qt::LeftButton)
                    map->setWall(i, j, true);

                //right click => unfill node
                if(e->buttons() == Qt::RightButton)
                    map->setWall(i, j, false);

                this->update();
                return;
            }
        }
    }
}

/* handles editing nodes when user clicks over rectangles */
void Visualization::mousePressEvent(QMouseEvent *e){
    for(int i = 0; i < MAP_LENGTH; i++){
        for(int j = 0; j < MAP_WIDTH; j++){
            if(rectangles[i][j].contains(e->pos())){
                //left click => fill node
                if(e->buttons() == Qt::LeftButton)
                    map->setWall(i, j, true);

                //right click => unfill node
                if(e->buttons() == Qt::RightButton)
                    map->setWall(i, j, false);

                this->update();
                return;
            }
        }
    }
}
