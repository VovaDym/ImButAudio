#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPixmap>
#include <QPushButton>

class ImageButton : public QPushButton
{
    Q_OBJECT
public:
    ImageButton() = default;
    ImageButton(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent *e) override;
public slots:
    void setUp();
    void setDown();
private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonDownPixmap;
    QPixmap mButtonUpPixmap;
};

#endif


