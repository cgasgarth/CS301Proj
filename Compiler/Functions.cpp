#include <cctype>
#include <string>
#include <stdexcept>
#include <iostream>
#include <array>
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

vector<string> Converter::lineTakeIn(string expression){
    string command;
    vector<string> out;
    for(int i = 0; i < expression.length(); i++){
        if(isspace(expression.at(i))){
            command = expression.substr(0, i);
            break;
        }
    }
    if(command == "add"){
        add(expression, out);
        return out;
    }
    if(command == "addi"){
        addi(expression, out);
        return out;
    }
    if(command == "sub"){
        sub(expression, out);
        return out;
    }
    // if(command == "mult"){
    //     return mult(expression);
    // }
    // if(command == "div"){
    //     return div(expression);
    // }
    // if(command == "mfhi"){
    //     return mfhi(expression);
    // }
    // if(command == "mflo"){
    //     return mflo(expression);
    // }
    // if(command == "sll"){
    //     return sll(expression);
    // }
    // if(command == "srl"){
    //     return srl(expression);
    // }
    // if(command == "lw"){
    //     return lw(expression);
    // }
    // if(command == "sw"){
    //     return sw(expression);
    // }
    // if(command == "slt"){
    //     return slt(expression);
    // }
    // if(command == "beq"){
    //     return beq(expression);
    // }
    // if(command == "bne"){
    //     return bne(expression);
    // }
    // if(command == "j"){
    //     return j(expression);
    // }
    // if(command == "jal"){
    //     return jal(expression);
    // }
    // if(command == "jr"){
    //     return jr(expression);
    // }
    // if(command == "jalr"){
    //     return jalr(expression);
    // }
    // if(command == "syscall"){
    //     return syscall();
    // }
    out.push_back("UNDEFINED COMMAND");
    return out;
}

array<RegLoc, 3> Converter::findRegs(string expression, int numRegs){
    array<RegLoc, 3> regs = {};
    int stringI = 0;
    int regsFound = 0;
    string substring;
    for(int i = 0; i <= expression.length(); i++){
        substring = expression.substr(stringI, i);
        for(int j = 0; j < 96; j++){ // IG Could've used a
            int location = substring.find(regList.at(j));
            if(location != string::npos){
                struct RegLoc reg;
                reg.reg = findReg(expression, stringI, i); 
                reg.loc = location;
                regs[regsFound] = reg;
                regsFound++;
                i = location + 1;
                stringI += location + 1; 
            }
        }
    }
    return regs;
}

string Converter::findReg(string expression, int stringI, int i){
    string substring = expression.substr(stringI, i+1);
    for(int j = 95; j >= 0; j--){
            int location = substring.find(regList.at(j));
            if(location != string::npos){
                return regList.at(j);
            }
        }
    return "ERROR";
}

string Converter::intToString(string intString, int totalLen){
    int n = stoi(intString);
    string binary;
    while(n!=0) {binary=(n%2==0 ?"0":"1")+binary; n/=2;}
    int remainder = totalLen - binary.length();
    string buffer;
    for (int i = 0; i < remainder; i++){
        buffer += "0";
    }
    buffer += binary;
    return buffer;
}

void Converter::add(string expression, vector<string> & out){ 
    array<RegLoc, 3> registers = findRegs(expression, 3);
    string result = "000000";
    result += regAddress(registers[1].reg);
    result += regAddress(registers[2].reg);
    result += regAddress(registers[0].reg);
    result += "00000100000"; //00000 + 0x20
    out.push_back(result);
}

void Converter::addi(string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 2);
    string result = "001000";
    result += regAddress(registers[1].reg);
    result += regAddress(registers[0].reg);
    string immediate;
    for(int i = (expression.length() - 1); i >= 0; i--){
        if(isspace(expression.at(i))){
            immediate = intToString(expression.substr(i, expression.length() - 1), 16);
            break;
        }
    }
    result += immediate;
    out.push_back(result);
}

void Converter::sub(string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 3);
    string result = "000000";
    result += regAddress(registers[1].reg);
    result += regAddress(registers[2].reg);
    result += regAddress(registers[0].reg);
    result += "00000100010";
    out.push_back(result);
}
