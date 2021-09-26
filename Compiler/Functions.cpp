#include <cctype>
#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
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

vector<string> Converter::lineTakeIn(string expression, int line){
    expression = cleanString(expression);
    string command;
    vector<string> out;
    if(expression.at(0) == '.'){
        return out;
    }
    if(expression.find(':') != string::npos){
        label tempL;
        for(int i = 0; i < expression.length(); i++){
            if(expression.at(i) == ':'){
                tempL.name = expression.substr(0, i);
            }
        }
        tempL.line = line;
        labels.push_back(tempL);
        out.push_back("Label");
        return out;
    }
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
    if(command == "mult"){
        mult(expression, out);
        return out;
    }
    if(command == "div"){
        div(expression, out);
        return out;
    }
    if(command == "mfhi"){
        mfhi(expression, out);
        return out;
    }
    if(command == "mflo"){
        mflo(expression, out);
        return out;
    }
    if(command == "sll"){
        sll(expression, out);
        return out;
    }
    if(command == "srl"){
        srl(expression, out);
        return out;
    }
    if(command == "lw"){
        lw(expression, out);
        return out;
    }
    if(command == "sw"){
        sw(expression, out);
        return out;
    }
    if(command == "slt"){
        slt(expression, out);
        return out;
    }
    if(command == "beq"){
        beq(expression, out);
        return out;
    }
    if(command == "bne"){
        bne(expression, out);
        return out;
    }
    if(command == "j" || command == "jump"){
        j(expression, out);
        return out;
    }
    if(command == "jal"){
        jal(expression, out);
        return out;
    }
    if(command == "jr"){
        jr(expression, out);
        return out;
    }
    if(command == "jalr"){
        jalr(expression, out);
        return out;
    }
    if((command == "syscall")||(expression == "syscall")){
        syscall(out);
        return out;
    }

    out.push_back("UNDEFINED COMMAND");
    return out;
}

string Converter::cleanString(string expression){
    for(int i = 0; i < expression.length(); i++){
        if((expression.at(i) != ' ') && (expression.at(i) != '\t')){
            expression = expression.substr(i, expression.length());
            break;
        }
    }
    // if(expression.at(expression.length()-1) == ' '){
    for(int i = (expression.length() - 1); i >= 0; i--){
        if((expression.at(i)) != ' ' && (expression.at(i) != '\t')){
            if(i < expression.length() - 1){
                expression = expression.substr(0, i+1);
                break;
            }
            break;
        }
    }
    return expression;
}

array<RegLoc, 3> Converter::findRegs(string expression, int numRegs){
    array<RegLoc, 3> regs = {};
    int stringI = 0;
    int regsFound = 0;
    string substring;
    for(int i = 0; i <= expression.length(); i++){
        substring = expression.substr(stringI, i);
        for(int j = 0; j < 96; j++){ // IG Could've used at
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

string Converter::intToString(int i, int totalLen){
    string binary;
    while(i!=0) {binary=(i%2==0 ?"0":"1")+binary; i/=2;}
    int remainder = totalLen - binary.length();
    string buffer;
    for (int j = 0; j < remainder; j++){
        buffer += "0";
    }
    buffer += binary;
    return buffer;
}

void Converter::setJumps(){
    ofstream outfile("hexTemp.txt");
    ifstream tempR("jumpsTemp.txt");
    string line;
    int curLine = 0;
    while(getline(tempR, line)){ //Rewrite out.txt 
        if (line.substr(0, 6) == "000100"){ // beq ND
            struct label label= setJumpsLH(line);
            int offset = label.line - curLine;
            line.replace(line.find("|"), label.name.length() + 1, intToString(offset, 16));
            outfile << line << endl;
        }
        else if(line.substr(0, 6) == "000101"){ //bne
            struct label label= setJumpsLH(line);
            int offset = label.line - curLine;
            line.replace(line.find("|"), label.name.length() + 1, intToString(offset, 16));
            outfile << line << endl;
        }
        else if(line.substr(0, 6) == "000010"){ // jump ND
            struct label label= setJumpsLH(line);
            line.replace(line.find("|"), label.name.length() + 1, intToString(label.line, 26));
            outfile << line << endl;
        }
        else if(line.substr(0, 6) == "000011"){ //jal ND
            struct label label= setJumpsLH(line);
            line.replace(line.find("|"), label.name.length() + 1, intToString(label.line, 26));
            outfile << line << endl;
        }
        else {
            outfile << line << endl;
        }
        curLine++;             
    }
    remove("jumpsTemp.txt");
}

label Converter::setJumpsLH(string expression){
    string labelName;
    for(int i = 0; i < expression.length(); i++){
        if(expression.at(i) == '|'){
            labelName = expression.substr(i + 1, expression.length());
            break;
        }
    }
    for (struct label i: labels){
        if(i.name == labelName){
            return i;
        }
    }
    label errorLab; 
    errorLab.line = -1;
    errorLab.name = "ERROR";
    return errorLab;
}

void Converter::convertToHex(int argc, char* argv[]){
    ifstream infile("hexTemp.txt");
    ofstream outfile(argv[2]);
    string line;
    while(getline(infile, line)){
        outfile << binaryToHex(line) << endl;
    }
    remove("hexTemp.txt");
}

string Converter::binaryToHex(string binaryS){
    std::string endresult = "0x";
	for(int i = 0; i < binaryS.length(); i = i+4)
	{
		endresult += getHexCharacter(binaryS.substr(i,4));
	}
	return endresult;

}
    
char Converter::getHexCharacter(std::string str)
{
	if(str.compare("1111") == 0) return 'F';
	else if(str.compare("1110") == 0) return 'E';
	else if(str.compare("1101")== 0) return 'D';
	else if(str.compare("1100")== 0) return 'C';
	else if(str.compare("1011")== 0) return 'B';
	else if(str.compare("1010")== 0) return 'A';
	else if(str.compare("1001")== 0) return '9';
	else if(str.compare("1000")== 0) return '8';
	else if(str.compare("0111")== 0) return '7';
	else if(str.compare("0110")== 0) return '6';
	else if(str.compare("0101")== 0) return '5';
	else if(str.compare("0100")== 0) return '4';
	else if(str.compare("0011")== 0) return '3';
	else if(str.compare("0010")== 0) return '2';
	else if(str.compare("0001")== 0) return '1';
	else if(str.compare("0000")== 0) return '0';
	else if(str.compare("111")== 0) return '7';
	else if(str.compare("110")== 0) return '6';
	else if(str.compare("101")== 0) return '5';
	else if(str.compare("100")== 0) return '4';
	else if(str.compare("011")== 0) return '3';
	else if(str.compare("010")== 0) return '2';
	else if(str.compare("001")== 0) return '1';
	else if(str.compare("000")== 0) return '0';
	else if(str.compare("11")== 0) return '3';
	else if(str.compare("10")== 0) return '2';
	else if(str.compare("01")== 0) return '1';
	else if(str.compare("00")== 0) return '0';
	else if(str.compare("1")== 0) return '1';
	else if(str.compare("0")== 0) return '0';
    else{ return 'Z'; };
}


string Converter::returnLabel(string expression){
    string label;
    for(int i = expression.length() - 1; i >= 0; i--){
        if(expression.at(i) == ' '){
            label = expression.substr(i + 1, expression.length());
            break;
        }
    }
    return label;
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

void Converter::mult(string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 2);
    string result = "000000";
    result += regAddress(registers[0].reg);
    result += regAddress(registers[1].reg);
    result += "0000000000011000";
    out.push_back(result);
}

void Converter::div(string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 2);
    string result = "000000";
    result += regAddress(registers[0].reg);
    result += regAddress(registers[1].reg);
    result += "0000000000011010";
    out.push_back(result);
}

void Converter::mfhi(string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 1);
    string result = "000000";
    result += "0000000000";
    result += regAddress(registers[0].reg);
    result += "00000010000";
    out.push_back(result);
}

void Converter::mflo(string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 1);
    string result = "000000";
    result += "0000000000";
    result += regAddress(registers[0].reg);
    result += "00000010010";
    out.push_back(result);
}

void Converter::sll(string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 1);
    string result = "00000000000";
    result += regAddress(registers[1].reg);
    result += regAddress(registers[0].reg);
    string immediate;
    for(int i = (expression.length() - 1); i >= 0; i--){
        if(isspace(expression.at(i))){
            immediate = intToString(expression.substr(i, expression.length() - 1), 5);
            break;
        }
    }
    result += immediate;
    result += "000000";
    out.push_back(result);
}

void Converter::srl(string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 1);
    string result = "00000000000";
    result += regAddress(registers[1].reg);
    result += regAddress(registers[0].reg);
    string immediate;
    for(int i = (expression.length() - 1); i >= 0; i--){
        if(isspace(expression.at(i))){
            immediate = intToString(expression.substr(i, expression.length() - 1), 5);
            break;
        }
    }
    result += immediate;
    result += "000010";
    out.push_back(result);
}

void Converter::lw(string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 2);
    string result = "100011";
    result += regAddress(registers[1].reg);
    result += regAddress(registers[0].reg);
    string immediate;
    int leftPar; 
    for(int i = (expression.length() - 1); i >= 0; i--){
        if(expression.at(i) == '('){ leftPar = i; }
        if(isspace(expression.at(i))){
            immediate = intToString(expression.substr(i, leftPar), 16);
            break;
        }
    }
    result += immediate;
    out.push_back(result);
}

void Converter::sw(string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 1);
    string result = "101011";
    result += regAddress(registers[1].reg);
    result += regAddress(registers[0].reg);
    string immediate;
    int leftPar; 
    for(int i = (expression.length() - 1); i >= 0; i--){
        if(expression.at(i) == '('){ leftPar = i; }
        if(isspace(expression.at(i))){
            immediate = intToString(expression.substr(i, leftPar), 16);
            break;
        }
    }
    result += immediate;
    out.push_back(result);
}

void Converter::slt(string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 3);
    string result = "000000";
    result += regAddress(registers[1].reg);
    result += regAddress(registers[2].reg);
    result += regAddress(registers[0].reg);
    result += "00000100000"; //00000 + 0x20
    out.push_back(result);
}

void Converter::beq(string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 2);
    string result = "000100";
    result += regAddress(registers[0].reg);
    result += regAddress(registers[1].reg);
    result += "|" + returnLabel(expression);
    out.push_back(result);
}

void Converter::bne(string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 2);
    string result = "000101";
    result += regAddress(registers[0].reg);
    result += regAddress(registers[1].reg);
    result += "|" + returnLabel(expression);
    out.push_back(result);
}

void Converter::j(string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 1);
    string result = "000010";
    result += "|" + returnLabel(expression);
    out.push_back(result);
}

void Converter::jal(string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 1);
    string result = "000011";
    result += "|" + returnLabel(expression);
    out.push_back(result);
}

void Converter::jr(string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 1);
    string result = "000000";
    result += regAddress(registers[0].reg);
    result += "000000000000000001000";
    out.push_back(result);
}

void Converter::jalr(string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 2);
    string result = "000000";
    result += regAddress(registers[1].reg);
    result += "00000";
    result += regAddress(registers[0].reg);
    result += "00000001001";
    out.push_back(result);
}

void Converter::syscall(vector<string> & out){
    out.push_back("00000000000000000000000000001100");
}
