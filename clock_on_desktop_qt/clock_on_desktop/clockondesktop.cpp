#include <QtWidgets>
#include <QSettings>
#include "clockondesktop.h"

ClockOnDesktop::ClockOnDesktop(QWidget *parent) :
    QMainWindow(parent)
  , m_ui(new Ui::ClockOnDesktopWindow)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    m_ui->setupUi(this);

    QTimer *timer(new QTimer(this));
    connect(timer, &QTimer::timeout, this, &ClockOnDesktop::showTime);
    timer->start(1000);

    readSettings();
    showTime();
}

void ClockOnDesktop::showTime()
{
    QTime time(QTime::currentTime());
    QString text(time.toString("hh:mm"));
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    m_ui->lcdNumber->display(text);
}

void ClockOnDesktop::mousePressEvent(QMouseEvent *event)
{
    m_mouseClickXCoordinate = event->x();
    m_mouseClickYCoordinate = event->y();
}

void ClockOnDesktop::mouseMoveEvent(QMouseEvent *event)
{
    move(event->globalX() - m_mouseClickXCoordinate, event->globalY() - m_mouseClickYCoordinate);
}

void ClockOnDesktop::closeEvent(QCloseEvent *event)
{
    QSettings settings("none", "clock_on_desktop");
    settings.setValue("geometry", saveGeometry());
    QMainWindow::closeEvent(event);
}

void ClockOnDesktop::readSettings()
{
    QSettings settings("none", "clock_on_desktop");
    restoreGeometry(settings.value("geometry").toByteArray());
}
