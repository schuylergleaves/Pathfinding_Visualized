#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include <QMainWindow>
#include <QtGui>
#include <QGraphicsScene>
#include "Constants.h"
#include "Map.h"

namespace Ui {
class Visualization;
}

class Visualization : public QMainWindow
{
    Q_OBJECT

public:
    explicit Visualization(QWidget *parent = nullptr);
    ~Visualization();

private slots:
    void on_btnGenerate_clicked();

private:
    /* pointers */
    Ui::Visualization *ui;
    Map               *map;
    QRect            **rectangles;

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
