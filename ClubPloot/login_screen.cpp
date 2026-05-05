#include "login_screen.h"
#include "ui_login_screen.h"

#include "startmenu.h"

login_screen::login_screen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login_screen)
{
    ui->setupUi(this);
}

login_screen::~login_screen()
{
    delete ui;
}

void login_screen::on_pushButton_clicked()
{
    StartMenu *window = new StartMenu(this);

    window->show();
    //this->hide();
}

