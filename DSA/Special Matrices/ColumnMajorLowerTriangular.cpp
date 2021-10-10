#include <iostream>

using namespace std;

class Matrix{
    private:
    int size;
    int *A;

    public:
    Matrix(int size){
        this->size = size;
        A = new int[size*(size+1)/2];
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void Display();
    ~Matrix(){delete [] A;}
};

void Matrix :: set(int i, int j, int x){
    if(i >= j) A[size*(j-1) - ((j-1)*(j-2))/2 + i-j] = x;
}

int Matrix :: get(int i, int j){
    if(i < j) return 0;
    else return A[size*(j-1) - ((j-1)*(j-2))/2 + i-j];
}

void Matrix :: Display(){
    for(int i = 1; i <= size; i++){
        for(int j = 1; j <= size; j++){
            if(i < j)
                printf("%3d ", 0);
            else
                printf("%3d ", A[size*(j -1) - ((j-1)*(j-2))/2 +i-j]);
        }
        printf("\n");
    }
}


int main(){
    int size;
    cin >> size;
    Matrix mat(size);
    for(int i=1; i<= size; i++){
        for(int j=1; j <= size; j++){
            int num;
            cin >> num;
            mat.set(i, j, num);
        }
    }

    cout << mat.get(5, 2) << endl;
    cout << mat.get(1, 0) << endl;
    cout << mat.get(1, 4) << endl;
    cout << mat.get(4, 4) << endl;
    cout << mat.get(4, 1) << endl;
    

    mat.Display();
}