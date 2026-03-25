#include "ploot_select.h"
#include "ui_ploot_select.h"

#include "moon_river.h"

#include <QFileDialog>

QString time_stamp;
QString ploot_normal_val;
QString ploot_poison_val;
QString ploot_fire_val;
QString ploot_devil_val;
QString ploot_whimsy_val;
QString ploot_parasitic_val;
QString ploot_bunny_val;
QString ploot_rat_val;
QString ploot_scary_val;
QString ploot_gloom_val;
QString ploot_name;
QString ploot_age;
QString ploot_kills;
QString ploot_orgin;
QString ploot_shiny;
QString ploot_accent;
QString ploot_call_sound;
QString ploot_collection_walk_sound;
QString ploot_completed_collection_sound;
QString ploot_death_sound;
QString ploot_hit_sound;
QString ploot_panic_sound;
QString ploot_rare_sound;
QString ploot_thrown_sound;
QString ploot_sparkle;

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
        window->setLabelText(ploot_name);
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

        //Read Ploot File
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);

            for (int i = 1; i <= 26; i++) {
                if (in.atEnd()) break;

                QString currentLine = in.readLine();

                //Go through the entire list and set the values correctly
                switch (i) {
                case 1: time_stamp = currentLine; time_stamp = time_stamp.mid(12); break;
                case 2: ploot_normal_val = currentLine; ploot_normal_val = ploot_normal_val.mid(8); break;
                case 3: ploot_poison_val = currentLine; ploot_poison_val = ploot_poison_val.mid(8); break;
                case 4: ploot_fire_val = currentLine; ploot_fire_val = ploot_fire_val.mid(6); break;
                case 5: ploot_devil_val = currentLine; ploot_devil_val = ploot_devil_val.mid(7); break;
                case 6: ploot_whimsy_val = currentLine; ploot_whimsy_val = ploot_whimsy_val.mid(8); break;
                case 7: ploot_parasitic_val = currentLine; ploot_parasitic_val = ploot_parasitic_val.mid(11); break;
                case 8: ploot_bunny_val = currentLine; ploot_bunny_val = ploot_bunny_val.mid(7); break;
                case 9: ploot_rat_val = currentLine; ploot_rat_val = ploot_rat_val.mid(5); break;
                case 10: ploot_scary_val = currentLine; ploot_scary_val = ploot_scary_val.mid(7); break;
                case 11: ploot_gloom_val = currentLine; ploot_gloom_val = ploot_gloom_val.mid(7); break;
                case 12: ploot_name = currentLine; ploot_name = ploot_name.mid(6); break;
                case 13: ploot_age = currentLine; ploot_age = ploot_age.mid(5); break;
                case 14: ploot_kills = currentLine; ploot_kills = ploot_kills.mid(7); break;
                case 15: ploot_orgin = currentLine; ploot_orgin = ploot_orgin.mid(7); break;
                case 16: ploot_shiny = currentLine; ploot_shiny = ploot_shiny.mid(7); break;
                case 17: ploot_accent = currentLine; ploot_accent = ploot_accent.mid(8); break;

                //PAST THIS POINT IS OUR BASE 64 STUFF! UNTESTED TO SEE IF IT ACTUALLY GRABS IT ALL PROPERLY!
                case 18: ploot_call_sound = currentLine; ploot_call_sound = ploot_call_sound.mid(12); break;
                case 19: ploot_collection_walk_sound = currentLine; ploot_collection_walk_sound = ploot_collection_walk_sound.mid(23); break;
                case 20: ploot_completed_collection_sound = currentLine; ploot_completed_collection_sound = ploot_completed_collection_sound.mid(28); break;
                case 21: ploot_death_sound = currentLine; ploot_death_sound = ploot_death_sound.mid(13); break;
                case 22: ploot_hit_sound = currentLine; ploot_hit_sound = ploot_hit_sound.mid(11); break;
                case 23: ploot_panic_sound = currentLine; ploot_panic_sound = ploot_panic_sound.mid(13); break;
                case 24: ploot_rare_sound = currentLine; ploot_rare_sound = ploot_rare_sound.mid(12); break;
                case 25: ploot_thrown_sound = currentLine; ploot_thrown_sound = ploot_thrown_sound.mid(14); break;
                case 26: ploot_sparkle = currentLine; ploot_sparkle = ploot_sparkle.mid(9); break;
            }

            file.close();
        }

    }
        ui->ploot_label->setText("Your Ploot is " + ploot_name);

}

}