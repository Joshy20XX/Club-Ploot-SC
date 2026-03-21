#ifndef PLOOT_SELECT_H
#define PLOOT_SELECT_H

#include <QMainWindow>

namespace Ui {
class ploot_select;
}

class ploot_select : public QMainWindow
{
    Q_OBJECT

public:
    explicit ploot_select(QWidget *parent = nullptr);
    ~ploot_select();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ploot_select *ui;
};

#endif // PLOOT_SELECT_H
