#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class AssemblerPass1 {

private:
    typedef struct MOTRow {

        int code{};
        int size{};
        int noOfOperands{};
        string type;
    }MOTRow;

    typedef struct tableRow {

        int index;
        int address;
    }SymbolTableRow;

    typedef struct ic {

        int lc;
        tuple<string, int> mnemonic;
        tuple<string, int> op1;
        tuple<string, int> op2;
    }ic;

    int lc, ptp, ltp, stp, rc, flagSTART;
    vector<string> tokensLine;

    unordered_map<string, MOTRow> mnemonicOpcodeTable;
    unordered_map<string, tableRow> symbolTable;
    unordered_map<string, tableRow> literalTable;
    vector<string> conditionCodes;
    vector<string> registers;
    vector<ic> intermediateCode;

public:
    void assemblerPass1Driver(char*);
    AssemblerPass1();
    void generateTokens(const string &input);
    int pass1(char *filename);
    void initializeMOT();
    int validateInputAndGenerateIC();
    int isLiteral(string);
    int isConstant(string);
    int isSymbol(string);
    int isRegister(string);
    int isConditionCode(string);
    int assemblerDirectiveHandler(int);
};