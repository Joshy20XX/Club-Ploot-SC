#ifndef LOGIN_SCEEN_H
#define LOGIN_SCEEN_H

#include <QMainWindow>

namespace Ui {
class login_sceen;
}

class login_sceen : public QMainWindow
{
    Q_OBJECT

public:
    explicit login_sceen(QWidget *parent = nullptr);
    ~login_sceen();

private slots:
    void on_pushButton_clicked();

private:
    Ui::login_sceen *ui;
};

#endif // LOGIN_SCEEN_H
