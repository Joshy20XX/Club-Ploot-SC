#include "moon_river.h"
#include "ui_moon_river.h"
#include "ploot_select.h"
#include "ui_ploot_select.h"
#include "ploot.h"

#include <QMouseEvent>
#include <QEvent>
#include <QPropertyAnimation>
#include <QDebug>
#include <QTimer>
#include <QTextBlock>
#include <QFile>
#include <iostream>
#include <QVector>
#include <QPixmap>
#include <QPainter>
#include <QFileInfo>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>

int player_normal;
int player_poison;
int player_fire;
int player_devil;
int player_whimsy;
int player_parasitic;
int player_bunny;
int player_rat;
int player_scary;
int player_gloom;
int player_rudeness = 0;
QColor player_color(255, 255, 255);

//For parsing the bad words
QVector<QString> badwords;
bool found_badword = false;
ploot* currentPloot = &new_ploot;

Moon_River::Moon_River(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Moon_River)
{
    ui->setupUi(this);
    Moon_River::parseCussWords();
    ui->scrollArea->hide();
}

Moon_River::~Moon_River()
{
    delete ui;
}

QPixmap Tint_image(const QPixmap &src, const QColor &color)
{
    QPixmap result(src.size());
    result.fill(Qt::transparent);

    QPainter painter(&result);
    painter.drawPixmap(0, 0, src);

    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.fillRect(result.rect(), color);

    painter.end();

    return result;
}

//Count for rudeness
int Moon_River::countRudeness(const QString &temp_text) {
    int count = 0;
    int rudeness = 0;

    QRegularExpression re("[A-Z!@#$%^&*<>'()*+,-./:;]");
    QString subject(temp_text);
    QRegularExpressionMatchIterator i = re.globalMatch(subject);

    while (i.hasNext()) {
        if (count > 8) rudeness++;
        i.next(); //Get next character
        count++;
    }
    return rudeness;
}

void Moon_River::parseCussWords() {
    //Get the bad words file with its associated path
    QString file = "../../bad_words.txt";
    QFileInfo bad_info(file);

    //If the path is empty because the file doesn't exist, don't read
    if (!bad_info.exists()) {
        qDebug() << "File's relative path doesn't exist.";
        return;
    }

    QString badfilepath = bad_info.canonicalFilePath();

    qDebug() << "File path: " << badfilepath;
    QFile badfile(badfilepath);

    //if the file doesn't exist, return
    if (!badfile.exists()) {
        qDebug() << "File open failed. File does not exist.";
        return;
    }

    //If the file exists and is open, get the text files
    if (badfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&badfile);
        qDebug() << "Badwords list:";
        while (!in.atEnd()) {
            QString line = in.readLine();
            qDebug() << line;
            badwords.push_back(line);
        }
        badfile.close();
    } else {
        qDebug() << "Failed opening file";
    }
}

//Speech stuff
void Moon_River::on_ploot_text_send_clicked()
{
    //Read what is wanted to be said
    QString text = ui->ploot_text_bar->toPlainText();

    //We can make a temp place for the string to account for
    //further checks like punctuation and rudeness level
    QString temp = text;

    //Check for rudeness first
    int rude_level = countRudeness(temp);
    player_rudeness += rude_level;

    //Then check for bad words
    temp.remove(QRegularExpression("[[:punct:]]"));

    //Open another QTextStream to stream each word in the sent string
    //before it's sent to the chat room.
    QTextStream stream(&temp);
    QString word;
    while (stream >> word) {
        for (const auto &cussword : badwords) {
            if (word.toLower() == cussword) {
                found_badword = true;
            }
        }
    }

    if (found_badword) {
        text = "NECTAR!";
        player_rudeness += 10; //Change the text to this.
    }

    //Now we can process it
    if (!text.isEmpty()) {

        QLabel *speech_bubble = new QLabel(this);
        QLabel *speech = new QLabel(text, this);
        speech->setStyleSheet("color: black");

        speech->setAlignment(Qt::AlignCenter);
        speech->adjustSize();

        //Position it above the player
        int x = ui->ploot_player->x();
        int y = ui->ploot_player->y() - speech->height() - 20;

        //Speech Bubble Image
        QPixmap pixmap(":/images/speech_bubble_mid.png");

        //Tint the bubble (As soon as we parse the ploot we will put its actual color here)
        QPixmap tinted = Tint_image(pixmap, "#" + currentPloot->getColor().toLower());

        speech_bubble->setPixmap(tinted);
        speech_bubble->resize(tinted.size());

        //Place both the speech bubble and the text.
        speech->move(x + 6, y);
        speech_bubble->move(x, y);
        speech_bubble->show();
        speech->show(); 


        //Give it a timer
        QTimer::singleShot(5000, speech, [=]() {
            speech->deleteLater();
            speech_bubble->deleteLater();
        });


        //Clear the text bar
        ui->ploot_text_bar->clear();
        found_badword = false;
        return;
    }
}

//This is setting the name of the Ploot in Moon River
void Moon_River::setLabelText(const QString &text)
{
    ui->ploot_name->setText(text);
    ui->ploot_name->setAlignment(Qt::AlignCenter);
}

//Setting ploot shadow color
void Moon_River::setShadowColor(const QColor &color)
{
    QPixmap pixmap(":/images/Ploot_Shadow.png");
    QPixmap shadow_tint = Tint_image(pixmap, color);
    ui->ploot_shadow->setPixmap(shadow_tint);
    ui->ploot_shadow->setAlignment(Qt::AlignCenter);
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

//Check if the input string surpasses 3 lines
void Moon_River::on_ploot_text_bar_textChanged()
{
    QTextCursor cursor = ui->ploot_text_bar->textCursor();
    QTextBlock block = cursor.block();
    QTextLayout *layout = block.layout();

    int lineCount = layout->lineCount();

    if (lineCount > 3) {
        cursor.deletePreviousChar();
    }
}


void Moon_River::on_toolButton_clicked(bool checked)
{
    ui->scrollArea->show();
    QString name = ui->ploot_name->text();

    ui->ploot_name_info->setText("Name: " + name);
    ui->ploot_age_info->setText("Age: " + currentPloot->getAge());
    ui->ploot_normal_info->setText("Normal: " + currentPloot->getNormal());
    ui->ploot_poison_info->setText("Poison: " + currentPloot->getPoison());
    ui->ploot_fire_info->setText("Fire: " + currentPloot->getFire());
    ui->ploot_devil_info->setText("Devil: " + currentPloot->getDevil());
    ui->ploot_whimsy_info->setText("Whimsy: " + currentPloot->getWhimsy());
    ui->ploot_parasitic_info->setText("Parasitic: " + currentPloot->getParasitic());
    ui->ploot_bunny_info->setText("Bunny: " + currentPloot->getBunny());
    ui->ploot_rat_info->setText("Rat: " + currentPloot->getRat());
    ui->ploot_scary_info->setText("Scary: " + currentPloot->getScary());
    ui->ploot_gloom_info->setText("Gloom: " + currentPloot->getGloom());
    ui->ploot_color_info->setText("Color: " + currentPloot->getColor());
    QString rudeness = QString::number(player_rudeness);
    ui->ploot_rudeness_info->setText("Rudeness: " + rudeness);
}


void Moon_River::on_pushButton_clicked(bool checked)
{
    ui->scrollArea->hide();
}

