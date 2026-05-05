#include "ploot_select.h"
#include "ui_ploot_select.h"

#include "moon_river.h"
#include "ploot.h"
#include <iostream>

#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QString>
#include "base64.hpp" //Included Base64 library from tobiasbaker: https://github.com/tobiaslocker/base64
#include <QHash>
#include <QChar>
#include <QByteArray>
#include <QStringList>
#include <QtMath>
#include <QTextCursor>
#include <QTextEdit>

QString time_stamp;
QString ploot_normal_val;
QString ploot_poison_val;
QString ploot_fire_val;
QString ploot_devil_val;
QString ploot_whimsy_val;
QString ploot_parasitic_val;
QString ploot_bunny_val;
QString ploot_rat_val;
QString ploot_scary_val;
QString ploot_gloom_val;
QString ploot_color;
QString ploot_name;
QString ploot_age;
QString ploot_kills;
QString ploot_orgin;
QString ploot_shiny;
QString ploot_accent;
QString ploot_call_sound;
QString ploot_collection_walk_sound;
QString ploot_completed_collection_sound;
QString ploot_death_sound;
QString ploot_hit_sound;
QString ploot_panic_sound;
QString ploot_rare_sound;
QString ploot_thrown_sound;
QString ploot_sparkle;

bool validated = false;

ploot_select::ploot_select(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ploot_select)
{
    ui->setupUi(this);
}

ploot_select::~ploot_select()
{
    delete ui;
}

//Opening Moon River
void ploot_select::on_pushButton_clicked()
{
    Moon_River *window = new Moon_River(this);

    //Giving the Ploot it's Name
    //If it has no name, give it a debug name
    if (ploot_name == ""){
        window->setLabelText("PLOOT NAME");
    } else {
        //Otherwise, give it it's real name.
        window->setLabelText(ploot_name);
    }

    if (ploot_color != ""){
        window->setShadowColor("#" + ploot_color.toLower());
    }

    window->show();
    this->hide();

}

//Ploot 3DES encryption code below but it is disabled for now.
//PERMUATATION TABLES

//Initial Permuation Table
static QVector<int> initial_perm = {58, 50, 42, 34, 26, 18, 10, 2,
                                    60, 52, 44, 36, 28, 20, 12, 4,
                                    62, 54, 46, 38, 30, 22, 14, 6,
                                    64, 56, 48, 40, 32, 24, 16, 8,
                                    57, 49, 41, 33, 25, 17, 9, 1,
                                    59, 51, 43, 35, 27, 19, 11, 3,
                                    61, 53, 45, 37, 29, 21, 13, 5,
                                    63, 55, 47, 39, 31, 23, 15, 7 };

//Expansion d-table
static QVector<int> exp_d = {32, 1, 2, 3, 4, 5, 4, 5,
                             6, 7, 8, 9, 8, 9, 10, 11,
                             12, 13, 12, 13, 14, 15, 16, 17,
                             16, 17, 18, 19, 20, 21, 20, 21,
                             22, 23, 24, 25, 24, 25, 26, 27,
                             28, 29, 28, 29, 30, 31, 32, 1 };


//Straight Permuation Table
static QVector<int> per = {16, 7, 20, 21,
                           29, 12, 28, 17,
                           1, 15, 23, 26,
                           5, 18, 31, 10,
                           2, 8, 24, 14,
                           32, 27, 3, 9,
                           19, 13, 30, 6,
                           22, 11, 4, 25 };

// S-box Table
static QVector<QVector<QVector<int>>> sbox = {
    {
        {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
        {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
        {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
        {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
    },

    {
        {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
        {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
        {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
        {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}
    },

    {
        {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
        {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
        {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
        {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
    },

    {
        {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
        {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
        {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
        {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
    },

    {
        {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
        {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
        {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
        {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
    },

    {
        {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
        {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
        {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
        {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
    },

    {
        {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
        {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
        {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
        {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}
    },

    {
        {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
        {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
        {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
        {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}

    }

};

//Final Permutation Table
static QVector<int> final_perm = {40, 8, 48, 16, 56, 24, 64, 32,
                                  39, 7, 47, 15, 55, 23, 63, 31,
                                  38, 6, 46, 14, 54, 22, 62, 30,
                                  37, 5, 45, 13, 53, 21, 61, 29,
                                  36, 4, 44, 12, 52, 20, 60, 28,
                                  35, 3, 43, 11, 51, 19, 59, 27,
                                  34, 2, 42, 10, 50, 18, 58, 26,
                                  33, 1, 41, 9, 49, 17, 57, 25};

//Parity bit drop table a.k.a. Permuted Choice 1 (PC-1)
static QVector<int> keyp = {57, 49, 41, 33, 25, 17, 9,
                            1, 58, 50, 42, 34, 26, 18,
                            10, 2, 59, 51, 43, 35, 27,
                            19, 11, 3, 60, 52, 44, 36,
                            63, 55, 47, 39, 31, 23, 15,
                            7, 62, 54, 46, 38, 30, 22,
                            14, 6, 61, 53, 45, 37, 29,
                            21, 13, 5, 28, 20, 12, 4};

//Number of bit shifts
static QVector<int> shift_table = {1, 1, 2, 2,
                                   2, 2, 2, 2,
                                   1, 2, 2, 2,
                                   2, 2, 2, 1};

//Compression of key from 56 bits to 48 bits
static QVector<int> key_comp = {14, 17, 11, 24, 1, 5,
                                3, 28, 15, 6, 21, 10,
                                23, 19, 12, 4, 26, 8,
                                16, 7, 27, 20, 13, 2,
                                41, 52, 31, 37, 47, 55,
                                30, 40, 51, 45, 33, 48,
                                44, 49, 39, 56, 34, 53,
                                46, 42, 50, 36, 29, 32};

//Added functions for DES encryption. Still a work-in-progress.
QString ploot_select::bin_to_hex(QString &string) {
    QString hex = "";

    //A lookup table for each binary value (4-bits) to its corresponding nybble.
    QHash<QString, QChar> binhex_map = {
        {"0000", '0'},
        {"0001", '1'},
        {"0010", '2'},
        {"0011", '3'},
        {"0100", '4'},
        {"0101", '5'},
        {"0110", '6'},
        {"0111", '7'},
        {"1000", '8'},
        {"1001", '9'},
        {"1010", 'A'},
        {"1011", 'B'},
        {"1100", 'C'},
        {"1101", 'D'},
        {"1110", 'E'},
        {"1111", 'F'}
    };
    for (int i=0; i < string.length(); i+=4) {

        //Take the bits, assemble it, and then append its corresponding nybble to the hex string.
        QString ch = "";
        ch += string[i];
        ch += string[i+1];
        ch += string[i+2];
        ch += string[i+3];
        hex += binhex_map[ch];
    }
    return hex;
}

QString ploot_select::hex_to_bin(QString &string) {
    QString bin = "";

    //A lookup table for the hex to bin conversion
    QHash<QChar, QString> hexbin_map = {
        {'0', "0000"},
        {'1', "0001"},
        {'2', "0010"},
        {'3', "0011"},
        {'4', "0100"},
        {'5', "0101"},
        {'6', "0110"},
        {'7', "0111"},
        {'8', "1000"},
        {'9', "1001"},
        {'A', "1010"},
        {'B', "1011"},
        {'C', "1100"},
        {'D', "1101"},
        {'E', "1110"},
        {'F', "1111"}
    };

    //For each nybble character in the hex string, append binary value to the binary string
    for (QChar i : string) {
        bin += hexbin_map[i];
    }
    return bin;
}

QString ploot_select::permute(QString &block, QVector<int> &arr, int n) {
    QString permutation = "";
    for (int i=0; i < n; i++) {
        permutation += block[arr[i] - 1];
    }
    return permutation;
}

QString ploot_select::shift_bit_left(QString &string, int n) {
    QString k = "";

    for (int i = n; i < string.length(); i++) k += string[i];
    for (int i = 0; i < n; i++) {
        k += string[i];
    }
    return k;
}

QString ploot_select::xor_add(QString &string1, QString &string2) {
    QString result = "";
    qDebug() << "Comparing:\n" << string1 << "\n" << string2;
    for (int j=0; j < string1.length(); j++) {
        if (string1[j] != string2[j]) {
            result += "1";
        } else {
            result += "0";
        }
    }
    return result;
}

QString ploot_select::dec_to_bin(int n) {
    QString bin = "";
    while (n > 0) {
        bin = (QChar)(n % 2 + '0') + bin;
        n /= 2;
    }
    while (bin.size() < 4) {
        bin = '0' + bin;
    }
    return bin;
}

//Convert hex to text
QString ploot_select::hex_to_char(QString &string) {
    QByteArray bytes = QByteArray::fromHex(string.toUtf8());
    QString result = QString::fromUtf8(bytes);

    return result;
}

int ploot_select::bin_to_dec(QString &string) {
    int decimal = 0, i = 0;

    for (QChar i : string) {
        decimal = (decimal << 1 | (i == '1'));
    }
    //qDebug() << "Decimal:" << decimal;

    return decimal;
}

//Key generation for round keys
void ploot_select::keygen(QString& key, QStringList &roundkeylist, QStringList &roundkeylist_bin) {
    QByteArray keyhex = key.toUtf8().toHex().toUpper();
    qDebug() << "Initial 64-bit Key (Hex): " << keyhex;
    QString key64 = keyhex;
    key64 = hex_to_bin(key64);
    qDebug() << "Initial 64-bit Key (Bin): " << key64;

    //Truncate the 64-bit key into 56-bits
    QString key56 = "";
    key56 = permute(key64, keyp, 56);

    //Get the left and right bits
    QString key_left = "", key_right = "";
    for (int i = 0; i < 28; i++) {
        key_left += key56[i];
    }

    for (int j=28; j < 56; j++) {
        key_right += key56[j];
    }
    qDebug() << "PC-1 key: " << key56 << "\nKey Left: " << key_left << "\nKey Right: " << key_right << "\n";

    //Shift the left and right halves of the key
    for (int i=0; i < 16; i++) {
        key_left = shift_bit_left(key_left, shift_table[i]);
        key_right = shift_bit_left(key_right, shift_table[i]);

        QString key56_combined = "";
        QString roundkey = "";

        //Combine the two halves into a 56-bit key and truncate to a 48-bit key
        key56_combined = key_left + key_right;
        roundkey = permute(key56_combined, key_comp, 48);

        //qDebug() << "Round key:" << i + 1 << roundkey;
        roundkeylist_bin.append(roundkey);

        roundkey = bin_to_hex(roundkey);
        roundkeylist.append(roundkey);
    }
}

//Encryption function with the chunk block, same or different key, and our round key lists
QString ploot_select::des_encrypt(QString &chunk_block, QStringList &roundkeylist, QStringList &roundkeylist_bin) {
    //Convert the base64 block and key to hex.
    //It's required for the encryption to work.
    QString encoded_block = "";

    if (chunk_block.length() == 16) {
        encoded_block = chunk_block;
    } else {
        QByteArray chunkhex = chunk_block.toUtf8().toHex().toUpper();
        encoded_block = chunkhex;
        qDebug() << "Encoded block (hex):" << encoded_block;
    }
    //QByteArray encoded_hex = encoded.toUtf8().toHex().toUpper();
    //qDebug() << "Encoded block: " << chunk_block; << "Hex:" << enc

    encoded_block = hex_to_bin(encoded_block);
    encoded_block = permute(encoded_block, initial_perm, 64);
    qDebug() << "Initial permutation of block: " << bin_to_hex(encoded_block);

    //Split the text
    QString blockleft = encoded_block.sliced(0,32);
    QString blockright = encoded_block.sliced(32, 32);
    qDebug() << "Block left:" << blockleft << "Block right:" << blockright;

    //Where the actual encryption happens
    for (int i=0; i < 16; i++) {
        //Use the Expansion D-box to expand the bits from 32 to 48 bits
        QString right_expanded = permute(blockright, exp_d, 48);
        qDebug() << "Expanded right D-box:" << right_expanded;

        //XOR current round key and expanded right
        QString xor_op = xor_add(right_expanded, roundkeylist_bin[i]);

        qDebug() << "XOR result:" << xor_op;

        //Using S-box table for calculating row and column
        QString sbox_str = "";

        for (int j = 0; j < 8; j++) {
            QString chunk = xor_op.mid(j * 6,6);
            QString rowbits = QString(chunk[0]) + chunk[5];
            QString colbits = chunk.mid(1,4);

            int row = bin_to_dec(rowbits);
            int col = bin_to_dec(colbits);

            int value = sbox[j][row][col];
            //qDebug() << "Row:" << row << "Col:" << col << "Value:" << value;
            sbox_str = sbox_str + dec_to_bin(value);
        }

        //Now permute with the straight permutation table
        sbox_str = permute(sbox_str, per, 32);

        //XOR left and sbox_str
        QString result = xor_add(blockleft, sbox_str);
        blockleft = result;

        if (i != 15) {
            QString temp = blockleft;
            blockleft = blockright;
            blockright = temp;
        }

        qDebug() << "Round" << i + 1 << bin_to_hex(blockleft) << bin_to_hex(blockright) << roundkeylist[i];
    }
    //qDebug() << "\n";
    QString combine = blockleft + blockright;

    //Now for the final permutation
    QString ciphertext = permute(combine, final_perm, 64);
    QString result = bin_to_hex(ciphertext);

    return result;
}

//Decryption function with the chunk block, same or different key, and our round key lists
QString ploot_select::des_decrypt(QString &encrypted_block, QStringList &roundkeylist, QStringList &roundkeylist_bin) {

    //Convert the base64 block and key to hex.
    //It's required for the encryption to work.
    QString encoded_block = encrypted_block;
    qDebug() << "Encoded block: " << encoded_block;

    encoded_block = hex_to_bin(encoded_block);
    encoded_block = permute(encoded_block, initial_perm, 64);
    qDebug() << "Initial permutation of block: " << bin_to_hex(encoded_block);

    //Split the text
    QString blockleft = encoded_block.sliced(0,32);
    QString blockright = encoded_block.sliced(32, 32);
    qDebug() << "Block left:" << blockleft << "Block right:" << blockright;

    //Where the actual encryption happens
    for (int i=0; i < 16; i++) {
        //Use the Expansion D-box to expand the bits from 32 to 48 bits
        QString right_expanded = permute(blockright, exp_d, 48);
        qDebug() << "Expanded right D-box:" << right_expanded;

        //XOR current round key and expanded right
        QString xor_op = xor_add(right_expanded, roundkeylist_bin[i]);

        qDebug() << "XOR result:" << xor_op;

        //Using S-box table for calculating row and column
        QString sbox_str = "";

        for (int j = 0; j < 8; j++) {
            QString chunk = xor_op.mid(j * 6,6);
            QString rowbits = QString(chunk[0]) + chunk[5];
            QString colbits = chunk.mid(1,4);

            int row = bin_to_dec(rowbits);
            int col = bin_to_dec(colbits);

            int value = sbox[j][row][col];
            //qDebug() << "Row:" << row << "Col:" << col << "Value:" << value;
            sbox_str = sbox_str + dec_to_bin(value);
        }

        //Now permute with the straight permutation table
        sbox_str = permute(sbox_str, per, 32);

        //XOR left and sbox_str
        QString result = xor_add(blockleft, sbox_str);
        blockleft = result;

        if (i != 15) {
            QString temp = blockleft;
            blockleft = blockright;
            blockright = temp;
        }

        qDebug() << "Round" << i + 1 << bin_to_hex(blockleft) << bin_to_hex(blockright) << roundkeylist[i];
    }
    qDebug() << "\n";
    QString combine = blockleft + blockright;

    //Now for the final permutation
    QString ciphertext = permute(combine, final_perm, 64);
    QString result = bin_to_hex(ciphertext);
    qDebug() << "Ciphered chunk (Hex):" << bin_to_hex(ciphertext) << "(Bin):" << ciphertext << "\n";
    return result;
}

QStringList ploot_select::TDES_decrypt(QFile &ploot_out_file) {
    //keys are 8 digits and later converted to 64 bits
    QString key1 = "34827168"; //key 1 encryption step 1
    QString key2 = "43712987"; //key 2 decryption step 2
    QString key3 = "58901264"; //key 3 encryption step 3

    int step = 0; //Step counter for encryption steps

    QStringList cipher_blocks; //Store the ciphered blocks after they're processed
    QString ci_chunk = ""; //Ciphered chunk

    //Round key lists in hex and binary
    QStringList roundkeylist = {};
    QStringList roundkeylist_bin = {};
    QStringList roundkeylist2 = {};
    QStringList roundkeylist2_bin = {};
    QStringList roundkeylist3 = {};
    QStringList roundkeylist3_bin = {};

    //Generate round keys for each step
    keygen(key1, roundkeylist, roundkeylist_bin);
    keygen(key2, roundkeylist2, roundkeylist2_bin);
    keygen(key3, roundkeylist3, roundkeylist3_bin);

    //Since this is decryption, reverse the round key lists
    std::reverse(roundkeylist.begin(), roundkeylist.end());
    std::reverse(roundkeylist_bin.begin(), roundkeylist_bin.end());
    std::reverse(roundkeylist2.begin(), roundkeylist2.end());
    std::reverse(roundkeylist2_bin.begin(), roundkeylist2_bin.end());
    std::reverse(roundkeylist3.begin(), roundkeylist3.end());
    std::reverse(roundkeylist3_bin.begin(), roundkeylist3_bin.end());

    step++; //3DES D->E->D decryption with reverse round keys

    if (step == 1) {
        //Read the file and start chunking
        if (ploot_out_file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&ploot_out_file);

            //Declare two pointers for string reading
            int start;
            int end;
            QString chunk;
            bool fix_chunk = false;

            while (!in.atEnd()) {
                start = 0;
                end = 16;

                QString line = in.readLine();
                int str_len = line.length(); //The line of string's length

                while (start <= end) {
                    chunk.append(line[start]);
                    start++;

                    if (start == end) {
                        //Print the chunk when the start pointer equals the end pointer. Then increase the end's pointer if possible.
                        qDebug() << "Good Chunk: " << chunk;
                        if (end >= str_len) {
                            qDebug() << "Done reading";
                            break;
                        }
                        else {
                            end += 16;
                        }
                        ci_chunk = des_decrypt(chunk, roundkeylist3, roundkeylist3_bin);
                        cipher_blocks.append(ci_chunk);
                        chunk.clear();
                    }
                }
            }
            ploot_out_file.close();
            qDebug() << "Step" << step << "complete! Ciphered blocks list:\n" << cipher_blocks << "\n";
            step++;
        }
    }
    if (step == 2) {
        //Reverse the round keys for the decryption
        //Pass in key 2 for the decryption

        for (int i = 0; i < cipher_blocks.length(); i++) {
            ci_chunk = des_encrypt(cipher_blocks[i], roundkeylist2, roundkeylist2_bin);
            cipher_blocks[i] = ci_chunk;
        }
        qDebug() << "Step" << step << "complete! Deciphered blocks list:\n" << cipher_blocks;
        step++;

        for (QString block : cipher_blocks) {
            qDebug() << "Decrypted block:" << hex_to_char(block);
        }
    }
    if (step == 3) {
        //Reverse the round keys for the decryption
        //Pass in key 3 for the encryption
        //qDebug() << "Checking for blocks list:\n" << cipher_blocks;
        for (int i = 0; i < cipher_blocks.length(); i++) {
            ci_chunk = des_decrypt(cipher_blocks[i], roundkeylist, roundkeylist_bin);
            cipher_blocks[i] = ci_chunk;
        }
        qDebug() << "Step" << step << "complete! Ciphered blocks list:\n" << cipher_blocks << "\nDecryption complete! Results are in the output file.";
        for (QString block : cipher_blocks) {
            qDebug() << "Decrypted block:" << hex_to_char(block);
        }
    }
    return cipher_blocks;
}

//Opening the Ploot File
void ploot_select::on_select_ploot_button_clicked()
{
    //Make sure we aren't validated
    validated = false;
    ui->pushButton->setEnabled(false);

    QString fileName = QFileDialog::getOpenFileName(
        this,
        "Open Ploot",
        "",
        "Ploot (*.ploot)"
        );

    if (!fileName.isEmpty()) {
        QFile file(fileName);

        //Ploot decryption is disabled for now but feel free to look at it if you like.

        /*
        QStringList ciphered = TDES_decrypt(file);

        for (int i = 0; i < ciphered.length(); i++) {
            ciphered[i] = hex_to_char(ciphered[i]);
            qDebug() << "DeCiphered:" << ciphered[i];
            //Convert the line to regular string for conversion

            //Check if the encoding contains a certain symbol
            qDebug() << "Cipher new line:" << ciphered[i];
            QByteArray decodedBytes = QByteArray::fromBase64(ciphered[i].toUtf8());
            ciphered[i] = QString::fromUtf8(decodedBytes);
        }

        //Clear the entire file
        if (file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
            file.close();
        }

        if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QTextStream out(&file);
            for (QString block : ciphered) {
                qDebug() << "Block:" << block;
                out << block;
            }

            file.close();
        }
        */


        //Read Ploot File
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);

            for (int i = 1; i <= 27; i++) {
                if (in.atEnd()) break;

                QString currentLine = in.readLine();

                //Go through the entire list and set the values correctly
                switch (i) {
                case 1: time_stamp = currentLine; time_stamp = time_stamp.mid(12); break;
                case 2: ploot_normal_val = currentLine; ploot_normal_val = ploot_normal_val.mid(8); break;
                case 3: ploot_poison_val = currentLine; ploot_poison_val = ploot_poison_val.mid(8); break;
                case 4: ploot_fire_val = currentLine; ploot_fire_val = ploot_fire_val.mid(6); break;
                case 5: ploot_devil_val = currentLine; ploot_devil_val = ploot_devil_val.mid(7); break;
                case 6: ploot_whimsy_val = currentLine; ploot_whimsy_val = ploot_whimsy_val.mid(8); break;
                case 7: ploot_parasitic_val = currentLine; ploot_parasitic_val = ploot_parasitic_val.mid(11); break;
                case 8: ploot_bunny_val = currentLine; ploot_bunny_val = ploot_bunny_val.mid(7); break;
                case 9: ploot_rat_val = currentLine; ploot_rat_val = ploot_rat_val.mid(5); break;
                case 10: ploot_scary_val = currentLine; ploot_scary_val = ploot_scary_val.mid(7); break;
                case 11: ploot_gloom_val = currentLine; ploot_gloom_val = ploot_gloom_val.mid(7); break;
                case 12: ploot_name = currentLine; ploot_name = ploot_name.mid(6); break;
                case 13: ploot_age = currentLine; ploot_age = ploot_age.mid(5); break;
                case 14: ploot_kills = currentLine; ploot_kills = ploot_kills.mid(7); break;
                case 15: ploot_orgin = currentLine; ploot_orgin = ploot_orgin.mid(7); break;
                case 16: ploot_shiny = currentLine; ploot_shiny = ploot_shiny.mid(7); break;
                case 17: ploot_accent = currentLine; ploot_accent = ploot_accent.mid(8); break;
                case 18: ploot_color = currentLine; ploot_color = ploot_color.mid(7); break;

                //PAST THIS POINT IS OUR BASE 64 STUFF! UNTESTED TO SEE IF IT ACTUALLY GRABS IT ALL PROPERLY!
                case 19: ploot_call_sound = currentLine; ploot_call_sound = ploot_call_sound.mid(12); break;
                case 20: ploot_collection_walk_sound = currentLine; ploot_collection_walk_sound = ploot_collection_walk_sound.mid(23); break;
                case 21: ploot_completed_collection_sound = currentLine; ploot_completed_collection_sound = ploot_completed_collection_sound.mid(28); break;
                case 22: ploot_death_sound = currentLine; ploot_death_sound = ploot_death_sound.mid(13); break;
                case 23: ploot_hit_sound = currentLine; ploot_hit_sound = ploot_hit_sound.mid(11); break;
                case 24: ploot_panic_sound = currentLine; ploot_panic_sound = ploot_panic_sound.mid(13); break;
                case 25: ploot_rare_sound = currentLine; ploot_rare_sound = ploot_rare_sound.mid(12); break;
                case 26: ploot_thrown_sound = currentLine; ploot_thrown_sound = ploot_thrown_sound.mid(14); break;
                case 27: ploot_sparkle = currentLine; ploot_sparkle = ploot_sparkle.mid(9); break;
            }

            file.close();
        }

            //Validation of Ploot
            if (ploot_color != "") {
                if (ploot_normal_val.toInt() + ploot_poison_val.toInt() + ploot_fire_val.toInt() + ploot_devil_val.toInt() + ploot_whimsy_val.toInt() + ploot_parasitic_val.toInt() + ploot_bunny_val.toInt() + ploot_rat_val.toInt() + ploot_scary_val.toInt() + ploot_gloom_val.toInt() == 100){

                    //Check Timestamp
                    QDateTime dt = QDateTime::fromString(time_stamp, "M/d/yyyy h:mm:ss AP");
                    QDateTime now = QDateTime::currentDateTime();

                    if (dt.isValid()) {
                        int daysDiff = dt.daysTo(now);

                        //Check if the ploot is still alive
                        if (daysDiff >= 0 && daysDiff <= 11 - ploot_age.toInt()) {
                            ui->pushButton->setEnabled(true);
                            validated = true;
                            ploot_age = QString::number(ploot_age.toInt() + daysDiff);
                        } else {
                            //Ploot is born in the future
                            if ((ploot_age.toInt() + daysDiff) < 0){
                                ui->ploot_label->setText("Your Ploot is illegal!");
                            } else {
                                //Ploot is too old
                                ui->ploot_label->setText("Your Ploot is dead!");
                            }


                        }

                    } else {
                        //Ploot doesn't have proper time stamp
                        ui->ploot_label->setText("Your Ploot doesn't have a proper time stamp!");
                    }

                } else {
                    //Lacks proper genetic code
                    ui->ploot_label->setText("Your Ploot lacks proper genetic code!");
                }
            } else {
                //Lacks full read
                ui->ploot_label->setText("Your Ploot is bad!");
            }

    }

    //Grab everything parsed and initialize it. It will be actually used in Moon River
    if (validated == true){
        ui->ploot_label->setText("Your Ploot is " + ploot_name);
    }
    new_ploot.setAge(ploot_age);
    new_ploot.setNormal(ploot_normal_val);
    new_ploot.setPoison(ploot_poison_val);
    new_ploot.setFire(ploot_fire_val);
    new_ploot.setDevil(ploot_devil_val);
    new_ploot.setWhimsy(ploot_whimsy_val);
    new_ploot.setParasitic(ploot_parasitic_val);
    new_ploot.setBunny(ploot_bunny_val);
    new_ploot.setRat(ploot_rat_val);
    new_ploot.setScary(ploot_scary_val);
    new_ploot.setGloom(ploot_gloom_val);
    new_ploot.setColor(ploot_color);

    }
}