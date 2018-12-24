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

    vector<string> tokensLine;
    unordered_map<string, MOTRow> mnemonics;

public:
    void assemblerPass1Driver(char*);
    AssemblerPass1();
    void generateTokens(const string &input);
    int pass1(char *filename);
    void initializeMOT();
    int validInput();
};