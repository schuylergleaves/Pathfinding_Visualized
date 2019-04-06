#include "Visualization.h"
#include "ui_Visualization.h"

/* Constructor */
Visualization::Visualization(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Visualization)
{
    ui->setupUi(this);
    map = new Map(MAP_LENGTH, MAP_WIDTH);
}

/* Destructor */
Visualization::~Visualization()
{
    delete ui;
}



