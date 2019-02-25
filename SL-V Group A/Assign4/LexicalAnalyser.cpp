#include <bits/stdc++.h>
#include "LexicalAnalyser.h"

using namespace std;

LexicalAnalyser :: LexicalAnalyser() {

}

void LexicalAnalyser :: input() {
    
    ifstream file;
    char* filename = "input.txt";
    file.open(filename, ios::in);
    while (!file.eof()) {
    
       getline(file, line);
       generateAndStoreTokens();
    }
}

void LexicalAnalyser :: generateAndStoreTokens() {

    int l = line.length();
    
    string token = "";
    vector<char> :: iterator it;
    for(int i = 0; i <= l; i++) {
        
        char temp = line[i];

        if(isalnum(temp) || temp == '_') {
            token += temp;
        } else if(temp > 32 && temp < 127) {
            
            token += temp;
            it = find (binaryOperators.begin(), binaryOperators.end(), temp); 
            if(it != binaryOperators.end()) {

                if(line[i + 1] == temp) {
                    token += temp;
                    i++; 
                }
            }
            cout << token << endl;
            token = "";
        } else {

            cout << token << endl;
            token = "";
        }
    }
}

int main() {

    LexicalAnalyser lexicalAnalyser;
    lexicalAnalyser.input();
    lexicalAnalyser.generateAndStoreTokens();
    return 0;
}