#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> Add(vector<vector<int>> A,vector<vector<int>> B,int n){
    vector<vector<int>> Ans(n,vector<int> (n,0));
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        Ans[i][j]=A[i][j] + B[i][j];
    return Ans;
}

vector<vector<int>> Multiply(vector<vector<int>> A,vector<vector<int>> B,int n){
    vector<vector<int>> Ans(n,vector<int> (n,0));
    int i,j;
    if(n<=2){
        Ans[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
        Ans[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
        Ans[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
        Ans[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1];
    }
    else{
        vector<vector<int>> A11(n/2,vector<int> (n/2,0));
        vector<vector<int>> A12(n/2,vector<int> (n/2,0));
        vector<vector<int>> A21(n/2,vector<int> (n/2,0));
        vector<vector<int>> A22(n/2,vector<int> (n/2,0));

        vector<vector<int>> B11(n/2,vector<int> (n/2,0));
        vector<vector<int>> B12(n/2,vector<int> (n/2,0));
        vector<vector<int>> B21(n/2,vector<int> (n/2,0));
        vector<vector<int>> B22(n/2,vector<int> (n/2,0));

        vector<vector<int>> C11(n/2,vector<int> (n/2,0));
        vector<vector<int>> C12(n/2,vector<int> (n/2,0));
        vector<vector<int>> C21(n/2,vector<int> (n/2,0));
        vector<vector<int>> C22(n/2,vector<int> (n/2,0));

        //Assigning values to smaller A matrix,Dividing
        for(i=0;i<n/2;i++){
            for(j=0;j<n/2;j++)
                A11[i][j]=A[i][j];
            for(j=n/2;j<n;j++)
                A12[i][j-n/2]=A[i][j];
        }
        for(i=n/2;i<n;i++){
            for(j=0;j<n/2;j++)
                A21[i-n/2][j]=A[i][j];
            for(j=n/2;j<n;j++)
                A22[i-n/2][j-n/2]=A[i][j];
        }
        //Assigning values to smaller B matrix,Dividing
        for(i=0;i<n/2;i++){
            for(j=0;j<n/2;j++)
                B11[i][j]=B[i][j];
            for(j=n/2;j<n;j++)
                B12[i][j-n/2]=B[i][j];
        }
        for(i=n/2;i<n;i++){
            for(j=0;j<n/2;j++)
                B21[i-n/2][j]=B[i][j];
            for(j=n/2;j<n;j++)
                B22[i-n/2][j-n/2]=B[i][j];
        }

        //Multiplying Smaller matrix
        C11 = Add(Multiply(A11,B11,n/2),Multiply(A12,B21,n/2),n/2);
        C12 = Add(Multiply(A11,B12,n/2),Multiply(A12,B22,n/2),n/2);
        C21 = Add(Multiply(A21,B11,n/2),Multiply(A22,B21,n/2),n/2);
        C22 = Add(Multiply(A21,B12,n/2),Multiply(A22,B22,n/2),n/2);


        //Assigning values from small matrix,Adding
        for(i=0;i<n/2;i++){
            for(j=0;j<n/2;j++)
                Ans[i][j]=C11[i][j];
            for(j=n/2;j<n;j++)
                Ans[i][j]=C12[i][j-n/2];
        }
        for(i=n/2;i<n;i++){
            for(j=0;j<n/2;j++)
                Ans[i][j]=C21[i-n/2][j];
            for(j=n/2;j<n;j++)
                Ans[i][j]=C22[i-n/2][j-n/2];
        }
    }
    return Ans;
}
int main(){
    int n=64,i,j,sum=0;
    vector<vector<int>> MatrixA(n,vector<int> (n,0));
    vector<vector<int>> MatrixB(n,vector<int> (n,0));

    //Assigning Matrix
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        MatrixA[i][j] = ++sum;
    sum = 0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        MatrixB[i][j] = ++sum;

    //Printing Matrix
    cout<<"Matrices are : \nA: \n";
        for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        cout<<MatrixA[i][j]<<" ";
        cout<<endl;
        }
        cout<<"\nB: \n";
        for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        cout<<MatrixB[i][j]<<" ";
        cout<<endl;
        }
    //////////////////////
    vector<vector<int>> MatrixAB(n,vector<int> (n,0));
    MatrixAB = Multiply(MatrixA,MatrixB,n);
    cout<<"Answer : \n";
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        cout<<MatrixAB[i][j]<<" ";
        cout<<endl;
        }
return 0;
}
