#include<bits/stdc++.h>
using namespace std;

class Tokenizer {
    
    public:
        vector<string> generateTokens(string input);
        void readFile(char* filename); 
        void display(vector<string>);
};
//TODO: Pass the delimiter as well to generateTokens
vector<string> Tokenizer :: generateTokens(string input) {

    int temp = 0;
    string intermediate;
    vector<string> tokensLine;
             
    stringstream check1(input);  

  
    while(getline(check1, intermediate, ' ')) { 
        tokensLine.push_back(intermediate); 
    }

    return tokensLine;
}

void Tokenizer :: readFile(char* filename) {

    string temp;
    ifstream file;
    
    file.open(filename, ios::in);
    while(!file.eof()) {

        getline(file, temp);
        display(generateTokens(temp));
    }

    file.close();
}

void Tokenizer :: display(vector<string> tokensLine) {

    for(int i = 0; i < tokensLine.size(); i++) { 
         
        cout << tokensLine[i] << ' ';
    }
    cout<<"\n";
}

int main() {

    Tokenizer tokenizer;
    tokenizer.readFile("test.txt");

    return 0;
}