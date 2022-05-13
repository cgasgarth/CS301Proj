#include <array>
#include <vector>
using namespace std;


struct RegLoc{ //register and the location of it
    string reg;
    int loc;
};
struct label{ //label and the line of it
    string name;
    int line;
};
class Converter {
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
    vector<label> labels; //used to keep track of labels for jumps
    string regAddress(string reg); //returns the address of a register
    vector<string> lineTakeIn(string expression, int line); //takes in a line and returns the binary representation
    string cleanString(string expression); //cleans the string of all whitespace
    array<RegLoc, 3> findRegs(string expression, int numRegs); //finds the registers in the expression
    string findReg(string expression, int stringI, int i); //finds the ith register in the expression
    string intToBinaryString(string intString, int totalLen); //converts an int to a binary string 
    string intToBinaryString(int i, int totalLen); //converts an int to a binary string
    void setJumps(); //sets the jumps in the temp file
    label setJumpsLH(string expression); //helps set setJumps() by finding the label
    void convertToHex(int argc, char* argv[]); //converts the temp file to the output file
    string binaryToHex(string binaryS); // converts a binary string to hex
    char getHexCharacter(string str); //gets single hex char
    string returnLabel(string expression); //returns the label of the line
    
    //BEGIN MIPS COMMANDS
    void add(string expression, vector<string> & out); //DONE, VALIDATED 
    void addi(string expression, vector<string> & out); //DONE, VALIDATED, 32 - 64 bit implemented
    void sub(string expression, vector<string> & out); //DONE, VALIDATED 
    void mult(string expression, vector<string> & out); //DONE, VALIDATED 
    void div(string expression, vector<string> & out); //DONE, VALIDATED 
    void mfhi(string expression, vector<string> & out); //DONE, VALIDATED 
    void mflo(string expression, vector<string> & out); //DONE, VALIDATED 
    void sll(string expression, vector<string> & out); //DONE, VALIDATED 
    void srl(string expression, vector<string> & out); //DONE, VALIDATED 
    void lw(string expression, vector<string> & out); //DONE, VALIDATED 
    void sw(string expression, vector<string> & out); //DONE, VALIDATED 
    void slt(string expression, vector<string> & out); //DONE, VALIDATED 
    void beq(string expression, vector<string> & out); //DONE, VALIDATED 
    void bne(string expression, vector<string> & out); //DONE, VALIDATED 
    void j(string expression, vector<string> & out); //DONE, VALIDATED  
    void jal(string expression, vector<string> & out); //DONE, VALIDATED 
    void jr(string expression, vector<string> & out); //DONE, VALIDATED 
    void jalr(string expression, vector<string> & out); //DONE, VALIDATED 
    void syscall(vector<string> & out); //DONE, VALIDATED
    void andC(string expression, vector<string> & out); //DONE, VALIDATED
    void orC(string expression, vector<string> & out); //DONE, VALIDATED
    void norC(string expression, vector<string> & out); //DONE, VALIDATED
    void xorC(string expression, vector<string> & out); //DONE, VALIDATED
    void andiC(string expression, vector<string> & out); //DONE, VALIDATED
    void oriC(string expression, vector<string> & out); //DONE, VALIDATED
    void xoriC(string expression, vector<string> & out); //DONE, VALIDATED
    //bonus mips
    void sgt(string expression, vector<string> & out, int line); //DONE, VALIDATED
    void sge(string expression, vector<string> & out, int line); //DONE, VALIDATED
    void sle(string expression, vector<string> & out, int line); //DONE, VALIDATED
    void seq(string expression, vector<string> & out, int line); //DONE, VALIDATED
    void sne(string expression, vector<string> & out, int line); //DONE, VALIDATED
    void move(string expression, vector<string> & out); //DONE, VALIDATED
    void li(string expression, vector<string> & out); //DONE, VALIDATED
    void bge(string expression, vector<string> & out, int line); //DONE, VALIDATED
    void bgt(string expression, vector<string> & out, int line); //DONE, VALIDATED
    void ble(string expression, vector<string> & out, int line); //DONE, VALIDATED
    void blt(string expression, vector<string> & out, int line); //DONE, VALIDATED
    void abs(string expression, vector<string> & out, int line); //DONE, VALIDATED
};