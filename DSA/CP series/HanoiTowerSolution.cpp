#include <iostream>
using namespace std;

int cnt=0;
void toh(int n, char a, char b, char c){
    if(n==1){
        cout << "Move disk " << n << " from " << a << " to " << c << endl;
        cnt++;
    }
    else{
        toh(n-1, a, c, b);
        cout << "Move disk " << n << " from " << a << " to " << c << endl;
        cnt++;
        toh(n-1, b, a, c);
    }
}

int main(){
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    toh(n, 'A', 'B', 'C');
    cout << "Total number of moves: " << cnt << endl;
    return 0;
}