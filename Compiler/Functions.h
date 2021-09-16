#include <string>
using namespace std;
class Converter {
    public:
    int regAddress(string reg);
    int add(string reg1, string reg2, string reg3);
    int addi(string reg1, string reg2, int val);
    int sub(string reg1, string reg2, string reg3);
}