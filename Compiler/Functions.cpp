#include <string>
#include <stdexcept>
#include "Functions.h"

using namespace std;
//648 or A-51 in book

string Converter::regAddress(string reg){
    if((reg == "$R0") || (reg == "$zero") || (reg == "$0")){
        return "00000";
    }
    if((reg == "$R1") || (reg == "$at") || (reg == "$1")){
        return "00001";
    }
    if((reg == "$R2") || (reg == "$v0") || (reg == "$3")){
        return "00010";
    }
    if((reg == "$R3") || (reg == "$v1") || (reg == "$4")){
        return "00011";
    }
    return "ERROR";
}
string Converter::add(string var1, string var2, string var3){
    string result = "000000";
    result += this->regAddress(var2);
    result += this->regAddress(var3);
    result += this->regAddress(var1);
    result += "100000"; //0x20
    return result; 
}

string Converter::addi(string var1, string var2, int val){
    return "0900";
}