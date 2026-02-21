/*
    Club Ploot: A chat room for your favorite ploot.
    Securing Coding Version.
    Authors: Nicholas Melchiore, Edgar Zayas, Josh Ottey, Samarth Muthalya
*/

//For now this is just the Club Ploot main file
//UPDATE (Josh): I added the enet library in the directory for the networking.
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <enet/enet.h>

using namespace std;

//A hash map for the ploot attributes (for now)
map<string, string> ploot;

int main() {
    //A dummy ploot file to create
    ifstream CP_DUMMY("dummy.ploot");
    
    if (!CP_DUMMY.is_open()) {
        cerr << "Error: couldn't open file." << std::endl;
        return 1;
    } 

    //Containers for our values and for looping for each line
    string variable, value;
    string line;

    if(CP_DUMMY.is_open()) {
        while (getline(CP_DUMMY, line)) {
            //Parsing stringstream into pairs for data flow
            std::pair<string, string> sub;

            //Create a stringstream and for each line, separate the ploot parameter and its value
            stringstream pss(line);
            getline(pss, variable, '=');
            sub.first = variable;
            getline(pss, value);
            sub.second = value;

            //Send that data over to a ploot hashmap (a dictionary)
            ploot[sub.first] = sub.second;
        }
    }
    CP_DUMMY.close();

    //Print the contents of the ploot dictionary
    cout << "Ploot's stats: " << endl;
    for (auto it = ploot.begin(); it != ploot.end(); it++) {
        cout << it->first << " = " << it->second << endl;
    }
    return 0;

}