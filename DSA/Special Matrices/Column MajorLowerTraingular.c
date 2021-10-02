#include <stdio.h>
#include <stdlib.h>

typedef struct CLowerTriangularMatrix{
    int size;
    int *A;
}Matrix;

void set(Matrix *m, int i, int j, int x){
    if(i >= j) m->A[m->size*(j-1) - ((j-1)*(j-2))/2 + i-j] = x;
}

int get(Matrix m, int i, int j){
    if(i < j) return 0;
    else return m.A[m.size*(j-1) - ((j-1)*(j-2))/2 + i-j];
}

void Display(Matrix m){
    for(int i = 1; i <= m.size; i++){
        for(int j = 1; j <= m.size; j++){
            if(i < j)
                printf("%3d ", 0);
            else
                printf("%3d ", m.A[m.size*(j -1) - ((j-1)*(j-2))/2 +i-j]);
        }
        printf("\n");
    }
}


int main(){
    Matrix mat;
    mat.size = 5;
    mat.A = (int *)malloc(sizeof(int)*(mat.size*(mat.size+1))/2);

    set(&mat, 1, 1, 24);
    set(&mat, 2, 1, 67);
    set(&mat, 2, 2, 12);
    set(&mat, 3, 1, 63);
    set(&mat, 3, 2, 19);
    set(&mat, 3, 3, 42);
    set(&mat, 4, 1, 90);
    set(&mat, 4, 2, 51);
    set(&mat, 4, 3, 63);
    set(&mat, 4, 4, 72);
    set(&mat, 5, 1, 52);
    set(&mat, 5, 2, 89);
    set(&mat, 5, 5, 61);
    set(&mat, 5, 4, 71);
    set(&mat, 5, 3, 112);

    printf("%d\n", get(mat, 5, 2));
    printf("%d\n",get(mat, 1, 0));
    printf("%d\n",get(mat, 1, 4));
    printf("%d\n",get(mat, 4, 4));
    printf("%d\n\n",get(mat, 4, 1));
    

    Display(mat);
}