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
    //map init - creates all nodes
    map = new Map(MAP_LENGTH, MAP_WIDTH);

    //create rectangle for each node in map
    rectangles = new QRect*[MAP_LENGTH];
    for(int i = 0; i < MAP_LENGTH; i++){
        rectangles[i] = new QRect[MAP_WIDTH];
    }

    for(int i = 0; i < MAP_LENGTH; i++){
        for(int j = 0; j < MAP_LENGTH; j++){
            //creates grid based on starting x and y, and current position in map
            rectangles[i][j] = QRect(MAP_STARTING_X + (j * RECT_WIDTH), MAP_STARTING_Y + (i * RECT_WIDTH), RECT_WIDTH, RECT_WIDTH);
        }
    }
}




/*
 * ========================
 * ===== UI FUNCTIONS =====
 * ========================
 */

/* draws grid map to UI (converting each node into a rectangle) */
void Visualization::drawMap(QPainter *painter){
    painter->setPen(Qt::black);

    for(int i = 0; i < MAP_LENGTH; i++){
        for(int j = 0; j < MAP_WIDTH; j++){
            Node* target = map->getNodeAt(i, j);

            painter->drawRect(rectangles[i][j]);

            if(target->isFilled())
                painter->fillRect(rectangles[i][j], Qt::black);
        }
    }
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

/* if user drags over a rectangle on the grid while holding mouse, set the node representing that rectangle to be filled */
void Visualization::mouseMoveEvent(QMouseEvent *e){
    //handles left button clicks
    if(e->buttons() == Qt::LeftButton){
        for(int i = 0; i < MAP_LENGTH; i++){
            for(int j = 0; j < MAP_WIDTH; j++){
                if(rectangles[i][j].contains(e->pos())){
                    map->setFilled(i, j, true);
                    this->update();
                    return;
                }
            }
        }
    }
}

/* if user clicks on a rectangle on the grid, set the node representing that rectangle to be filled */
void Visualization::mousePressEvent(QMouseEvent *e){
    if(e->button() == Qt::LeftButton){
        for(int i = 0; i < MAP_LENGTH; i++){
            for(int j = 0; j < MAP_WIDTH; j++){
                if(rectangles[i][j].contains(e->pos())){
                    map->setFilled(i, j, true);
                    this->update();
                    return;
                }
            }
        }
    }
}





/*
 * ============================
 * ===== HELPER FUNCTIONS =====
 * ============================
 */

