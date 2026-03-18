/*
    Club Ploot: A chat room for your favorite ploot.
    The Secure Coding Version.
    Authors: Nicholas Melchiore, Edgar Zayas, Josh Ottey, and Samarth Muthyala
*/

//For now this is just the Club Ploot main file
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include "ploot.h"
#include "mainmenu.h"
using namespace std;

//Main code (work in progress)
int main(int argc, char* argv[]) {

    QApplication app(argc, argv);
    QWidget widget;

    Ui::Form ui;
    ui.setupUi(&widget);

    widget.show();
    return app.exec();
    /*
    //C++ file open handling. You can also use fopen() too.
    ifstream ploot_stream("Melissa.ploot");
    
    //Return error if something bad happens to the file
    if (!ploot_stream.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }
    
    //Declaring ploot
    Ploot ploot;
    ploot.parsePloot(ploot_stream); //Parse the text file
    ploot_stream.close(); //Close the file handling for now
    
    ploot.info(); //Print the ploot's stats from the class file
    */

}