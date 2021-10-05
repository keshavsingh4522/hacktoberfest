//Lokesh Gawande

// Check whether a number is perfectcube or not

// Approach find cuberoot and check if ceil of cuberoot is equal to floor of cube root if it is then it is perfect cube else not perfect

// TC   O(1)
// SC   O(1)

#include <bits/stdc++.h>
using namespace std;
bool Perfectcube(int x)
{
    float temp = pow(x, 1 / 3.0);
    return (ceil(temp) == floor(x)) ? true : false;
}

int main()
{
    int x;
    cin >> x;
    if (Perfectcube(x))
    {
        cout << "Perfectcube" << endl;
    }
    else
    {
        cout << "No perfectcube" << endl;
    }
    return 0;
}