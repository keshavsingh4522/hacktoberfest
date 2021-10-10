#include <iostream>

using namespace std;

//Lower Triangular Matrix Row major Represetation
class LowerTriangularMatrix{
    private:
        int *A;
        int size;
    
    public:
        LowerTriangularMatrix(int n){
            this->size = n;
            A = new int[(n*(n+1))/2];
        }

        void set(int i, int j, int x);
        int get(int i, int j);
        void Display();
        ~LowerTriangularMatrix(){delete [] A;}
};

void LowerTriangularMatrix :: set(int i, int j, int x){
    if(i >= j)
        A[(i*(i-1))/2 + j-1] = x;
}

int LowerTriangularMatrix :: get(int i, int j){
    if(i < j) return 0;
    else return A[(i*(i-1))/2 + j-1];
}

void LowerTriangularMatrix :: Display(){
    for(int i=1; i<= size; i++){
        for(int j = 1; j<= size; j++){
            if(i >= j) {
                printf("%3d ", A[(i*(i-1))/2 + j-1]);
            }
            else printf("%3d ", 0);
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    LowerTriangularMatrix mat(5);
    mat.set(1, 1, 24);
    mat.set(2, 1, 67);
    mat.set(2, 2, 12);
    mat.set(3, 1, 63);
    mat.set(3, 2, 19);
    mat.set(3, 3, 42);
    mat.set(4, 1, 90);
    mat.set(4, 2, 51);
    mat.set(4, 3, 63);
    mat.set(4, 4, 72);
    mat.set(5, 1, 52);
    mat.set(5, 2, 89);
    mat.set(5, 5, 61);
    mat.set(5, 4, 71);
    mat.set(5, 3, 112);

    cout << mat.get(5, 2) << endl;
    cout << mat.get(1, 0) << endl;
    cout << mat.get(1, 4) << endl;
    cout << mat.get(4, 4) << endl;
    cout << mat.get(4, 1) << endl;
    cout << endl;

    mat.Display();
    return 0;
}
