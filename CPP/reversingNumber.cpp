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
    int sign = (num>=0?1:-1);
    cout << "Reverse of no. is "
         << (sign*reverseDigits(abs(num))); 
    
    return 0; 
} 