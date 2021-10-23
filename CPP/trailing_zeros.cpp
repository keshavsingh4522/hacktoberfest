/*
Author : Aditya Choubey

Problem Statement :
The program's task is to calculate the number of trailing zeros in the factorial n!.
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    unsigned long long int n;
    cin >> n;
    unsigned long long int countFives = 0;
    for (int i = 5; n / i >= 1; i *= 5)
        countFives += n / i;
    cout << countFives << endl;
}

