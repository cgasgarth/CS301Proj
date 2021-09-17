#include <string>
using namespace std;
class Converter { //648 or A-51 in book
    public:
    string regAddress(string reg); //DONE, NEEDS VALIDATION
    string lineTakeIn(string expression);
    string lineTakeIn(string expression, int offset);
    string add(string reg1, string reg2, string reg3); //DONE, NEEDS VALIDATION
    string addi(string reg1, string reg2, int val);
    string sub(string reg1, string reg2, string reg3);
    string mult(string reg1, string reg2); // multiply these two num, store in hi and low regs
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