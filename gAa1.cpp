#include<bits/stdc++.h>
using namespace std;

class Tokenizer {
    
    private:
        vector< vector<string> > tokens;
        
    public:
        vector< vector<string> > generateTokens(string input);
        string readFile(string filename); 
        void display(vector< vector<string> >);
};

vector< vector<string> > Tokenizer :: generateTokens(string input) {

    int temp = 0;
    string intermediate;
    vector<string> tokensLine;
    
    string line = "GeeksForGeeks is a must try\nrdsgts"; 
            
    stringstream check1(line);  

    while(check1) {

        while(getline(check1, intermediate, ' ')) { 
            
            tokensLine.push_back(intermediate); 
        }

        tokens.push_back(tokensLine);
    }
    for(int j = 0; j < tokens.size(); j++)
    {   
        for(int i = 0; i < tokens[j].size(); i++) { 
         
            cout << tokens[j][i] << ' ';
        }
        cout <<'\n';
    }
    return tokens;  
}

string Tokenizer :: readFile(string filename) {

    return NULL;
}

int main() {

    Tokenizer tokenizer;
    tokenizer.generateTokens("LOL");

    return 0;
}