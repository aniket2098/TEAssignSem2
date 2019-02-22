#include<bits/stdc++.h>

#define MAX 100

using namespace std;
  
int memoizationTable[MAX]; 
  
void init() 
{ 
  int i; 
  for (i = 0; i < MAX; i++) 
    memoizationTable[i] = -1; 
} 
  
int fibonacci(int n) 
{ 
   if (memoizationTable[n] == -1) 
   { 
      if (n <= 1) 
         memoizationTable[n] = n; 
      else
         memoizationTable[n] = fibonacci(n-1) + fibonacci(n-2); 
   } 
  
   return memoizationTable[n]; 
} 
  
int main () 
{ 
    int n;
    cout << "Enter a no. :: ";
    cin >> n; 
    init(); 
    cout << n << "th Fibonacci number is " << fibonacci(n) << endl; 
    return 0; 
}