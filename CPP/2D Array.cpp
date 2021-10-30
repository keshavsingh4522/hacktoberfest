#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    int Cnt[2][3];

    int i = 0 , j = 0;

    for(i = 0 ; i < 2 ; i++)
    {
        for(j = 0 ; j < 3 ; j++)
        {
            cout << "\n Enter Value for Cnt %d %d = > ";
            cin >> Cnt[i][j];
        }
    }

    cout << "\n Two Dimensional Array Element are : " << endl;

    for(i = 0 ; i < 2 ; i++)
    {
        for(j = 0 ; j < 3 ; j++)
        {
            cout << "\t\t" <<Cnt[i][j] << endl;
        }
    }

    getch();
    return 0;
}
