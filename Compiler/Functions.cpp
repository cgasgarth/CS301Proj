#include <string>
#include <iostream>
#include <fstream>
#include <array>
#include <math.h>
#include "Functions.h"

using namespace std;
//648 or A-51 in book

string Converter::regAddress(const string reg){
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
    if((reg == "$R20") || (reg == "$s4") || (reg == "$20")){
        return "10100";
    }
    if((reg == "$R21") || (reg == "$s5") || (reg == "$21")){
        return "10101";
    }
    if((reg == "$R22") || (reg == "$s6") || (reg == "$22")){
        return "10110";
    }
    if((reg == "$R23") || (reg == "$s7") || (reg == "$23")){
        return "10111";
    }
    if((reg == "$R24") || (reg == "$t8") || (reg == "$24")){
        return "11000";
    }
    if((reg == "$R25") || (reg == "$t9") || (reg == "$25")){
        return "11001";
    }
    if((reg == "$R26") || (reg == "$k0") || (reg == "$26")){
        return "11010";
    }
    if((reg == "$R27") || (reg == "$k1") || (reg == "$27")){
        return "11011";
    }
    if((reg == "$R28") || (reg == "$gp") || (reg == "$28")){
        return "11100";
    }
    if((reg == "$R29") || (reg == "$sp") || (reg == "$29")){
        return "11101";
    }
    if((reg == "$R30") || (reg == "$s8") || (reg == "$30")){
        return "11110";
    }
    if((reg == "$R31") || (reg == "$ra") || (reg == "$31")){
        return "11111";
    }
    return "reg address error";
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
    if(command == "and"){
        andC(expression, out);
        return out;
    }
    if(command == "or"){
        orC(expression, out);
        return out;
    }
    if(command == "nor"){
        norC(expression, out);
        return out;
    }
    if(command == "xor"){
        xorC(expression, out);
        return out;
    }
    if(command == "andi"){
        andiC(expression, out);
        return out;
    }
    if(command == "ori"){
        oriC(expression, out);
        return out;
    }
    if(command == "xori"){
        xoriC(expression, out);
        return out;
    }
    if(command == "sgt"){
        sgt(expression, out, line);
        return out;
    }
    if(command == "sge"){
        sge(expression, out, line);
        return out;
    }
    if(command == "sle"){
        sle(expression, out, line);
        return out;
    }
    if(command == "seq"){
        seq(expression, out, line);
        return out;
    }
    if(command == "sne"){
        sne(expression, out, line);
        return out;
    }
    if(command == "move"){
        move(expression, out);
        return out;
    }
    if(command == "li"){
        li(expression, out);
        return out;
    }
    if(command == "bge"){
        bge(expression, out, line);
        return out;
    }
    if(command == "bgt"){
        bgt(expression, out, line);
        return out;
    }
    if(command == "ble"){
        ble(expression, out, line);
        return out;
    }
    if(command == "blt"){
        blt(expression, out, line);
        return out;
    }
    if(command == "abs"){
        abs(expression, out, line);
        return out;
    } 
    out.push_back("00000000000000000000000000000000");
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
    return "FindRegError";
}

string Converter::intToBinaryString(string intString, int totalLen){
    int n = stoi(intString);
    if(n < 0) {
        n += pow(2, totalLen);
    }
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

string Converter::intToBinaryString(int i, int totalLen){
    if(i < 0) {
        i += pow(2, totalLen);
    }
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
            struct label label = setJumpsLH(line);
            int offset = label.line - curLine;
            line.replace(line.find("|"), label.name.length() + 1, intToBinaryString(offset, 16));
            outfile << line << "\n";
        }
        else if(line.substr(0, 6) == "000101"){ //bne
            struct label label= setJumpsLH(line);
            int offset = label.line - curLine;
            line.replace(line.find("|"), label.name.length() + 1, intToBinaryString(offset, 16));
            outfile << line << "\n";
        }
        else if(line.substr(0, 6) == "000010"){ // jump ND
            struct label label= setJumpsLH(line);
            line.replace(line.find("|"), label.name.length() + 1, intToBinaryString(label.line, 26));
            outfile << line << "\n";
        }
        else if(line.substr(0, 6) == "000011"){ //jal ND
            struct label label= setJumpsLH(line);
            line.replace(line.find("|"), label.name.length() + 1, intToBinaryString(label.line, 26));
            outfile << line << "\n";
        }
        else {
            outfile << line << "\n";
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
    errorLab.name = "setJumpsLH Error";
    return errorLab;
}

void Converter::convertToHex(int argc, char* argv[]){
    ifstream infile("hexTemp.txt");
    ofstream outfile(argv[2]);
    outfile << "v3.0 hex words plain" << "\n";
    string line;
    while(getline(infile, line)){
        outfile << binaryToHex(line) << "\n";
    }
    remove("hexTemp.txt");
}

string Converter::binaryToHex(string binaryS){
    string endresult;
	for(int i = 0; i < binaryS.length(); i = i+4)
	{
		endresult += getHexCharacter(binaryS.substr(i,4));
	}
	return endresult;

}
    
char Converter::getHexCharacter(std::string str)
{
	if(str.compare("1111") == 0) return 'f';
	else if(str.compare("1110") == 0) return 'e';
	else if(str.compare("1101")== 0) return 'd';
	else if(str.compare("1100")== 0) return 'c';
	else if(str.compare("1011")== 0) return 'b';
	else if(str.compare("1010")== 0) return 'a';
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


string Converter::returnLabel(const string expression){
    string label;
    for(int i = expression.length() - 1; i >= 0; i--){
        if(expression.at(i) == ' '){
            label = expression.substr(i + 1, expression.length());
            break;
        }
    }
    return label;
}

void Converter::add(const string expression, vector<string> & out){ 
    array<RegLoc, 3> registers = findRegs(expression, 3);
    string result = "000000";
    result += regAddress(registers[1].reg);
    result += regAddress(registers[2].reg);
    result += regAddress(registers[0].reg);
    result += "00000100000"; //00000 + 0x20
    out.push_back(result);
}

void Converter::addi(const string expression, vector<string> & out){
    string immediate;
    int immediateI = 0;
    array<RegLoc, 3> registers = findRegs(expression, 2);
    for(int i = (expression.length() - 1); i >= 0; i--){
        if(isspace(expression.at(i))){
            immediateI = stoi(expression.substr(i, expression.length() - 1));
            immediate = intToBinaryString(expression.substr(i, expression.length() - 1), 16);
            break;
        }
    }
    if((immediateI > 32767) && (immediateI < 2147483647)){
        int quotient = immediateI / 32767;
        int remainder = immediateI % 32767;
        string e = "addi " + registers[0].reg + ", " + registers[1].reg + ", 32767";
        for(int j = 0; j < quotient; j++){
            addi(e, out);
        }
        e = "addi " + registers[0].reg + ", " + registers[1].reg + ", " + to_string(remainder);
        addi(e, out);
        return;
    }
    if((immediateI < (-32768)) && (immediateI > -2147483647)){
        int quotient = immediateI / 32767;
        int remainder = immediateI % 32767;
        string e = "addi " + registers[0].reg + ", " + registers[1].reg + ", 32767";
        for(int j = 0; j < quotient; j++){
            addi(e, out);
        }
        e = "addi " + registers[0].reg + ", " + registers[1].reg + ", " + to_string(remainder);
        addi(e, out);
        return;
    }
    string result = "001000";
    result += regAddress(registers[1].reg);
    result += regAddress(registers[0].reg);
    result += immediate;
    out.push_back(result);
}

void Converter::sub(const string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 3);
    string result = "000000";
    result += regAddress(registers[1].reg);
    result += regAddress(registers[2].reg);
    result += regAddress(registers[0].reg);
    result += "00000100010";
    out.push_back(result);
}

void Converter::mult(const string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 2);
    string result = "000000";
    result += regAddress(registers[0].reg);
    result += regAddress(registers[1].reg);
    result += "0000000000011000";
    out.push_back(result);
}

void Converter::div(const string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 2);
    string result = "000000";
    result += regAddress(registers[0].reg);
    result += regAddress(registers[1].reg);
    result += "0000000000011010";
    out.push_back(result);
}

void Converter::mfhi(const string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 1);
    string result = "000000";
    result += "0000000000";
    result += regAddress(registers[0].reg);
    result += "00000010000";
    out.push_back(result);
}

void Converter::mflo(const string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 1);
    string result = "000000";
    result += "0000000000";
    result += regAddress(registers[0].reg);
    result += "00000010010";
    out.push_back(result);
}

void Converter::sll(const string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 1);
    string result = "00000000000";
    result += regAddress(registers[1].reg);
    result += regAddress(registers[0].reg);
    string immediate;
    for(int i = (expression.length() - 1); i >= 0; i--){
        if(isspace(expression.at(i))){
            immediate = intToBinaryString(expression.substr(i, expression.length() - 1), 5);
            break;
        }
    }
    result += immediate;
    result += "000000";
    out.push_back(result);
}

void Converter::srl(const string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 1);
    string result = "00000000000";
    result += regAddress(registers[1].reg);
    result += regAddress(registers[0].reg);
    string immediate;
    for(int i = (expression.length() - 1); i >= 0; i--){
        if(isspace(expression.at(i))){
            immediate = intToBinaryString(expression.substr(i, expression.length() - 1), 5);
            break;
        }
    }
    result += immediate;
    result += "000010";
    out.push_back(result);
}

void Converter::lw(const string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 2);
    string result = "100011";
    result += regAddress(registers[1].reg);
    result += regAddress(registers[0].reg);
    string immediate;
    int leftPar; 
    for(int i = (expression.length() - 1); i >= 0; i--){
        if(expression.at(i) == '('){ leftPar = i; }
        if(isspace(expression.at(i))){
            immediate = intToBinaryString(expression.substr(i, leftPar), 16);
            break;
        }
    }
    result += immediate;
    out.push_back(result);
}

void Converter::sw(const string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 1);
    string result = "101011";
    result += regAddress(registers[1].reg);
    result += regAddress(registers[0].reg);
    string immediate;
    int leftPar; 
    for(int i = (expression.length() - 1); i >= 0; i--){
        if(expression.at(i) == '('){ leftPar = i; }
        if(isspace(expression.at(i))){
            immediate = intToBinaryString(expression.substr(i, leftPar), 16);
            break;
        }
    }
    result += immediate;
    out.push_back(result);
}

void Converter::slt(const string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 3);
    string result = "000000";
    result += regAddress(registers[1].reg);
    result += regAddress(registers[2].reg);
    result += regAddress(registers[0].reg);
    result += "00000101010"; //00000 + 0x20
    out.push_back(result);
}

void Converter::beq(const string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 2);
    string result = "000100";
    result += regAddress(registers[0].reg);
    result += regAddress(registers[1].reg);
    result += "|" + returnLabel(expression);
    out.push_back(result);
}

void Converter::bne(const string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 2);
    string result = "000101";
    result += regAddress(registers[0].reg);
    result += regAddress(registers[1].reg);
    result += "|" + returnLabel(expression);
    out.push_back(result);
}

void Converter::j(const string expression, vector<string> & out){
    string result = "000010";
    result += "|" + returnLabel(expression);
    out.push_back(result);
}

void Converter::jal(const string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 1);
    string result = "000011";
    result += "|" + returnLabel(expression);
    out.push_back(result);
}

void Converter::jr(const string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 1);
    string result = "000000";
    result += regAddress(registers[0].reg);
    result += "000000000000000001000";
    out.push_back(result);
}

void Converter::jalr(const string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 2);
    string result = "000000";
    result += regAddress(registers[0].reg);
    result += "00000";
    result += regAddress(registers[1].reg);
    result += "00000001001";
    out.push_back(result);
}

void Converter::syscall(vector<string> & out){
    out.push_back("00000000000000001101000000001001");
}
void Converter::andC(string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 3);
    string result = "000000";
    result += regAddress(registers[1].reg);
    result += regAddress(registers[2].reg);
    result += regAddress(registers[0].reg);
    result += "00000100100"; //00000 + 0x20
    out.push_back(result);
}  
void Converter::orC(string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 3);
    string result = "000000";
    result += regAddress(registers[1].reg);
    result += regAddress(registers[2].reg);
    result += regAddress(registers[0].reg);
    result += "00000100101"; //00000 + 0x20
    out.push_back(result);
}
void Converter::norC(string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 3);
    string result = "000000";
    result += regAddress(registers[1].reg);
    result += regAddress(registers[2].reg);
    result += regAddress(registers[0].reg);
    result += "00000100111"; //00000 + 0x20
    out.push_back(result);
}
void Converter::xorC(string expression, vector<string> & out){
    array<RegLoc, 3> registers = findRegs(expression, 3);
    string result = "000000";
    result += regAddress(registers[1].reg);
    result += regAddress(registers[2].reg);
    result += regAddress(registers[0].reg);
    result += "00000100110"; //00000 + 0x20
    out.push_back(result);
}
void Converter::andiC(string expression, vector<string> & out){
    string immediate;
    // int immediateI = 0;
    array<RegLoc, 3> registers = findRegs(expression, 2);
    for(int i = (expression.length() - 1); i >= 0; i--){
        if(isspace(expression.at(i))){
            // immediateI = stoi(expression.substr(i, expression.length() - 1));
            immediate = intToBinaryString(expression.substr(i, expression.length() - 1), 16);
            break;
        }
    }
    string result = "001100";
    result += regAddress(registers[1].reg);
    result += regAddress(registers[0].reg);
    result += immediate;
    out.push_back(result);
}
void Converter::oriC(string expression, vector<string> & out){
    string immediate;
    // int immediateI;
    array<RegLoc, 3> registers = findRegs(expression, 2);
    for(int i = (expression.length() - 1); i >= 0; i--){
        if(isspace(expression.at(i))){
            // immediateI = stoi(expression.substr(i, expression.length() - 1));
            immediate = intToBinaryString(expression.substr(i, expression.length() - 1), 16);
            break;
        }
    }
    string result = "001101";
    result += regAddress(registers[1].reg);
    result += regAddress(registers[0].reg);
    result += immediate;
    out.push_back(result);
}
void Converter::xoriC(string expression, vector<string> & out){
    string immediate;
    // int immediateI;
    array<RegLoc, 3> registers = findRegs(expression, 2);
    for(int i = (expression.length() - 1); i >= 0; i--){
        if(isspace(expression.at(i))){
            // immediateI = stoi(expression.substr(i, expression.length() - 1));
            immediate = intToBinaryString(expression.substr(i, expression.length() - 1), 16);
            break;
        }
    }
    string result = "001110";
    result += regAddress(registers[1].reg);
    result += regAddress(registers[0].reg);
    result += immediate;
    out.push_back(result);
}
//BONUS MIPS
void Converter::sgt(string expression, vector<string> & out, int line){
    string sLine = to_string(line);
    array<RegLoc, 3> registers = findRegs(expression, 2);

    string slt = "slt $at, " + registers[1].reg + ", " + registers[2].reg;
    this->slt(slt, out);

    string beq = "beq $at, $zero, GE" + sLine;
    this->beq(beq, out);

    string jump1 = "j LTEQ" + sLine;
    this->j(jump1, out);

    string GE = "GE" + sLine;
    label tempL;
    tempL.name = GE;
    tempL.line = line + 3;
    labels.push_back(tempL);
    out.push_back("Label");

    string beq2 = "beq " + registers[1].reg + ", " + registers[0].reg + ", LTEQ" + sLine;
    this->beq(beq2, out);

    string addi = "addi " + registers[0].reg + ", $zero, 1";
    this->addi(addi, out);

    string jump2 = "j end" + sLine;
    this->j(jump2, out);

    string LTEQ = "LTEQ" + sLine;
    tempL.name = LTEQ;
    tempL.line = line + 6;
    labels.push_back(tempL);
    out.push_back("Label");

    string addi2 = "addi " + registers[0].reg + ", $zero, 0";
    this->addi(addi2, out);

    string end = "end" + sLine;
    tempL.name = end;
    tempL.line = line + 7;
    labels.push_back(tempL);
    out.push_back("Label");
}
    
void Converter::sge(string expression, vector<string> & out, int line){
    string sLine = to_string(line);
    array<RegLoc, 3> registers = findRegs(expression, 2);
    //sge $s2, $s1, $s0
    string slt = "slt $at, " + registers[1].reg + ", " + registers[2].reg; //stl $at, $s1, $s0
    this->slt(slt, out);

    string beq = "beq $at, $zero, GTEQ" + sLine; //beq $at, $zero, GTEQ
    this->beq(beq, out);

    string addi = "addi " + registers[0].reg + ", $zero, 0"; //addi $s2, $zero, 0
    this->addi(addi, out);

    string jump1 = "j end" + sLine; //j end
    this->j(jump1, out);

    string GTEQ = "GTEQ" + sLine;
    label tempL;
    tempL.name = GTEQ;
    tempL.line = line + 4;
    labels.push_back(tempL);
    out.push_back("Label");

    addi = "addi " + registers[0].reg + ", $zero, 1";
    this->addi(addi, out);

    string end = "end" + sLine;
    tempL.name = end;
    tempL.line = line + 5;
    labels.push_back(tempL);
    out.push_back("Label");
}

void Converter::sle(string expression, vector<string> & out, int line){
    string sLine = to_string(line);
    array<RegLoc, 3> registers = findRegs(expression, 2);

    string slt = "slt $at, " + registers[1].reg + ", " + registers[2].reg;
    this->slt(slt, out);

    string beq = "beq $at, $zero, GTEQ" + sLine;
    this->beq(beq, out);

    string addi = "addi " + registers[0].reg + ", $zero, 1";
    this->addi(addi, out);

    string jump1 = "j end" + sLine;
    this->j(jump1, out);

    string GTEQ = "GTEQ" + sLine;
    label tempL;
    tempL.name = GTEQ;
    tempL.line = line + 4;
    labels.push_back(tempL);
    out.push_back("Label");

    string beq2 = "beq " + registers[1].reg + ", " + registers[2].reg + ", EQ" + sLine;
    this->beq(beq2, out);

    addi = "addi " + registers[0].reg + ", $zero, 0";
    this->addi(addi, out);

    string jump2 = "j end" + sLine;
    this->j(jump2, out);

    string EQ = "EQ" + sLine;
    tempL.name = EQ;
    tempL.line = line + 7;
    labels.push_back(tempL);
    out.push_back("Label");

    addi = "addi " + registers[0].reg + ", $zero, 1";
    this->addi(addi, out);

    string end = "end" + sLine;
    tempL.name = end;
    tempL.line = line + 8;
    labels.push_back(tempL);
    out.push_back("Label");
}

void Converter::seq(string expression, vector<string> & out, int line){}

void Converter::sne(string expression, vector<string> & out, int line){}

void Converter::move(string expression, vector<string> & out){
    expression += ", $zero";
    add(expression, out);
}

void Converter::li(string expression, vector<string> & out){
    int comma = expression.find(',');
    expression.insert(comma + 1, " $zero,");
    addi(expression, out);
}

void Converter::bge(string expression, vector<string> & out, int line){ // Maybe done? 
    // bge $s0, $s1, label
    // translates to
    // slt $at, $s0, $s1
    // beq $at, $zero, label
    string label = returnLabel(expression);
    array<RegLoc, 3> registers = findRegs(expression, 2);
    
    string slt = "slt $at, " + registers[0].reg + ", " + registers[1].reg;
    this->slt(slt, out);
    slt = "beq $at, $zero, " + label;
    this->beq(slt, out);
}

void Converter::bgt(string expression, vector<string> & out, int line){
    // # bgt $s0, $s1, label
    // # translates to
    // slt $at, $s1, $s0
    // bne $at, $zero, label   
    string label = returnLabel(expression);
    array<RegLoc, 3> registers = findRegs(expression, 2);
    
    string slt = "slt $at, " + registers[1].reg + ", " + registers[0].reg;
    this->slt(slt, out);
    slt = "bne $at, $zero, " + label;
    this->bne(slt, out);
}

void Converter::ble(string expression, vector<string> & out, int line){ //hope these work
    // # ble $s0, $s1, label
    // # translates to
    // slt $at, $s1, $s0
    // beq $at, $zero, label
    string label = returnLabel(expression);
    array<RegLoc, 3> registers = findRegs(expression, 2);
    
    string slt = "slt $at, " + registers[1].reg + ", " + registers[0].reg;
    this->slt(slt, out);
    slt = "beq $at, $zero, " + label;
    this->beq(slt, out);
}

void Converter::blt(string expression, vector<string> & out, int line){
    // # blt $s0, $s1, label
    // # translates to
    // slt $at, $s0, $s1
    // bne $at, $zero, label
    string label = returnLabel(expression);
    array<RegLoc, 3> registers = findRegs(expression, 2);
    
    string slt = "slt $at, " + registers[0].reg + ", " + registers[1].reg;
    this->slt(slt, out);
    slt = "bne $at, $zero, " + label;
    this->bne(slt, out);
}

void Converter::abs(string expression, vector<string> & out, int line){}
