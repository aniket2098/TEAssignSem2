#include<bits/stdc++.h>

using namespace std;

class LexicalAnalyser {

string *keywords;
string line;
vector<char> binaryOperators {'+', '-', '=', '>', '<', ':', '/'};

public:
    LexicalAnalyser();
    void input();
    void generateAndStoreTokens();
};