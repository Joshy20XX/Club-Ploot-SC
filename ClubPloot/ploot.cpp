#include "ploot.h"
#include <QString>

//ploot constructor
ploot::ploot() {
    age = "";
    normal = "";
    poison = "";
    fire = "";
    devil = "";
    whimsy = "";
    parasitic = "";
    bunny = "";
    rat = "";
    scary = "";
    gloom = "";
    color = "";
}

//Ploot getter setters
void ploot::setAge(QString set_ploot_age) {
    this->age = set_ploot_age;
}

void ploot::setNormal(QString set_ploot_normal) {
    this->normal = set_ploot_normal;
}

void ploot::setPoison(QString set_ploot_poison) {
    this->poison = set_ploot_poison;
}

void ploot::setFire(QString set_ploot_fire) {
    this->fire = set_ploot_fire;
}

void ploot::setDevil(QString set_ploot_devil) {
    this->devil = set_ploot_devil;
}

void ploot::setWhimsy(QString set_ploot_whimsy) {
    this->whimsy = set_ploot_whimsy;
}

void ploot::setParasitic(QString set_ploot_parasitic) {
    this->parasitic = set_ploot_parasitic;
}

void ploot::setBunny(QString set_ploot_bunny) {
    this->bunny = set_ploot_bunny;
}

void ploot::setRat(QString set_ploot_rat) {
    this->rat = set_ploot_rat;
}

void ploot::setScary(QString set_ploot_scary) {
    this->scary = set_ploot_scary;
}

void ploot::setGloom(QString set_ploot_gloom) {
    this->gloom = set_ploot_gloom;
}

void ploot::setColor(QString ploot_color_hex) {
    this->color = ploot_color_hex;
}

QString ploot::getAge() { return age; }
QString ploot::getNormal() { return normal; }
QString ploot::getPoison() { return poison; }
QString ploot::getFire() { return fire; }
QString ploot::getDevil() { return devil; }
QString ploot::getWhimsy() { return whimsy; }
QString ploot::getParasitic() { return parasitic; }
QString ploot::getBunny() { return bunny; }
QString ploot::getRat() { return rat; }
QString ploot::getScary() { return scary; }
QString ploot::getGloom() { return gloom; }
QString ploot::getColor() { return color; }

ploot new_ploot;