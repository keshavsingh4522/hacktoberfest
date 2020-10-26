#include <bits/stdc++.h> 
  
using namespace std; 
// function to reverse digits of number
int reverseDigits(int num) 
{ 
    int rev_num = 0; 
    while(num > 0){ 
        rev_num = rev_num*10 + num%10; 
        num = num/10; 
    } 
    return rev_num; 
} 
  
// Driver program
int main() 
{ 
    int num;
    cin>>num; 
    cout << "Reverse of no. is "
         << reverseDigits(num); 
    
    return 0; 
} 