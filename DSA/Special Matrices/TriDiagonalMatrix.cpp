//Tri-Diagonal Matrix
//As the name suggests, tri-Diiagonal Matrix is a Matrix such that only its three mid-Digaonals have non-zero values
//So no of non-zero elements in tri Diagonal Matrix = n +  n-1  + n-1 = 3*n -2,
//where n = size of the matrix
//In short we can describe it as following : m[i, j] != 0 if |i-j| <= 1
//Let's Code

#include <iostream>

using namespace std;

class triDiagonal{
    private:
    int size;
    int *ele;

    public:
    triDiagonal(int n){
        this->size = n;
        ele = new int[3*n - 2];
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void Display();
    ~triDiagonal(){delete [] ele;}
};


void triDiagonal :: set(int i, int j, int x){
    if(i - j <= 1 && i - j >= -1){
        if(i < j) ele[i-2] = x;
        else if(i ==j) ele[size -1 + i -1] = x;
        else if(i >= j) ele[2*size - 1 + i - 1] = x;
    }
}

int triDiagonal :: get(int i, int j){
    if(i - j <= 1 && i-j >= -1){
        if(i < j) return ele[i-2];
        else if(i == j) return ele[size - 1 + i -1];
        else if(i >= j) return ele[2*size - 1 + i -1];
    }
    return 0;
}

void triDiagonal :: Display(){
    for(int i=1; i <= size; i++){
        for(int j =1; j <= size; j++){
            int data = 0;
            if(i -j >= -1 && i-j <= 1){
                if(i < j) data = ele[i-2];
                else if(i == j) data = ele[size - 1 + i -1];
                else if(i >= j) data = ele[2*size -1 + i -1];
            }
            printf("%-3d", data);
        }
        cout << endl;
    }
}

int main(){
    int size;
    cout << "Enter the size of the TriBand Matrix : ";
    cin >> size;
    triDiagonal tri(size);

    cout << endl;
    cout << "Enter the Elements and the indices of the TriDiagonal Matrix : \n";
    int i, j, x;
    for(int k=0; k < 3* size - 2; k++){
        cin >> i >> j >> x;
        tri.set(i, j, x);
    }
    
    cout << endl;
    tri.Display();
    cout << endl << endl;
    int choice = 1;
    while(choice){
        printf("Enter the Element indices you want to search for : ");
        cin >> i >> j;
        printf("Element at index %d,%d = %d\n", i, j, tri.get(i, j));
        cout << "Do you want to continue to search. Press 1 for Y, 0 for N : ";
        cin >> choice;
        if(choice == 0) exit(0);
    }
    return 0;
}
