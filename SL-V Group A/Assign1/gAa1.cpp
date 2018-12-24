#include<bits/stdc++.h>
using namespace std;



class Assembler {

    typedef struct MOT {

        int code;
        int size;
        int noOfOperands;
        string type;
    }MOT;

    vector<string> tokensLine;
    unordered_map<string, MOT> mnemonics;

    public:
        Assembler();
        void generateTokens(string input);
        int pass1(char *filename);
        void initializeTable();
        int validInput();
};

Assembler ::Assembler() {


}

void Assembler :: initializeTable() {

    ifstream file;
    file.open("Mnemonics", ios::binary);
    string tempMnemonic;
    MOT tempMOT;

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

void Assembler :: generateTokens(string const input) {

    string intermediate;
    stringstream check1(input);  

    while(getline(check1, intermediate, ' ')) {

        tokensLine.push_back(intermediate);
    }
}

int Assembler :: validInput() {

    if(mnemonics.find(tokensLine[1]) == mnemonics.end()) {

        MOT temp = mnemonics[tokensLine[1]];

        if(tokensLine.size() - 2 == temp.noOfOperands) {


            return 1;
        }

        return 0;
    }

    return 0;
}

int Assembler :: pass1(char *filename) {

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

int main() {

    char* file = "input.txt";
    Assembler assembler;
    assembler.initializeTable();
    assembler.pass1(file);

    return 0;
}