#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <tuple>
#include "AssemblerPass1.h"

using namespace std;

AssemblerPass1::AssemblerPass1() {

    lc = 0;
    ptp = 0;
    ltp = 0;
    stp = 0;
    rc = 0;
    flagSTART = 0;
    conditionCodes = {"EQ", "NE", "GT", "LE", "LT", "GTE", "LTE"};
    registers = {"AREG", "BREG", "CREG", "DREG"};
}

void AssemblerPass1::assemblerPass1Driver(char *filename) {

    initializeMOT();

    if(!pass1(filename)) {

        cout << endl << "Intermediate Code\n\n";

        for (auto &i : intermediateCode) {

            cout << i.lc << "\t(" << get<0>(i.mnemonic) << "," << get<1>(i.mnemonic) << ")\t(" << get<0>(i.op1) << ","
                 << get<1>(i.op1) << ")\t(" << get<0>(i.op2) << "," << get<1>(i.op2) << ")\n";
        }

        cout << endl << "Symbol Table\n\n";

        for (auto &i : symbolTable) {

            cout << i.index << "\t" << i.symbolOrLiteral << "\t" << i.address << endl;
        }

        cout << endl << "Literal Table\n\n";

        for (auto &i : literalTable) {

            cout << i.index << "\t" << i.symbolOrLiteral << "\t" << i.address << endl;
        }

        cout << endl << "Pool Table\n\n";

        for (auto &i : poolTable) {

            cout << i << endl;
        }

        cout << endl;
    }
}

void AssemblerPass1::initializeMOT() {

    ifstream file;
    file.open("Utils/Mnemonics", ios::binary);
    string tempMnemonic;
    MOTRow tempMOT;

    while (!file.eof()) {

        file >> tempMnemonic;
        file >> tempMOT.code;
        file >> tempMOT.size;
        file >> tempMOT.noOfOperands;
        file >> tempMOT.type;
        mnemonicOpcodeTable[tempMnemonic] = tempMOT;
    }

    file.close();
}

int AssemblerPass1::pass1(char *filename) {

    string temp;
    ifstream file;
    filename = "input.txt";
    file.open(filename, ios::in);
    int returnValue;
    ic icTemp;
    icTemp.lc = -1;
    icTemp.mnemonic = make_tuple('-', -1);
    icTemp.op1 = make_tuple('-', -1);
    icTemp.op2 = make_tuple('-', -1);

    while (!file.eof()) {

        getline(file, temp);
        generateTokens(temp);

        intermediateCode.push_back(icTemp);

        if ((returnValue = validateInputAndGenerateIC())) {

            if (returnValue == 4) {

                file.close();
                return 0;
            }
        } else {

            file.close();
            cout << "\n!!!ERROR!!!\n";
            return 1;
        }
        tokensLine.clear();
    }

    file.close();

    return 0;
}

void AssemblerPass1::generateTokens(string const &input) {

    string intermediate;
    stringstream check1(input);

    while (getline(check1, intermediate, ' ')) {

        tokensLine.push_back(intermediate);
    }
}

int AssemblerPass1::validateInputAndGenerateIC() {

    int base = 0;

    if ((mnemonicOpcodeTable.find(tokensLine[0]) == mnemonicOpcodeTable.end())) {

        base = 1;
        int temp;
        tableRow temp1{};
        temp = isSymbol(tokensLine[0]);
        if (temp < 0) {

            temp1.index = stp++;
            temp1.symbolOrLiteral = tokensLine[0];
            symbolTable.push_back(temp1);
        }
//        else if (symbolTable[temp - 1].address != -1) {
//cout<<"Finally";
//            return 0;
//        }

        symbolTable[symbolTable.size() - 1].address = lc;
    }

    MOTRow temp = mnemonicOpcodeTable[tokensLine[base]];
    intermediateCode[intermediateCode.size() - 1].mnemonic = make_tuple(temp.type, temp.code);

    if (temp.type == "AD") {

        return assemblerDirectiveHandler(base);
    }

    intermediateCode[intermediateCode.size() - 1].lc = lc;
    lc = lc + temp.size;

    if (temp.type == "IS") {

        return imperativeStatementsHandler(base, temp);
    }

    if (temp.type == "DL") {

        return declarativeStatementsHandler();
    }
    return 0;
}

int AssemblerPass1::assemblerDirectiveHandler(int base) {

    if (tokensLine[base] == "START" && !flagSTART) {

        if (isConstant(tokensLine[base + 1])) {

            intermediateCode[intermediateCode.size() - 1].lc = lc;
            lc = stoi(tokensLine[base + 1]);
            flagSTART = 1;
            return 1;
        }
        return 0;
    } else if (tokensLine[base] == "LTORG" || tokensLine[base] == "END") {

        intermediateCode[intermediateCode.size() - 1].lc = lc;
        for (int i = ptp; i < literalTable.size(); i++) {

            literalTable[i].address = lc;
            lc++;
        }

        poolTable.push_back(ptp);
        ptp = ltp;
        if(tokensLine[base] == "END")
            return 4;
        return 2;
    } else if (tokensLine[base] == "EQU") {

        int tempIndex = isSymbol(tokensLine[0]);
        intermediateCode[intermediateCode.size() - 1].lc = lc;

        return 3;
    } else if (tokensLine[base] == "ORIGIN") {
        if (isConstant(tokensLine[base + 1])) {
            intermediateCode[intermediateCode.size() - 1].lc = lc;

            lc = stoi(tokensLine[base + 1]);
            return 5;
        }
        return 0;
    }

    return 0;
}

int AssemblerPass1::imperativeStatementsHandler(int base, MOTRow temp) {


    if (tokensLine.size() - 1 - base == temp.noOfOperands) {

        if (temp.noOfOperands == 1) {

            if (isLiteral(tokensLine[1 + base])) {

                return 1;
            } else if (isConstant(tokensLine[1 + base])) {

                return 1;
            } else {

                int tempIndex = isSymbol(tokensLine[1 + base]);
                if (tempIndex >= 0) {

                    intermediateCode[intermediateCode.size() - 1].op2 = make_tuple("S", tempIndex);
                    return 1;
                }
                tableRow temp1{};
                temp1.index = stp++;
                temp1.symbolOrLiteral = tokensLine[1 + base];
                temp1.address = -1;
                symbolTable.push_back(temp1);
                intermediateCode[intermediateCode.size() - 1].op2 = make_tuple("S", temp1.index);
                return 1;
            }

        } else if(temp.noOfOperands == 2){

            if (isConditionCode(tokensLine[1 + base])) {}

            else if (isRegister(tokensLine[1 + base])) {}

            else {

                return 0;
            }

            if (isLiteral(tokensLine[2 + base])) {

                return 1;
            } else if (isConstant(tokensLine[2 + base])) {

                return 1;
            } else {
                int tempIndex = isSymbol(tokensLine[2 + base]);
                if (tempIndex >= 0) {

                    intermediateCode[intermediateCode.size() - 1].op2 = make_tuple("S", tempIndex);
                    return 1;
                }

                tableRow temp1{};
                temp1.index = stp++;
                temp1.symbolOrLiteral = tokensLine[2 + base];
                temp1.address = -1;
                symbolTable.push_back(temp1);
                intermediateCode[intermediateCode.size() - 1].op2 = make_tuple("S", temp1.index);
                return 1;
            }
        } else if(temp.noOfOperands == 0) {

            return 1;
        }

    }
}

int AssemblerPass1::declarativeStatementsHandler() {

    if(tokensLine[1] == "DS") {

        int tempIndex = isSymbol(tokensLine[0]);
        if(tempIndex >= 0) {

            symbolTable[tempIndex].address = lc;
            lc += stoi(tokensLine[2]);
            return 1;
        }
    }
    if(tokensLine[1] == "DC") {

        if(isConstant(tokensLine[2])) {

            int tempIndex = isSymbol(tokensLine[0]);
            if(tempIndex >= 0) {

                symbolTable[tempIndex].address = lc;
                lc++;
                return 1;
            }
        }
    }
    return 0;
}

int AssemblerPass1::isLiteral(string literal) {

    string temp = literal;
    for (int i = ptp; i < literalTable.size(); i++) {

        if (literalTable[i].symbolOrLiteral == literal) {

            intermediateCode[intermediateCode.size() - 1].op2 = make_tuple("L", i);
            return 1;
        }
    }

    if (temp[0] == '=') {

        temp.erase(0);

        for (auto const &i : temp) {

            if (i < '0' || i > '9') {

                return 0;
            }
        }

        tableRow temp1{};

        temp1.index = ltp++;
        temp1.address = -1;
        temp1.symbolOrLiteral = literal;

        literalTable.push_back(temp1);

        intermediateCode[intermediateCode.size() - 1].op2 = make_tuple("L", temp1.index);

        return 1;
    }
    return 0;
}

int AssemblerPass1::isConstant(string constant) {

    for (auto const &i : constant) {

        if (i < '0' || i > '9') {

            return 0;
        }

    }

    intermediateCode[intermediateCode.size() - 1].op2 = make_tuple("C", stoi(constant));

    return 1;
}

int AssemblerPass1::isSymbol(string symbol) {

    for (auto const &i : symbolTable) {

        if (symbol == i.symbolOrLiteral) {

            return i.index;
        }
    }
    return -1;
}

int AssemblerPass1::isRegister(string reg) {

    for (int i = 0; i < registers.size(); i++) {

        if (reg == registers[i]) {

            intermediateCode[intermediateCode.size() - 1].op1 = make_tuple("R", i);

            return 1;
        }
    }

    return 0;
}

int AssemblerPass1::isConditionCode(string conditionCode) {


    for (int i = 0; i < conditionCodes.size(); i++) {

        if (conditionCode == conditionCodes[i]) {

            intermediateCode[intermediateCode.size() - 1].op1 = make_tuple("CC", i);

            return 1;
        }
    }
    return 0;
}

const vector<AssemblerPass1::ic> &AssemblerPass1::getIntermediateCode() const {

    return intermediateCode;
}

const vector<AssemblerPass1::tableRow> &AssemblerPass1::getSymbolTable() const {
    return symbolTable;
}

const vector<AssemblerPass1::tableRow> &AssemblerPass1::getLiteralTable() const {
    return literalTable;
}

