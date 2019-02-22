#include <string>
#include <vector>
#include <unordered_map>
#ifndef AssemblerPass1_h
#define AssemblerPass1_h

using namespace std;

class AssemblerPass1 {

public:
    typedef struct ic {

        int lc;
        tuple<string, int> mnemonic;
        tuple<string, int> op1;
        tuple<string, int> op2;
    }ic;

    typedef struct tableRow {

        int index;
        int address;
        string symbolOrLiteral;
    }tableRow;

private:
    typedef struct MOTRow {

        int code{};
        int size{};
        int noOfOperands{};
        string type;
    }MOTRow;

    int lc, ptp, ltp, stp, rc, flagSTART;
    vector<string> tokensLine;

    unordered_map<string, MOTRow> mnemonicOpcodeTable;
    vector<tableRow> symbolTable;
    vector<tableRow> literalTable;
    vector<int> poolTable;
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
    int imperativeStatementsHandler(int, MOTRow);
    int declarativeStatementsHandler();
    const vector<ic> &getIntermediateCode() const;
    const vector<tableRow> &getSymbolTable() const;
    const vector<tableRow> &getLiteralTable() const;
};

#endif