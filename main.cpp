#include "Visualization.h"
#include <QApplication>

/* entry point for program - opens Visualization (ie: UI of program) */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Visualization w;
    w.show();

    return a.exec();
}
