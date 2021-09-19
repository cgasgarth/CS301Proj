#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Functions.h"
using namespace std;

int main(int argc, char** argv){
    Converter c;
    vector<string> out;
    vector<string> lineOut;
    lineOut = c.lineTakeIn("sll $s0, $s1, 10");
    out.insert(out.end(), lineOut.begin(), lineOut.end());
    for (vector<string>::iterator t = out.begin(); t != out.end(); ++t) 
    {
        cout<<*t<<endl;
    }

    return 0;
}
