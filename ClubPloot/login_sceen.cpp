#include "login_sceen.h"
#include "ui_login_sceen.h"

#include "startmenu.h"

login_sceen::login_sceen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login_sceen)
{
    ui->setupUi(this);
}

login_sceen::~login_sceen()
{
    delete ui;
}

void login_sceen::on_pushButton_clicked()
{
    StartMenu *window = new StartMenu(this);

    window->show();
    //this->hide();
}

