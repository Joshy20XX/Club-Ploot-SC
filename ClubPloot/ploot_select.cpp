#include "ploot_select.h"
#include "ui_ploot_select.h"

#include "moon_river.h"

#include <QFileDialog>

QString ploot_name;

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

//Opening Moon River
void ploot_select::on_pushButton_clicked()
{
    Moon_River *window = new Moon_River(this);

    //Giving the Ploot it's Name
    //If it has no name, give it a debug name
    if (ploot_name == ""){
        window->setLabelText("PLOOT NAME");
    } else {
        //Otherwise, give it it's real name.
        window->setLabelText(ploot_name.mid(6));
    }


    window->show();

    this->hide();
}

//Opening the Ploot File
void ploot_select::on_select_ploot_button_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        "Open Ploot",
        "",
        "Ploot (*.ploot)"
        );

    if (!fileName.isEmpty()) {
        QFile file(fileName);

        //Read the ploot file and specifcally get the 12th line (It's Name)
        //This is meant to be temporary for now.
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);

            for (int i = 1; i <= 12; i++) {
                if (in.atEnd()) break;
                ploot_name = in.readLine();
            }

            file.close();
        }

    }


}

