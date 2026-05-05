#ifndef LOGIN_SCREEN_H
#define LOGIN_SCREEN_H

#include <QMainWindow>

namespace Ui {
class login_screen;
}

class login_screen : public QMainWindow
{
    Q_OBJECT

public:
    explicit login_screen(QWidget *parent = nullptr);
    ~login_screen();

private slots:
    void on_pushButton_clicked();

private:
    Ui::login_screen *ui;
};

#endif // LOGIN_SCREEN_H
