#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include <QMainWindow>
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

private:
    Ui::Visualization *ui;

    Map *map;

    const int MAP_LENGTH = 20;
    const int MAP_WIDTH  = 20;
};

#endif // VISUALIZATION_H
