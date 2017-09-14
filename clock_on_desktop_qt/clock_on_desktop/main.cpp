#include <QApplication>
#include <QMainWindow>
#include "clockondesktop.h"

int main(int argc, char *argv[])
{
QApplication app(argc, argv);

ClockOnDesktop *clock_window(new ClockOnDesktop);
clock_window->show();

return app.exec();
}
