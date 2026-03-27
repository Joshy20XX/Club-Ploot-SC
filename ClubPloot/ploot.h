#ifndef PLOOT_H
#define PLOOT_H
#include <QString>

class ploot
{
private:
    QString age;
    QString normal;
    QString poison;
    QString fire;
    QString devil;
    QString whimsy;
    QString parasitic;
    QString bunny;
    QString rat;
    QString scary;
    QString gloom;
    QString color;
public:
    void setAge(QString set_ploot_age);
    void setNormal(QString set_ploot_normal);
    void setPoison(QString set_ploot_poison);
    void setFire(QString set_ploot_fire);
    void setDevil(QString set_ploot_devil);
    void setWhimsy(QString set_ploot_whimsy);
    void setParasitic(QString set_ploot_parasitic);
    void setBunny(QString set_ploot_bunny);
    void setRat(QString set_ploot_rat);
    void setScary(QString set_ploot_scary);
    void setGloom(QString set_ploot_gloom);
    void setColor(QString ploot_color_hex);
    QString getAge();
    QString getNormal();
    QString getPoison();
    QString getFire();
    QString getDevil();
    QString getWhimsy();
    QString getParasitic();
    QString getBunny();
    QString getRat();
    QString getGloom();
    QString getScary();
    QString getColor();
    ploot(); //constructor
    //~ploot(); //deconstructor
};

extern ploot new_ploot;

#endif // PLOOT_H
