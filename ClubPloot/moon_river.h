#ifndef MOON_RIVER_H
#define MOON_RIVER_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class Moon_River;
}

class Moon_River : public QMainWindow
{
    Q_OBJECT

public:
    explicit Moon_River(QWidget *parent = nullptr);
    ~Moon_River();

void setLabelText(const QString &text);

protected:
    void mousePressEvent(QMouseEvent *event) override;


private slots:
    void on_ploot_text_send_clicked();

private:
    Ui::Moon_River *ui;
};

#endif // MOON_RIVER_H
