#ifndef MOON_RIVER_H
#define MOON_RIVER_H

#include <QMainWindow>

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

void setShadowColor(const QColor &color);

void parseCussWords();

int countRudeness(const QString &temp_text);

protected:
    void mousePressEvent(QMouseEvent *event) override;


private slots:

    void on_ploot_text_send_clicked();

    void on_ploot_text_bar_textChanged();

    void on_toolButton_clicked(bool checked);

    void on_pushButton_clicked(bool checked);

private:
    Ui::Moon_River *ui;
};

#endif // MOON_RIVER_H
