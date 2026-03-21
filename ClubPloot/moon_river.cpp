#include "moon_river.h"
#include "ui_moon_river.h"

#include <QMouseEvent>
#include <QPropertyAnimation>
#include <QDebug>


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

//This is setting the name of the Ploot in Moon River
void Moon_River::setLabelText(const QString &text)
{
    ui->ploot_name->setText(text);
    ui->ploot_name->setAlignment(Qt::AlignCenter);
}

void Moon_River::mousePressEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();
    QRect ploot_pos = ui->ploot_player->geometry();  //Ploot's position

    int x = pos.x() - ui->ploot_player->width() / 2;
    int y = pos.y() - ui->ploot_player->height() / 2;

    //Animate the ploot's movement from its current position to the new position
    ui->ploot_player->move(x,y); //Update to the new position

    //Then animate the ploot_player moving to that new position and avoid flickering
    QPropertyAnimation *anim = new QPropertyAnimation(ui->ploot_player, "geometry", this);
    anim->setDuration(1000);
    anim->setStartValue(ploot_pos);
    anim->setEndValue(QRect(x, y, ui->ploot_player->width(), ui->ploot_player->height()));
    anim->start();
}

