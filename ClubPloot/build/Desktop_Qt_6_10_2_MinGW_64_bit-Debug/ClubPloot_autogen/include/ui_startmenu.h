/********************************************************************************
** Form generated from reading UI file 'startmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTMENU_H
#define UI_STARTMENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartMenu
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QMenu *menuFIle;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StartMenu)
    {
        if (StartMenu->objectName().isEmpty())
            StartMenu->setObjectName("StartMenu");
        StartMenu->resize(686, 600);
        actionExit = new QAction(StartMenu);
        actionExit->setObjectName("actionExit");
        actionAbout = new QAction(StartMenu);
        actionAbout->setObjectName("actionAbout");
        actionAbout->setMenuRole(QAction::MenuRole::AboutRole);
        centralwidget = new QWidget(StartMenu);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(150, 280, 171, 81));
        pushButton->setCheckable(false);
        pushButton->setChecked(false);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(380, 280, 171, 81));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 170, 271, 41));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(270, 10, 151, 161));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(160, 210, 371, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(100, 240, 501, 21));
        StartMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StartMenu);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 686, 22));
        menuFIle = new QMenu(menubar);
        menuFIle->setObjectName("menuFIle");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        StartMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(StartMenu);
        statusbar->setObjectName("statusbar");
        StartMenu->setStatusBar(statusbar);

        menubar->addAction(menuFIle->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFIle->addAction(actionExit);
        menuHelp->addAction(actionAbout);

        retranslateUi(StartMenu);

        QMetaObject::connectSlotsByName(StartMenu);
    } // setupUi

    void retranslateUi(QMainWindow *StartMenu)
    {
        StartMenu->setWindowTitle(QCoreApplication::translate("StartMenu", "StartMenu", nullptr));
        actionExit->setText(QCoreApplication::translate("StartMenu", "Exit", nullptr));
        actionAbout->setText(QCoreApplication::translate("StartMenu", "About", nullptr));
        pushButton->setText(QCoreApplication::translate("StartMenu", "Open", nullptr));
        pushButton_2->setText(QCoreApplication::translate("StartMenu", "Exit", nullptr));
        label->setText(QCoreApplication::translate("StartMenu", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:700; font-style:italic;\">Welcome to Club Ploot</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("StartMenu", "<html><head/><body><p><img src=\":/images/Ploot_Fraymakers.png\"/></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("StartMenu", "<html><head/><body><p>A <span style=\" font-style:italic;\">Club Penguin</span>-inspired chat room based on an original game, <span style=\" font-style:italic;\">Ploot.</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("StartMenu", "<html><head/><body><p>Click &quot;Open&quot; to get started! Make sure you have a ploot exported from the game on your disk.</p></body></html>", nullptr));
        menuFIle->setTitle(QCoreApplication::translate("StartMenu", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("StartMenu", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartMenu: public Ui_StartMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTMENU_H
