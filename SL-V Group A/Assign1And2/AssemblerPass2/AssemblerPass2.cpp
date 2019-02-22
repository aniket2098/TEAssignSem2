#include <utility>
#include <fstream>
#include <iostream>
#include "AssemblerPass2.h"

using namespace std;

AssemblerPass2::AssemblerPass2(AssemblerPass1 assemblerPass1) {

    this->assemblerPass1 = assemblerPass1;
    intermediateCode = assemblerPass1.getIntermediateCode();
    symbolTable = assemblerPass1.getSymbolTable();
    literalTable = assemblerPass1.getLiteralTable();
}

void AssemblerPass2::assemblerPass2Driver() {

    ofstream outFile;

    outFile.open("Output", ios :: out);

    for(auto &i : intermediateCode) {

        if(get<0>(i.mnemonic) == "IS") {

            outFile << i.lc << "\t" << get<1>(i.mnemonic) << "\t" << get<1>(i.op1) << "\t";

            if(get<0>(i.op2) == "C") {

               outFile << get<1>(i.op2) << endl;
            } else if(get<0>(i.op2) == "S") {

                outFile << symbolTable[get<1>(i.op2)].address << endl;
            } else if(get<0>(i.op2) == "L") {

                outFile << literalTable[get<1>(i.op2)].address << endl;
            } else {

                outFile << "-1" << endl;
            }
        }
    }

    outFile.close();
}