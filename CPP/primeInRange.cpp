#include<iostream>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    for (int range = a; range <= b; range++){
        int counter = 0;
        if (range == 1){
            cout << range<<"\n";
        }
        else{
            for (int factor = 1; factor <= range; factor++){
                if (range % factor == 0){
                    counter++;
                }
            }
            if (counter == 2){
                cout<< range<<"\n";
            }
        }
    }
    return 0;
}
