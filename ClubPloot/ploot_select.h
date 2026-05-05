#ifndef PLOOT_SELECT_H
#define PLOOT_SELECT_H

#include <QMainWindow>
#include <QFile>

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

    void on_select_ploot_button_clicked();

private:
    Ui::ploot_select *ui;
    QString des_encrypt(QString &encoded_block, QStringList &roundkeylist, QStringList &roundkeylist_bin);
    QString des_decrypt(QString &encrypted_block, QStringList &roundkeylist, QStringList &roundkeylist_bin);
    QStringList TDES_decrypt(QFile &ploot_out_file);
    void keygen(QString& key, QStringList &roundkeylist, QStringList &roundkeylist_bin);
    QString shift_bit_left(QString &string, int n);
    QString xor_add(QString &string1, QString &string2);
    QString permute(QString &key, QVector<int> &arr, int n);
    QString bin_to_hex(QString &string);
    QString hex_to_bin(QString &string);
    QString dec_to_bin(int n);
    int bin_to_dec(QString &string);
    QString hex_to_char(QString &string);
};

#endif // PLOOT_SELECT_H
