#include <bits/stdc++.h>
using namespace std;
 
void findNthRoot(double x, int n)
{
 
    // Initialize boundary values
    double low, high;
    if (x >= 0 and x <= 1)
    {
        low = x;
        high = 1;
    }
    else
    {
        low = 1;
        high = x;
    }
 
    // Used for taking precision
    double epsilon = 0.00000001;
 
    // Do binary search
    double guess = (low + high) / 2;
    while (abs((pow(guess, n)) - x) >= epsilon)
    {
        if (pow(guess, n) > x)
        {
            high = guess;
        }
        else
        {
            low = guess;
        }
        guess = (low + high) / 2;
    }
 
    cout << fixed << setprecision(16) << guess;
}

int main()
{
    double x = 5;
    int n = 2;
    findNthRoot(x, n);
}