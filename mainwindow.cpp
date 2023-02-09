#include "mainwindow.h"
#include <QPaintEvent>
#include <QApplication>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QTimer>

ImageButton::ImageButton(QWidget *parent)
{
    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    mButtonUpPixmap = QPixmap(":/image/Files/Off.png");
    mButtonDownPixmap = QPixmap(":/image/Files/On.png");
    mCurrentButtonPixmap = mButtonUpPixmap;
    setGeometry(mCurrentButtonPixmap.rect());
    connect(this, &QPushButton::clicked, this, &ImageButton::setDown);
}

void ImageButton::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(),mCurrentButtonPixmap);

}

QSize ImageButton::sizeHint() const
{
    return QSize(100,100);
}

QSize ImageButton::minimumSizeHint() const
{
    return sizeHint();
}

void ImageButton::keyPressEvent(QKeyEvent *e)
{
    setDown();
}

void ImageButton::setDown()
{
    mCurrentButtonPixmap = mButtonDownPixmap;
    update();
    QTimer::singleShot(100, this, &ImageButton::setUp);
}

void ImageButton::setUp()
{
    mCurrentButtonPixmap = mButtonUpPixmap;
    update();
}





