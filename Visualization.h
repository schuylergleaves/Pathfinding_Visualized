#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include <QMainWindow>
#include <QtGui>
#include <QGraphicsScene>
#include "Constants.h"
#include "Map.h"
#include "Pathfinder.h"

namespace Ui {
class Visualization;
}

class Visualization : public QMainWindow
{
    Q_OBJECT

public:
    explicit Visualization(QWidget *parent = nullptr);
    ~Visualization();

    //public so that Pathfinder can access
    Ui::Visualization *ui;

private slots:
    void on_btnGenerate_clicked();
    void on_btnRun_clicked();

private:
    /* pointers */
    Map               *map;
    QRect            **rectangles;
    Pathfinder        *pathfinder;

    /* member variables */
    bool shouldGenerateMap = false;

    /* initialization functions */
    void init();

    /* ui functions */
    void drawMap(QPainter *painter);

    /* event handlers */
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);

    /* helper functions */

};

#endif // VISUALIZATION_H
