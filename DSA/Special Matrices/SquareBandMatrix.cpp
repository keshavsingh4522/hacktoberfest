//SquareBand Matrix resembles TriDiagonal  Matrix. Only in this case, instead of three diagonals there are much more.
//Thus they show resemeblance to bands of diaagonals and occur in Square Matrix and hence are called as SquareBand Matrices.
//Now why to use Square band Matrix??
//If you have got a matrix of order say 100 X 100 or even arger with only 6-7 bands with non-zero elements, then implementation using
//Square aband matrices save a lot space.
//Let's code SquareBand Matrix

#include <iostream>
#include <cmath>

using namespace std;

//Defining the Class
class SquareBand{
    private:
    int size;
    int l_band;
    int u_band;
    int *ele;

    public:
    SquareBand(int size, int l_bands, int u_bands){
        this->size = size;
        this->l_band = l_bands;
        this->u_band = u_bands;
        ele = new int[(l_bands + u_bands + 1)*size - (l_bands*(l_bands+1))/2 - (u_bands*(u_bands+1))/2];
    }

    void set(int i, int j, int x);
    int get(int i, int j);
    void Display();
    ~SquareBand(){delete [] ele;}
};

//Defining the Functions
void SquareBand :: set(int i, int j, int x){
    int diff = size - (i - j);
    int d = j - i;
    if(j-i >= -l_band && j - i <= u_band){
        if(i > j) ele[((diff*(diff-1))/2 - l_band - 1)+ j - 1] = x;
        else if(i == j) ele[(size*(size-1))/2 - (l_band*(l_band + 1))/2 + j -1] = x;
        else if(i < j)
            ele[(size * (size + 1)) / 2 - (l_band * (l_band + 1)) / 2 + (size * d - (d * (d + 1)) / 2 - size + 1) + j - 1] = x;
    }
}

int SquareBand :: get(int i, int j){
    int diff = size - (i - j);
    int d = j -  i;
    if(j-i >= -l_band && j - i <= u_band){
        if(i > j) return ele[((diff*(diff-1))/2 - l_band - 1)+ j - 1];
        else if(i == j) return ele[(size*(size-1))/2 - (l_band*(l_band + 1))/2 + j -1];
        else if(i < j) return ele[(size*(size+1))/2 - (l_band*(l_band + 1))/2 + (size*d - (d*(d+1))/2 - size  + 1) +j-1];
    }
    return 0;
}

void SquareBand :: Display(){
    for(int i=1; i <= size; i++){
        for(int j=1; j <= size; j++){
            int data = 0;
            int diff = size - (i - j);
            int d = j - i;
            if(j-i >= -l_band && j - i <= u_band){
                if(i > j) data = ele[((diff*(diff-1))/2 - l_band - 1)+ j - 1];
                else if(i == j) data = ele[(size*(size-1))/2 - (l_band*(l_band + 1))/2 + j -1];
                else if(i < j) data = ele[(size*(size+1))/2 - (l_band*(l_band + 1))/2 + (size*d - (d*(d+1))/2 - size  + 1) +j-1];
            }
            printf("%-3d", data);
        }
        cout << endl;
    }
}

int main(){
    //Setting the MAtrix
    cout << "Enter the size of SquareBand Matric along with lower and upper bounds : ";
    int s, m, n, x;
    cin >> s >> m >> n;
    SquareBand sq(s, m, n);

    //Entering the Elements
    int size2 = (m + n + 1)*s - (m*(m+1))/2 - (n*(n+1))/2;
    cout << "Now Enter the Elements of your SquareBand Matrix along with indices : \n";
    for(int i=0; i < size2; i++){
        cin >> m >> n >> x;
        sq.set(m, n, x);
    }
    cout << endl;

    //Displaying the Matrix
    cout << "Matrix : \n";
    sq.Display();

    cout << endl << endl;
    //Getting the individual Values
    int choice = 1;
    while(choice){
        cout << "Enter the indices of Elements to search for: " << endl;
        cin >> m >> n;
        printf("The Element at index %d,%d = %d\n\n", m, n, sq.get(m, n));
        printf("Do you want to continue search?? Press 1 for Y, 0 for N : ");
        cin >> choice;
    }
    return 0;
}