#include "moon_river.h"
#include "ui_moon_river.h"

#include <QMouseEvent>

Moon_River::Moon_River(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Moon_River)
{
    ui->setupUi(this);
}

Moon_River::~Moon_River()
{
    delete ui;
}

void Moon_River::mousePressEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();

    int x = pos.x() - ui->ploot_player->width() / 2;
    int y = pos.y() - ui->ploot_player->height() / 2;

    ui->ploot_player->move(x, y);
}
