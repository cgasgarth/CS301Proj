#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

    if (!outfile.is_open()){ //error in the case of file not opening
        std::cerr << "Error: could not open file: " << argv[2] << std::endl;
        std::exit(1);
    }
    ofstream tempFile("jumpsTemp.txt");
    string line;
    string instruction;
    Converter c;
    vector<string> binaryOut;
    int curLine = 0;

    while(getline(infile, line)){
        int i = 0;
        while((i < line.length()) && (line[i] != '#') && (line[i] != '\r')){
            instruction += line[i];
            i++;
        }
        if(instruction.length() > 0){
            binaryOut = c.lineTakeIn(instruction, curLine);
            for (string j: binaryOut){
                if(j == "Label"){
                    break;
                }
                tempFile << j << endl;
                curLine ++;
            } 
        }
        binaryOut.clear();
        instruction = "";

    }
    c.setJumps();
    c.convertToHex(argc, argv);
    return 0;
}