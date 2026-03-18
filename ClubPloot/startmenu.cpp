#include "startmenu.h"
#include "./ui_startmenu.h"
#include <QMessageBox>

StartMenu::StartMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartMenu)
{
    ui->setupUi(this);
}

StartMenu::~StartMenu()
{
    delete ui;
}

void StartMenu::on_actionExit_triggered()
{
    QApplication::quit();
}


void StartMenu::on_pushButton_2_clicked()
{
    QApplication::quit();
}


void StartMenu::on_actionAbout_triggered()
{
    QMessageBox aboutBox;
    aboutBox.setIcon(QMessageBox::Information);
    aboutBox.setText("Club Ploot\n Authors: Nick Mel, Samarth Muthyala, Edgar Zayas, and Josh Ottey");
    aboutBox.setDefaultButton(QMessageBox::Ok);
    int ret = aboutBox.exec();
}

