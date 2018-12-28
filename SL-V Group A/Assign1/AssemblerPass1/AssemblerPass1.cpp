#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "AssemblerPass1.h"

using namespace std;

AssemblerPass1 :: AssemblerPass1() = default;

void AssemblerPass1 :: initializeMOT() {

    ifstream file;
    file.open("Mnemonics", ios::binary);
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

    if( !(mnemonics.find(tokensLine[1]) == mnemonics.end()) ) {

        MOTRow temp = mnemonics[tokensLine[1]];

        if(tokensLine.size() - 2 == temp.noOfOperands) {

            if(temp.noOfOperands == 1) {

                //TODO: Register or eq, lt, gt, ne etc.

            }
            else {

                //TODO: Constant, Literal, Symbol

            }

            return 1;
        }

        return 0;
    }

    return 0;
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

int AssemblerPass1::isLiteral(string) {
    return 0;
}

int AssemblerPass1::isConstant(string) {
    return 0;
}

int AssemblerPass1::isSymbol(string) {
    return 0;
}

int AssemblerPass1::isRegister(string) {
    return 0;
}

int AssemblerPass1::isConditionCode(string) {
    return 0;
}
