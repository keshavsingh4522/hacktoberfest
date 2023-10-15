#include <iostream>
#define endl "\n"
using namespace std;

//Row Major-Upper Triangular
class RUpperTriMatrix{
    private:
    int size;
    int *A;

    public:
        RUpperTriMatrix(int n){
            size = n;
            A = new int[(n*(n+1))/2];
        }

        void set(int i, int j, int x);
        int get(int i, int j);
        void Display();
        ~RUpperTriMatrix(){delete [] A;}
};

void RUpperTriMatrix :: set(int i, int j, int x){
    if(i <= j)
        A[size*(i-1) - ((i-1)*(i-2))/2 + j-i] = x;
}

int RUpperTriMatrix :: get(int i, int j){
    if(i <= j) return A[size*(i-1) -  ((i-1)*(i-2))/2 +j-i];
    else return 0;
}

void RUpperTriMatrix :: Display(){
    for(int i=1; i<= size; i++){
        for(int j=1; j <= size; j++){
            if(i <= j) printf("%3d ", A[size*(i-1) - ((i-1)*(i-2))/2 + j-i]);
            else printf("%3d ",0);
        }
        cout << endl;
    }
} 

//Column Major-Upper traingular
class CUpperTriMatrix{
    private:
    int size;
    int *A;

    public:
    CUpperTriMatrix(int n){
        this->size = n;
        A = new int[(n*(n+1))/2];
    }
    ~CUpperTriMatrix(){delete [] A;}
    void set(int i, int j, int x);
    int get(int i, int j);
    void Display();
};

void CUpperTriMatrix :: set(int i, int j, int x){
    if(i <= j) A[(j*(j-1))/2 + i-1] = x;
}

int CUpperTriMatrix :: get(int i, int j){
    if(i <= j) return A[(j*(j-1))/2 + i-1];
    else return 0;
}

void CUpperTriMatrix :: Display(){
    for(int i=1; i<=size; i++){
        for(int j=1; j <=size; j++){
            if(i <= j) printf("%3d ",A[(j*(j-1))/2 + i-1]);
            else printf("%3d ", 0);
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    int size;
    cin >> size;
    RUpperTriMatrix tri1(size);
    CUpperTriMatrix tri2(size);
    int num;
    for(int i=1; i<=size; i++) {
        for(int j=1; j <=size; j++){
            cin >> num; 
            tri1.set(i, j, num);
            tri2.set(i, j, num);
        }
    }   

    tri1.Display();
    cout << endl << endl;
    cout << tri1.get(5,5) << endl;
    cout << tri1.get(3,4) << endl;
    cout << tri1.get(4,1) << endl;

    tri2.Display();
    cout << endl << endl;
    cout << tri2.get(5,5) << endl;
    cout << tri2.get(3,4) << endl;
    cout << tri2.get(4,1) << endl;
    return 0;
}
