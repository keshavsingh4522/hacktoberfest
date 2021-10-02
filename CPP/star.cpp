#include <iostream>
using namespace std;

void patern(int y);

int main()
{
    int x;
    cout << "Enter a number : ";
    cin >> x;
    patern(x);
    return 0;
}

void patern(int x)
{
    for(int i=0;i<=x;i++){
        for(int j=0;j<i;j++){
            cout << "*" << " ";
        }
        cout << endl;
    }
}
