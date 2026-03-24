#include "moon_river.h"
#include "ui_moon_river.h"

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

//For parsing the bad words
QVector<QString> badwords;
bool found_badword = false;

Moon_River::Moon_River(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Moon_River)
{
    ui->setupUi(this);
    Moon_River::parseCussWords();
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

void Moon_River::parseCussWords() {
    //Open the bad words file
    QString file = "../../bad_words.txt";
    QFile bad_file(file);

    //if the file doesn't exist, return
    if (!bad_file.exists()) {
        qDebug() << "File open failed. File does not exist.";
        return;
    }

    //If the file exists and is open, get the text files
    if (bad_file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&bad_file);
        qDebug() << "Badwords list:";
        while (!in.atEnd()) {
            QString line = in.readLine();
            qDebug() << line;
            badwords.push_back(line);
        }
        bad_file.close();
    } else {
        qDebug() << "Failed opening file";
    }
}

//Speech stuff
void Moon_River::on_ploot_text_send_clicked()
{
    //Read what is wanted to be said
    QString text = ui->ploot_text_bar->toPlainText();

    //Open another QTextStream to stream each word in the sent string
    //before it's sent to the chat room.
    QTextStream stream(&text);
    QString word;
    while (stream >> word) {
        for (const auto &cussword : badwords) {
            if (word == cussword) {
                found_badword = true;
            }
        }
    }

    if (found_badword) text = "NECTAR!"; //Change the text to this.

    //Now we can process it
    if (!text.isEmpty()) {

        QLabel *speech_bubble = new QLabel(this);
        QLabel *speech = new QLabel(text, this);;

        speech->setAlignment(Qt::AlignCenter);
        speech->adjustSize();

        //Position it above the player
        int x = ui->ploot_player->x();
        int y = ui->ploot_player->y() - speech->height() - 20;

        //Speech Bubble Image
        QPixmap pixmap(":/images/speech_bubble_mid.png");

        //Tint the bubble (As soon as we parse the ploot we will put its actual color here)
        QPixmap tinted = Tint_image(pixmap, QColor(165, 35, 65));

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

