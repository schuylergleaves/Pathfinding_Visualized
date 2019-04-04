#include "Visualization.h"
#include "ui_Visualization.h"

/* Constructor */
Visualization::Visualization(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Visualization)
{
    ui->setupUi(this);
}

/* Destructor */
Visualization::~Visualization()
{
    delete ui;
}



