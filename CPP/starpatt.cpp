//star pattern in c++

#include<iostream>
using namespace std;
int main()
{
int n, s, i, j;
cout << "Enter number of rows: ";
cin >> n;
for(i = n; i >= 1; i--)
{
//for loop to put space
for(s = i; s < n; s++)
cout << " ";
//for loop for displaying star
for(j = 1; j <= (2 * i - 1); j++)
cout << "* ";
// ending line after each row
cout << "\n";
}
return 0;
}
