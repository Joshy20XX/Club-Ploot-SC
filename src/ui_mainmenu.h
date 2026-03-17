/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QAction *actionExit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(473, 601);
        actionExit = new QAction(Form);
        actionExit->setObjectName("actionExit");
        actionExit->setMenuRole(QAction::MenuRole::QuitRole);
        label = new QLabel(Form);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 230, 321, 51));
        label_2 = new QLabel(Form);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 50, 161, 171));
        label_3 = new QLabel(Form);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 280, 341, 91));
        label_4 = new QLabel(Form);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(90, 360, 311, 51));
        pushButton = new QPushButton(Form);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(120, 430, 101, 51));
        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(260, 430, 101, 51));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        actionExit->setText(QCoreApplication::translate("Form", "Exit", nullptr));
        label->setText(QCoreApplication::translate("Form", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:700;\">Welcome to Club Ploot!</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "<html><head/><body><p><img src=\":/images/Ploot_Fraymakers.png\"/></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "<html><head/><body><p align=\"center\">A <span style=\" font-style:italic;\">Club Penguin</span>-inspired chat room based on an original game, </p><p align=\"center\"><span style=\" font-style:italic;\">Ploot</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("Form", "Locate your exported ploot from the game to get started!", nullptr));
        pushButton->setText(QCoreApplication::translate("Form", "Open", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Form", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
