#include<iostream>
using namespace std;
int main(){
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    int *array = new int[size];
    cout << "Enter the elements of the array: " << endl;
    for(int i = 0; i < size; i++){
        cin >> array[i];
    }
    int *b = new int[size];
    
    for(int i = 0; i < size; i++){
        b[i] = array[size-1-i];
    }
    delete[] array;
    array = b;
    
    cout << "The reversed array is: " << endl;
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    delete[] b;
    return 0;
}