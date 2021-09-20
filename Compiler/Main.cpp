#include <iostream>
#include <fstream>
#include <string>
#include "Functions.h"
using namespace std;

int main(int argc, char** argv){
    if(argc != 3){
        cout << "requires ASSEMBLE [input.asm] [output.txt]" << endl;
        return 0;
    }
    // open the input file
    ifstream infile(argv[1]);

    if (!infile.is_open()){  //error in the case of file not opening
        std::cerr << "Error: could not open file: " << argv[1] << std::endl;
        std::exit(1);
    }

    // open the output file 
    ofstream outfile(argv[2]);

    if (!outfile){ //error in the case of file not opening
        std::cerr << "Error: could not open file: " << argv[2] << std::endl;
        std::exit(1);
    }

    string line;
    string instruction;

    while(getline(infile, line)){
        int i = 0;
        while((i < line.length()) and (line[i] != '#')){
            instruction += line[i];
            i++;
        }
        cout << "instruction: " << instruction << endl;
        //pass instruction into function
        instruction = "";
    }


    // Converter c;
    // string inLine;
    // while( getline (inFile, inLine)) {
    //     cout << c.add("$zero", "$at", "$v0") << endl;
    // }
    
    return 0;
}