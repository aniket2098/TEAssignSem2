#include "../AssemblerPass1/AssemblerPass1.h"

class AssemblerPass2 {

    AssemblerPass1 assemblerPass1;
    vector<AssemblerPass1 :: ic> intermediateCode;
    vector<AssemblerPass1 :: tableRow> symbolTable;
    vector<AssemblerPass1 :: tableRow> literalTable;

public:

    AssemblerPass2(AssemblerPass1);
    void assemblerPass2Driver();
};