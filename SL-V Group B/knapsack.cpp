#include<bits/stdc++.h> 

using namespace std;

int max(int a, int b) { 
    
    return (a > b)? a : b; 
} 
  
int knapSack(int W, int weight[], int value[], int n) 
{ 
   int i, w; 
   int K[n+1][W+1]; 
  
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (weight[i-1] <= w) 
                 K[i][w] = max(value[i-1] + K[i-1][w-weight[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
  
   return K[n][W]; 
} 
  
int main() 
{
    int n;
    cin >> n;
    int value[n]; 
    int weight[n]; 

    for(int i = 0; i < n; i++) {

        cin >> value[i];
    } 

    for(int i = 0; i < n; i++) {

        cin >> weight[i];
    } 

    int  W = 50; 
    printf("%d", knapSack(W, weight, value, n)); 
    return 0; 
} 