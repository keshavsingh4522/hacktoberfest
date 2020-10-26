#include<bits/stdc++.h> 
using namespace std; 
  
// Function to find if n reaches to 1 or not. 
bool isToOneRec(int n, unordered_set<int> &s) 
{ 
    if (n == 1) 
        return true; 
  
    // If there is a cycle formed, we can't r 
    // reach 1. 
    if (s.find(n) != s.end()) 
        return false; 
  
    // If n is odd then pass n = 3n+1 else n = n/2 
    return (n % 2)? isToOneRec(3*n + 1, s) : 
                    isToOneRec(n/2, s); 
} 
  
// Wrapper over isToOneRec() 
bool isToOne(int n) 
{ 
   // To store numbers visited using recursive calls. 
   unordered_set<int> s; 
  
   return isToOneRec(n, s); 
} 
  
// Drivers code 
int main() 
{ 
    int n = 5; 
    isToOne(n) ? cout << "Yes" : cout <<"No"; 
    return 0; 
} 
