#include <bits/stdc++.h> 

using namespace std; 
  
bool** table; 
  
void display(const vector<int>& v) 
{ 
    for (int i = 0; i < v.size(); ++i) 
        printf("%d ", v[i]); 
    printf("\n"); 
}

void printResult(int input[], int i, int sum, vector<int>& p) 
{ 
    if (i == 0 && sum != 0 && table[0][sum]) 
    { 
        p.push_back(input[i]); 
        display(p); 
        return; 
    } 
  
    if (i == 0 && sum == 0) 
    { 
        display(p); 
        return; 
    } 
  
    if (table[i-1][sum]) 
    { 
        vector<int> b = p; 
        printResult(input, i-1, sum, b); 
    } 
  
    if (sum >= input[i] && table[i-1][sum-input[i]]) 
    { 
        p.push_back(input[i]); 
        printResult(input, i-1, sum-input[i], p); 
    } 
} 
  
void printAllSubsets(int input[], int n, int sum) 
{ 
    if (n == 0 || sum < 0) 
       return; 
  
    table = new bool*[n]; 
    for (int i=0; i<n; ++i) 
    { 
        table[i] = new bool[sum + 1]; 
        table[i][0] = true; 
    } 
  
    if (input[0] <= sum) 
       table[0][input[0]] = true; 
  
    for (int i = 1; i < n; ++i) 
        for (int j = 0; j < sum + 1; ++j) 
            table[i][j] = (input[i] <= j) ? table[i-1][j] || 
                                       table[i-1][j-input[i]] 
                                     : table[i - 1][j]; 
    if (table[n-1][sum] == false) 
    { 
        printf("There are no subsets with sum %d\n", sum); 
        return; 
    } 
  
    vector<int> p; 
    printResult(input, n-1, sum, p); 
} 
  
int main() 
{ 
    int n, sum;
    cin >> n;
    int input[n];
    for(int i = 0; i < n; i++) {

        cin >> input[i];
    }
    cin >> sum;
    printAllSubsets(input, n, sum); 
    return 0; 
}