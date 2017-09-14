#ifndef CLOCKONDESKTOP_H
#define CLOCKONDESKTOP_H

#include <QMainWindow>
#include "ui_clockondesktop.h"

class ClockOnDesktop : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClockOnDesktop(QWidget *parent = 0);

private slots:
    void showTime();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *event);
    void readSettings();

private:
    Ui::ClockOnDesktopWindow *m_ui;
    int m_mouseClickXCoordinate;
    int m_mouseClickYCoordinate;
};

#endif // CLOCKONDESKTOP_H
