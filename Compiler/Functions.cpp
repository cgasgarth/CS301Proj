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
    if((reg == "$R2") || (reg == "$v0") || (reg == "$2")){
        return "00010";
    }
    if((reg == "$R3") || (reg == "$v1") || (reg == "$3")){
        return "00011";
    }
    if((reg == "$R4") || (reg == "$a0") || (reg == "$4")){
        return "00100";
    }
    if((reg == "$R5") || (reg == "$a1") || (reg == "$5")){
        return "00101";
    }
    if((reg == "$R6") || (reg == "$a2") || (reg == "$6")){
        return "00110";
    }
    if((reg == "$R7") || (reg == "$a3") || (reg == "$7")){
        return "00111";
    }
    if((reg == "$R8") || (reg == "$t0") || (reg == "$8")){
        return "01000";
    }
    if((reg == "$R9") || (reg == "$t1") || (reg == "$9")){
        return "01001";
    }
    if((reg == "$R10") || (reg == "$t2") || (reg == "$10")){
        return "01010";
    }
    if((reg == "$R11") || (reg == "$t3") || (reg == "$11")){
        return "01011";
    }
    if((reg == "$R12") || (reg == "$t4") || (reg == "$12")){
        return "01100";
    }
    if((reg == "$R13") || (reg == "$t5") || (reg == "$13")){
        return "01101";
    }
    if((reg == "$R14") || (reg == "$t6") || (reg == "$14")){
        return "01110";
    }
    if((reg == "$R15") || (reg == "$t7") || (reg == "$15")){
        return "01111";
    }
    if((reg == "$R16") || (reg == "$s0") || (reg == "$16")){
        return "10000";
    }
    if((reg == "$R17") || (reg == "$s1") || (reg == "$17")){
        return "10001";
    }
    if((reg == "$R18") || (reg == "$s2") || (reg == "$18")){
        return "10010";
    }
    if((reg == "$R19") || (reg == "$s3") || (reg == "$19")){
        return "10011";
    }
    if((reg == "$20") || (reg == "$s4") || (reg == "$20")){
        return "10100";
    }
    if((reg == "$21") || (reg == "$s5") || (reg == "$21")){
        return "10101";
    }
    if((reg == "$22") || (reg == "$s6") || (reg == "$22")){
        return "10110";
    }
    if((reg == "$23") || (reg == "$s7") || (reg == "$23")){
        return "10111";
    }
    if((reg == "$24") || (reg == "$t8") || (reg == "$24")){
        return "11000";
    }
    if((reg == "$25") || (reg == "$t9") || (reg == "$25")){
        return "11001";
    }
    if((reg == "$26") || (reg == "$k0") || (reg == "$26")){
        return "11010";
    }
    if((reg == "$27") || (reg == "$k1") || (reg == "$27")){
        return "11011";
    }
    if((reg == "$28") || (reg == "$gp") || (reg == "$28")){
        return "11100";
    }
    if((reg == "$29") || (reg == "$sp") || (reg == "$29")){
        return "11101";
    }
    if((reg == "$30") || (reg == "$s8") || (reg == "$30")){
        return "11110";
    }
    if((reg == "$31") || (reg == "$ra") || (reg == "$31")){
        return "11111";
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