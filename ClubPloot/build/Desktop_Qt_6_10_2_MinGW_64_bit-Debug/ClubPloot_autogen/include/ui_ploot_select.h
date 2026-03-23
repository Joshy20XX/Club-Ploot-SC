/********************************************************************************
** Form generated from reading UI file 'ploot_select.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOOT_SELECT_H
#define UI_PLOOT_SELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ploot_select
{
public:
    QWidget *centralwidget;
    QLineEdit *key3_input;
    QLineEdit *key2_input;
    QLineEdit *key1_input;
    QPushButton *pushButton;
    QPushButton *select_ploot_button;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ploot_select)
    {
        if (ploot_select->objectName().isEmpty())
            ploot_select->setObjectName("ploot_select");
        ploot_select->resize(608, 444);
        centralwidget = new QWidget(ploot_select);
        centralwidget->setObjectName("centralwidget");
        key3_input = new QLineEdit(centralwidget);
        key3_input->setObjectName("key3_input");
        key3_input->setGeometry(QRect(140, 210, 311, 31));
        key2_input = new QLineEdit(centralwidget);
        key2_input->setObjectName("key2_input");
        key2_input->setGeometry(QRect(140, 170, 311, 31));
        key1_input = new QLineEdit(centralwidget);
        key1_input->setObjectName("key1_input");
        key1_input->setGeometry(QRect(140, 130, 311, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(240, 270, 131, 71));
        select_ploot_button = new QPushButton(centralwidget);
        select_ploot_button->setObjectName("select_ploot_button");
        select_ploot_button->setGeometry(QRect(180, 90, 241, 31));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 611, 401));
        ploot_select->setCentralWidget(centralwidget);
        label->raise();
        key3_input->raise();
        key2_input->raise();
        key1_input->raise();
        pushButton->raise();
        select_ploot_button->raise();
        menubar = new QMenuBar(ploot_select);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 608, 22));
        ploot_select->setMenuBar(menubar);
        statusbar = new QStatusBar(ploot_select);
        statusbar->setObjectName("statusbar");
        ploot_select->setStatusBar(statusbar);

        retranslateUi(ploot_select);

        QMetaObject::connectSlotsByName(ploot_select);
    } // setupUi

    void retranslateUi(QMainWindow *ploot_select)
    {
        ploot_select->setWindowTitle(QCoreApplication::translate("ploot_select", "MainWindow", nullptr));
        key3_input->setText(QCoreApplication::translate("ploot_select", "Key 3", nullptr));
        key2_input->setText(QCoreApplication::translate("ploot_select", "Key 2", nullptr));
        key1_input->setText(QCoreApplication::translate("ploot_select", "Key 1", nullptr));
        pushButton->setText(QCoreApplication::translate("ploot_select", "Confirm", nullptr));
        select_ploot_button->setText(QCoreApplication::translate("ploot_select", "Select Ploot", nullptr));
        label->setText(QCoreApplication::translate("ploot_select", "<html><head/><body><p><img src=\":/images/Ploot_Select_Background.png\"/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ploot_select: public Ui_ploot_select {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOOT_SELECT_H
