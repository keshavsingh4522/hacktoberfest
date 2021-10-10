//Toeplitz Martrix is a Special Matrix with all elements in each of the diagonals same.
//Thus it follows the rule: M[i, j] = M[i-1, j-1]
//The ToePlitz Matrix can be compressed down to a very small size for a given Matrix thus reducing a lot of space
//Let's Code Toeplitz Matrix:

#include <iostream>

using namespace std;

class Toeplitz{
    private:
    int size;
    int *ele;

    public:
    Toeplitz(int n){
        this ->size = n;
        ele = new int[n + n - 1];
    }
    ~Toeplitz(){delete [] ele;}
    void set(int i, int j, int x);
    int get(int i, int j);
    void Display();
};

void Toeplitz :: set(int i, int j, int x){
    if(i == 1) ele[j-1] = x;
    else if(j == 1) ele[size + i - 1] = x;
}

int Toeplitz :: get(int i, int j){
    if(j >= i) return ele[j-i];
    else return ele[size + i - j];
}

void Toeplitz :: Display(){
    for(int i=1; i <= size; i++){
        for(int j=1; j <=size; j++){
            if(j >= i) printf("%-3d", ele[j-i]);
            else printf("%-3d", ele[size + i-j]);
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    //Craton of Matrix
    int n;
    cout << "Enter the size of Toeplitz Matrix : ";
    cin >> n;
    Toeplitz toe(n);
    cout << "Enter the elements along with indices of Toeplitz Matrix : \n";
    int i, j, x;
    for(int k=0; k<n + n-1; k++){
        cin >> i >> j >> x;
        toe.set(i, j, x);
    }
    cout << endl << endl;
    
    //Displaying the Matrix:
    toe.Display();
    cout << endl;

    //Searching a particulat Element:
    int choice = 1;
    while(choice){
        cout << "Enter the indices of Elements to search for : ";
        cin >> i >> j;
        printf("The Elements at indices %d,%d = %d\n\n", i, j, toe.get(i, j));

        cout << "Do you want to continue the search?? Press 1 for Y, 0 for N : ";
        cin >> choice;
    }
    return 0;
}

 