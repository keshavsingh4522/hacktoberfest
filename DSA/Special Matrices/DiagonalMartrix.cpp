#include <iostream>

using namespace std;

class Matrix{
    private:
    int *A;
    int size;

    public:
    Matrix(int size){
        A = new int(size);
        this->size = size;
    }

    void  set_element(int i, int j , int x);
    int get_element(int i, int j);
    void Display();
    int sum_all_elements();
    ~Matrix(){delete [] A;}
};

void Matrix :: set_element(int i, int j, int x){
    if(i == j) A[i-1] = x;
}

int Matrix :: get_element(int i, int j){
    if(i != j) return 0;
    else return A[i-1];
}

void Matrix :: Display(){
    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
            if(i == j) printf("%2d ", A[i]);
            else printf("%2d ", 0); 
        }            
        cout << endl;
    }
}
int Matrix :: sum_all_elements(){
    int sum = 0;
    for(int i=0; i < size; i++) sum += A[i]; 
    return sum;
}

int main(int argc, char const *argv[])
{
    Matrix a(5);
    a.set_element(4, 5, 12);
    a.set_element(4, 4, 36);
    a.set_element(1, 1, 14);
    a.set_element(2, 2, 74);
    a.set_element(3, 3, 67);
    a.set_element(5, 5, 17);
    a.set_element(1, 4, 71);

    cout << a.get_element(1,1)<< endl;
    cout << a.get_element(2,3)<< endl;
    cout << a.get_element(2,2)<< endl;
    cout << a.get_element(4,5)<< endl;
    cout << a.get_element(3, 3)<< endl;
    cout << a.get_element(5,5)<< endl;
    cout << a.get_element(4,4)<< endl;

    cout << "Sum : " << a.sum_all_elements();   
    cout << endl << endl;
    a.Display();
    return 0;
}
