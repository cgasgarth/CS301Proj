#include <string>
using namespace std;
class Converter { //648 or A-51 in book
    public:
    string regAddress(string reg);
    string add(string reg1, string reg2, string reg3);
    string addi(string reg1, string reg2, int val);
    string sub(string reg1, string reg2, string reg3);
};