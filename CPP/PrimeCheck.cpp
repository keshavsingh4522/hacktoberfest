/* 
------------------------------------------------------------------------------------------------
USERNAME: RASESH2005
DESCRIPTION: THIS PROGRAM CHECKS IF A NUMBER IS PRIME OR NOT
DATE: 1/10/2021
------------------------------------------------------------------------------------------------
*/
#include <bits/stdc++.h>

using namespace std;

//SNIPPET
bool isPrime(int n)
{
    for (int i = 2; i <= int(sqrt(n) + 1); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int num;
    //APPLICATION
    cout<<"Enter a number: ";
    cin>>num;
    
    if(!(int)num)
    {
        cout<<"Enter a number not a stringer or decimal.";
        exit(1);
    }
    bool result = isPrime(num);
    cout << result << endl;
    cout << (result ? "Prime" : "Not A Prime") << endl;
    return 0;
}
