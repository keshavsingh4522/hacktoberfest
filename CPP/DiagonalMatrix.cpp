#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 100;

void printPrincipalDiagonal(int mat[][MAX], int n)
{
    cout << "Principal Diagonal: ";
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i == j)
                cout << mat[i][j] << ", ";
        }
    }
    cout << endl;
}

void printSecondaryDiagonal(int mat[][MAX], int n)
{
    cout << "Secondary Diagonal: ";
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if ((i + j) == (n - 1))
                cout << mat[i][j] << ", ";
        }
    }
    cout << endl;
}

int main()
{
    int n = 4;
    int a[][MAX] = { { 1, 2, 3, 4 },
                     { 5, 6, 7, 8 },
                     { 1, 2, 3, 4 },
                     { 5, 6, 7, 8 } };
 
    printPrincipalDiagonal(a, n);
    printSecondaryDiagonal(a, n);
    return 0;
}