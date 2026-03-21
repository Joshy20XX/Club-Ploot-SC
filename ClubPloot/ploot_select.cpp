#include "ploot_select.h"
#include "ui_ploot_select.h"

#include "moon_river.h"

ploot_select::ploot_select(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ploot_select)
{
    ui->setupUi(this);
}

ploot_select::~ploot_select()
{
    delete ui;
}

void ploot_select::on_pushButton_clicked()
{
    Moon_River *window = new Moon_River(this);
    window->show();

    this->hide();
}

