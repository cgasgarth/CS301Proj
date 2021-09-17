#include <string>
#include <array>
using namespace std;


struct RegLoc{
    string reg;
    int loc;
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
    string regAddress(string reg); //DONE, NEEDS VALIDATION
    string lineTakeIn(string expression);
    string lineTakeIn(string expression, int offset);
    array<RegLoc, 3> findRegs(string expression, int numRegs); //DONE, NEEDS VALIDATION
    string findReg(string expression, int stringI, int i); //DONE, VALIDATED KINDA
    
    //BEGIN MIPS COMMANDS
    string add(string reg1, string reg2, string reg3); //DONE, NEEDS VALIDATION
    string addi(string reg1, string reg2, int val);
    string sub(string reg1, string reg2, string reg3);
    string mult(string reg1, string reg2);
    string div(string reg1, string reg2);
    string mfhi(string reg1);
    string mflo(string reg1);
    string sll(string reg1, string reg2, int shift);
    string srl(string reg1, string reg2, int shift);
    string lw(string reg1, string reg2, int offset);
    string sw(string reg1, string reg2, int offset);
    string slt(string reg1, string reg2, string reg3);
    string beq(string reg1, string reg2, int offset);
    string bne(string reg1, string reg2, int offset);
    string j(string label);
    string jal(string label);
    string jr(string reg);
    string jalr(string reg1, string reg2);
    string syscall();    
};
