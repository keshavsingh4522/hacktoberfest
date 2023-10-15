#include <iostream>
using namespace std;

int main()
{
    int n; //stores the number whose multiplication table is required

    cout << "Enter number whose multiplication table you want: ";    //Taking user input
    cin >> n;
    cout<<"Multiplication table of " <<n<<" is:"<<endl;           
    for (int i = 1; i <= 10; i++) {                      //Login
        cout << n << " * " << i << " = " << n * i << endl;
    }
    return 0;
}
