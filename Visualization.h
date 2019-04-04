#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include <QMainWindow>

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
};

#endif // VISUALIZATION_H
