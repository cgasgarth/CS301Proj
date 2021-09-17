#include <iostream>
#include <fstream>
#include <string>
#include "Functions.h"
using namespace std;

int main(int argc, char** argv){
    Converter c;
    if(argc == 3){
        ifstream inFile;
        ofstream outFile;
        inFile.open(argv[1], ios::in); //open a file to read from
        outFile.open(argv[2], ios::out); //open a file to write to
        string inLine;
        while( getline (inFile, inLine)) {
            cout << c.add("$zero", "$at", "$v0") << endl;
        }
    }
    cout << c.lineTakeIn("add $s0, $s1, $s2") << endl;
    return 0;
}