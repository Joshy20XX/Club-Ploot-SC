/********************************************************************************
** Form generated from reading UI file 'moon_river.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOON_RIVER_H
#define UI_MOON_RIVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Moon_River
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QWidget *centralwidget;
    QLabel *moon_river_background;
    QLabel *moon_river_tree;
    QPlainTextEdit *ploot_text_bar;
    QWidget *ploot_player;
    QVBoxLayout *ploot_layout;
    QLabel *ploot_player_sprite;
    QLabel *ploot_name;
    QPushButton *ploot_text_send;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Moon_River)
    {
        if (Moon_River->objectName().isEmpty())
            Moon_River->setObjectName("Moon_River");
        Moon_River->resize(625, 430);
        actionExit = new QAction(Moon_River);
        actionExit->setObjectName("actionExit");
        actionAbout = new QAction(Moon_River);
        actionAbout->setObjectName("actionAbout");
        actionAbout->setMenuRole(QAction::MenuRole::AboutRole);
        centralwidget = new QWidget(Moon_River);
        centralwidget->setObjectName("centralwidget");
        moon_river_background = new QLabel(centralwidget);
        moon_river_background->setObjectName("moon_river_background");
        moon_river_background->setGeometry(QRect(0, -10, 631, 421));
        moon_river_tree = new QLabel(centralwidget);
        moon_river_tree->setObjectName("moon_river_tree");
        moon_river_tree->setGeometry(QRect(270, 40, 241, 231));
        moon_river_tree->setSizeIncrement(QSize(0, 0));
        moon_river_tree->setBaseSize(QSize(0, 0));
        moon_river_tree->setTextFormat(Qt::TextFormat::MarkdownText);
        moon_river_tree->setScaledContents(true);
        moon_river_tree->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        moon_river_tree->setWordWrap(false);
        moon_river_tree->setMargin(-270);
        moon_river_tree->setIndent(0);
        ploot_text_bar = new QPlainTextEdit(centralwidget);
        ploot_text_bar->setObjectName("ploot_text_bar");
        ploot_text_bar->setGeometry(QRect(170, 370, 211, 31));
        ploot_text_bar->setMaximumSize(QSize(281, 31));
        ploot_text_bar->setStyleSheet(QString::fromUtf8(""));
        ploot_text_bar->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        ploot_text_bar->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        ploot_text_bar->setUndoRedoEnabled(false);
        ploot_text_bar->setLineWrapMode(QPlainTextEdit::LineWrapMode::WidgetWidth);
        ploot_text_bar->setMaximumBlockCount(3);
        ploot_text_bar->setBackgroundVisible(false);
        ploot_player = new QWidget(centralwidget);
        ploot_player->setObjectName("ploot_player");
        ploot_player->setGeometry(QRect(50, 170, 81, 65));
        ploot_layout = new QVBoxLayout(ploot_player);
        ploot_layout->setObjectName("ploot_layout");
        ploot_layout->setContentsMargins(3, 3, 3, 3);
        ploot_player_sprite = new QLabel(ploot_player);
        ploot_player_sprite->setObjectName("ploot_player_sprite");

        ploot_layout->addWidget(ploot_player_sprite);

        ploot_name = new QLabel(ploot_player);
        ploot_name->setObjectName("ploot_name");

        ploot_layout->addWidget(ploot_name);

        ploot_text_send = new QPushButton(centralwidget);
        ploot_text_send->setObjectName("ploot_text_send");
        ploot_text_send->setGeometry(QRect(380, 370, 75, 31));
        Moon_River->setCentralWidget(centralwidget);
        moon_river_background->raise();
        ploot_player->raise();
        moon_river_tree->raise();
        ploot_text_send->raise();
        ploot_text_bar->raise();
        statusbar = new QStatusBar(Moon_River);
        statusbar->setObjectName("statusbar");
        Moon_River->setStatusBar(statusbar);

        retranslateUi(Moon_River);

        QMetaObject::connectSlotsByName(Moon_River);
    } // setupUi

    void retranslateUi(QMainWindow *Moon_River)
    {
        Moon_River->setWindowTitle(QCoreApplication::translate("Moon_River", "StartMenu", nullptr));
        actionExit->setText(QCoreApplication::translate("Moon_River", "Exit", nullptr));
        actionAbout->setText(QCoreApplication::translate("Moon_River", "About", nullptr));
        moon_river_background->setText(QCoreApplication::translate("Moon_River", "<html><head/><body><p><img src=\":/images/Moon_River_Background.png\"/></p></body></html>", nullptr));
        moon_river_tree->setText(QCoreApplication::translate("Moon_River", "<html><head/><body><p><br/></p><p><br/></p><p><img src=\":/images/Moon_River_Foreground.png\"/></p></body></html>", nullptr));
        ploot_text_bar->setPlainText(QString());
        ploot_text_bar->setPlaceholderText(QCoreApplication::translate("Moon_River", "Say Something!", nullptr));
        ploot_player->setProperty("text", QVariant(QString()));
        ploot_player_sprite->setText(QCoreApplication::translate("Moon_River", "<html><head/><body><p align=\"center\"><img src=\":/images/Ploot_Super_Tiny.png\"/></p></body></html>", nullptr));
        ploot_name->setText(QCoreApplication::translate("Moon_River", "<html><head/><body><p align=\"center\">PLOOT NAME</p></body></html>", nullptr));
        ploot_text_send->setText(QCoreApplication::translate("Moon_River", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Moon_River: public Ui_Moon_River {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOON_RIVER_H
