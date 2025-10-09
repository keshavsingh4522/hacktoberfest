//Symmetric matrix xan be implemented either using upper Triangular or Lower Triangular Matrices.
//They follow the condition A[i, j] = A[j, i]

#include <iostream>

using namespace std;

class SymmetricMatrix{
    private:
    int size;
    int *ele;

    public:
    SymmetricMatrix(int n){
        this->size = n;
        ele = new int[n*(n+1)/2];
    }  

    void set(int i, int j, int x);
    int get(int i, int j);
    void Display();
    ~SymmetricMatrix(){delete [] ele;}
};

void SymmetricMatrix :: set(int i, int j, int x){
    if(i >= j)
        ele[(i*(i-1))/2 + j-1] = x;
    else 
        ele[size * (j-1) - ((j-1)*(j-2))/2 +i-j] = x;
}

int SymmetricMatrix :: get(int i, int j){
    if(i >= j)
        return ele[i*(i-1)/2 + j-1];
    else
        return ele[j * (j-1)/2 + i-1]; 
}

void SymmetricMatrix :: Display(){
    for(int i =1; i <= size; i++){
        for(int j =1; j <= size; j++){
            if(i <= j) printf("%3d", ele[(i*(i-1))/2 + j-1]);
            else printf("%3d", ele[(j*(j-1))/2 + i-1]);
        }
        cout << endl;
    }
}


int main(){
    int index;
    cout << "Enter the size of the Matrix : " ;
    cin >> index;
    SymmetricMatrix mat(index);
    printf("Enter the Elements along with indices : \n");
    int i, j, val;
    for(int k=0; k < (index*(index+1))/2; k++){
        cin >> i >> j >> val;
        mat.set(i, j, val);
    }

    cout << endl;
    mat.Display();
    cout << endl << endl;
    int choice = 1;
    while(choice){
        cin >> i >> j;
        printf("Element at index %d,%d = %d\n", i, j, mat.get(i, j));
        cout << "Do you want to continue Searching. Press 1 for Y, 0 for N : ";
        cin >> choice;
    }
}