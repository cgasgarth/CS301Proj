#include <string>
#include <array>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
using namespace std;


struct RegLoc{
    string reg;
    int loc;
};
struct label{
    string name;
    int line;
};
class Converter { //648 or A-51 in book
    public:
    array<string, 96> regList = {"$R0","$zero","$0","R1","$at","$1", 
                                 "$R2","$v0","$2","$R3","$v1","$3",
                                 "$R4","$a0","$4","$R5","$a1","$5",
                                 "$R6","$a2","$6","$R7","$a3","$7",
                                 "$R8","$t0","$8","$R9","$t1","$9",
                                 "$R10","$t2","$10","$R11","$t3","$11",
                                 "$R12","$t4","$12","$R13","$t5","$13",
                                 "$R14","$t6","$14","$R15","$t7","$15",
                                 "$R16","$s0","$16","$R17","$s1","$17",
                                 "$R18","$s2","$18","$R19","$s3","$19",
                                 "$R20","$s4","$20","$R21","$s5","$21",
                                 "$R22","$s6","$22","$R23","$s7","$23",
                                 "$R24","$t8","$24","$R25","$t9","$25",
                                 "$R26","$k0","$26","$R27","$k1","$27",
                                 "$R28","$gp","$28","$R29","$sp","$29",
                                 "$R30","$s8","$30","$R31","$ra","$31"}; //List of all regs
    vector<label> labels;
    string regAddress(string reg); //DONE, VALIDATED KINDA; return binary address of a reg
    vector<string> lineTakeIn(string expression, int line); //IDK if going to be used
    string cleanString(string expression);
    array<RegLoc, 3> findRegs(string expression, int numRegs); //DONE, VALIDATED KINDA; finds registers in order they appear
    string findReg(string expression, int stringI, int i); //DONE, VALIDATED KINDA; validates findRegs for $num < $num+10 case
    string intToString(string intString, int totalLen); //DONE, self explainitory 
    string intToString(int i, int totalLen); //DONE, self explainitory
    void setJumps();
    label setJumpsLH(string expression); //set jumps label helper
    void convertToHex(int argc, char* argv[]); //converts file to hex
    string binaryToHex(string binaryS); // converts a string to hex
    char getHexCharacter(string str); //gets single hex char
    string returnLabel(string expression); //DONE, KINDA
    
    //BEGIN MIPS COMMANDS
    void add(string expression, vector<string> & out); //DONE, VALIDATED KINDA
    void addi(string expression, vector<string> & out); //DONE, VALIDATED KINDA, 32 - 64 bit implemented
    void sub(string expression, vector<string> & out); //DONE, VALIDATED KINDA
    void mult(string expression, vector<string> & out); //DONE, VALIDATED KINDA
    void div(string expression, vector<string> & out); //DONE, VALIDATED KINDA
    void mfhi(string expression, vector<string> & out); //DONE, VALIDATED KINDA
    void mflo(string expression, vector<string> & out); //DONE, VALIDATED KINDA
    void sll(string expression, vector<string> & out); //DONE, VALIDATED KINDA
    void srl(string expression, vector<string> & out); //DONE, VALIDATED KINDA
    void lw(string expression, vector<string> & out); //DONE, VALIDATED KINDA
    void sw(string expression, vector<string> & out); //DONE, VALIDATED KINDA
    void slt(string expression, vector<string> & out); //DONE, VALIDATED KINDA
    void beq(string expression, vector<string> & out);
    void bne(string expression, vector<string> & out);
    void j(string expression, vector<string> & out);
    void jal(string expression, vector<string> & out);
    void jr(string expression, vector<string> & out); //DONE, VALIDATED KINDA
    void jalr(string expression, vector<string> & out); //DONE, VALIDATED KINDA
    void syscall(vector<string> & out); //DONE  
    //bonus mips
    void sgt(string expression, vector<string> & out);
    void sge(string expression, vector<string> & out);
    void sle(string expression, vector<string> & out);
    void seq(string expression, vector<string> & out);
    void sne(string expression, vector<string> & out);
    void move(string expression, vector<string> & out);
    void li(string expression, vector<string> & out);
    void bge(string expression, vector<string> & out);
    void bgt(string expression, vector<string> & out);
    void ble(string expression, vector<string> & out);
    void blt(string expression, vector<string> & out);
    void abs(string expression, vector<string> & out);
};
