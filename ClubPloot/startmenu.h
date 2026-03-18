#ifndef STARTMENU_H
#define STARTMENU_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class StartMenu;
}
QT_END_NAMESPACE

class StartMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartMenu(QWidget *parent = nullptr);
    ~StartMenu() override;

private slots:
    void on_actionExit_triggered();

    void on_pushButton_2_clicked();

    void on_actionAbout_triggered();

private:
    Ui::StartMenu *ui;
};
#endif // STARTMENU_H
