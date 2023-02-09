#include "mainwindow.h"
#include <QPaintEvent>
#include <QApplication>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QSound>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ImageButton b (nullptr);
    b.setFixedSize(100,100);
    b.move(1000,400);

    QSound player(":/sound/Files/cl.wav");

    QObject::connect(&b,&QPushButton::pressed,[&player]
    {
        player.play();
    });

    b.show();

    return QApplication::exec();
}

#include <main.moc>
