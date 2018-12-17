#include<bits/stdc++.h>
using namespace std;

class Tokenizer {
    
    private:
        vector<string> tokens;
    public:
        vector<string> generateTokens(string input);
        string readFile(string filename); 
};

vector<string> Tokenizer :: generateTokens(string input) {

      
    string line = "GeeksForGeeks is a must try"; 
      
    vector<string> tokens; 
      
    stringstream check1(line); 
      
    string intermediate; 
      
    while(getline(check1, intermediate, ' ')) 
    { 
        tokens.push_back(intermediate); 
    } 
      
    for(int i = 0; i < tokens.size(); i++) 
        cout << tokens[i] << '\n';  
}

string Tokenizer :: readFile(string filename) {


}

int main() {

    Tokenizer tokenizer;
    tokenizer.generateTokens("LOL");

    return 0;
}