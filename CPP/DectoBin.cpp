#include <iostream>
using namespace std;

void DectoBin(int n)
{
    int binarynum[100], i = 0;
    while (n > 0)
    {
        binarynum[i] = n % 2;
        n = n / 2;
        i++;
    }
    cout << "Binary form is: ";

    for (int j = i - 1; j >= 0; j--)
        cout << binarynum[j];
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter the Decimal number: " << endl;
    cin >> n;
    DectoBin(n);
}