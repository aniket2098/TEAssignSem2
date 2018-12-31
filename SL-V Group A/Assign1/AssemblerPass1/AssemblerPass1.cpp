#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "AssemblerPass1.h"

using namespace std;

AssemblerPass1 :: AssemblerPass1() {

    lc = -1;
    ptp = 1;
    ltp = 1;
    stp = 1;
    rc = 0;
    conditionCodes = {"eq", "ne", "gt", "lt", "gte", "lte"};
    registers = {"AREG", "BREG", "CREG", "DREG"};

}

void AssemblerPass1 :: initializeMOT() {

    ifstream file;
    file.open("AssemblerPass1/Mnemonics", ios::binary);
    string tempMnemonic;
    MOTRow tempMOT;

    while (!file.eof())
    {

        file >> tempMnemonic;
        file >> tempMOT.code;
        file >> tempMOT.size;
        file >> tempMOT.noOfOperands;
        file >> tempMOT.type;
        mnemonics[tempMnemonic] = tempMOT;
    }

    file.close();
}

void AssemblerPass1 :: generateTokens(string const &input) {

    string intermediate;
    stringstream check1(input);  

    while(getline(check1, intermediate, ' ')) {

        tokensLine.push_back(intermediate);
    }
}

int AssemblerPass1 :: validInput() {

    //TODO: Remove similar blocks of code
    if( !(mnemonics.find(tokensLine[0]) == mnemonics.end()) ) {

        MOTRow temp = mnemonics[tokensLine[0]];

        if(tokensLine.size() - 1 == temp.noOfOperands) {

            if(temp.noOfOperands == 1) {

                if(isLiteral(tokensLine[1])) {

                }

                else if(isConstant(tokensLine[1])) {

                }

                else if(isSymbol(tokensLine[1])) {

                }

                return 0;

            }
            else {

                if(isConditionCode(tokensLine[1])) {

                }
                else if(isRegister(tokensLine[1])) {

                }

                else {

                    return 0;
                }

                if(isLiteral(tokensLine[2])) {

                }

                else if(isConstant(tokensLine[2])) {

                }

                else if(isSymbol(tokensLine[2])) {


                }

                return 0;
            }

        }

        return 0;
    }
    else  {

        MOTRow temp = mnemonics[tokensLine[1]];
        SymbolTableRow temp1;

        if((symbolTable.find(tokensLine[0]) == symbolTable.end())) {

            temp1.index = stp ++;
            temp1.address = lc;

            symbolTable[tokensLine[0]] = temp1;
        }

        if( !(mnemonics.find(tokensLine[1]) == mnemonics.end()) ) {

            if (tokensLine.size() - 2 == temp.noOfOperands) {

                if (temp.noOfOperands == 1) {

                    if(isLiteral(tokensLine[2])) {

                    }

                    else if(isConstant(tokensLine[2])) {

                    }

                    else if(isSymbol(tokensLine[2])) {


                    }


                } else {

                    if(isConditionCode(tokensLine[2])) {

                    }
                    else if(isRegister(tokensLine[2])) {

                    }

                    if(isLiteral(tokensLine[3])) {

                    }

                    else if(isConstant(tokensLine[3])) {

                    }

                    else if(isSymbol(tokensLine[3])) {


                    }

                }

                return 1;
            }

            return 0;
        }

        return 0;
    }

}

int AssemblerPass1 :: pass1(char *filename) {

    string temp;
    ifstream file;
    file.open(filename, ios::in);

    while(!file.eof()) {

        getline(file, temp);
        generateTokens(temp);

        if( validInput() ) {


        }

        else {

            cout<<"\n!!!ERROR!!!\n";
            return 1;
        }
        tokensLine.clear();
    }

    file.close();

    return 0;
}

void AssemblerPass1::assemblerPass1Driver(char* filename) {

    initializeMOT();
    pass1(filename);
}

int AssemblerPass1::isLiteral(string literal) {

    if(literal[0] == '=') {

        literal.erase(0);

        for(auto const &i : literal) {

            if(i < '0' || i > '9') {

                return 0;
            }
        }

        return 1;
    }

    return 0;
}

int AssemblerPass1::isConstant(string constant) {

    for(auto const &i : constant) {

        if(i < '0' || i > '9') {

            return 0;
        }

    }

    return 1;
}

int AssemblerPass1::isSymbol(string) {

    return 0;
}

int AssemblerPass1::isRegister(string reg) {

    for(auto const &i : registers ) {

        if(reg == i) {

            return 1;
        }
    }

    return 0;
}

int AssemblerPass1::isConditionCode(string conditionCode) {


    for(auto const &i : conditionCodes ) {

        if(conditionCode == i) {

            return 1;
        }
    }
    return 0;
}
