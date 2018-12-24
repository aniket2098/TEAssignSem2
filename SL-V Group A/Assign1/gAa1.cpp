#include<bits/stdc++.h>
using namespace std;

typedef struct MOT {

    int code;
    int size;
    int noOfOperands;
    string type;
}MOT;

class Assembler {

    vector<string> tokensLine;
    unordered_map<string, MOT> mnemonics;

    public:
        void generateTokens(string input);
        void readFile(char* filename); 
        void display(vector<string>);
        void initializeTable();
        int validInput();
};

void Assembler :: initializeTable() {

    ifstream file;
    file.open("Mnemonics", ios::binary);
    string tempMnemonic;
    MOT tempMOT;
    file>>tempMnemonic;
    file>>tempMOT.code;
    file>>tempMOT.size;
    file>>tempMOT.noOfOperands;
    file>>tempMOT.type;
    mnemonics[tempMnemonic] = tempMOT;
}

void Assembler :: generateTokens(string input) {

    int temp = 0;
    string intermediate;
    vector<string> tokensLine;
             
    stringstream check1(input);  

  
    while(getline(check1, intermediate, ' ')) { 

        tokensLine.push_back(intermediate);
    }

}

int Assembler :: validInput() {

    // if(mnemonics[tokensLine[0]] ) {
        MOT temp;

        temp = mnemonics[tokensLine[1]];
          cout<<temp.type;
    // }
    return 0;
}

void Assembler :: readFile(char* filename) {

    string temp;
    ifstream file;
    
    file.open(filename, ios::in);
    while(!file.eof()) {

        getline(file, temp);
        cout<<temp;
        generateTokens(temp);
        cout<<tokensLine[0];
        // validInput();
    }

    file.close();
}

void Assembler :: display(vector<string> tokensLine) {

    for(int i = 0; i < tokensLine.size(); i++) { 
         
        cout << tokensLine[i] << ' ';
    }
    cout<<"\n";
}

int main() {

    
    Assembler assembler;
    assembler.readFile("input.asm");
    assembler.initializeTable();
    return 0;
}