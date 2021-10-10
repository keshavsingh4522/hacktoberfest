#include <stdio.h>
#include <stdlib.h>

typedef struct RLowerTriangularMatrix{
    int *A;
    int size;
}Matrix;

void set(Matrix *m,int i, int j, int x){
    if(i >= j) m->A[(i*(i-1))/2 + j-1] = x;
}

int get(Matrix m, int i, int j){
    if(i < j) return 0;
    else return m.A[(i*(i-1))/2 + j-1];
}

void Display(Matrix m){
    for(int i=1; i<=m.size; i++){
        for(int j=1; j <= m.size; j++){
            if(i < j) printf("%3d ", 0);
            else 
                printf("%3d ", m.A[(i*(i-1))/2 + j-1]);
        }
        printf("\n");
    }
} 

int main(int argc, char const *argv[])
{
    Matrix m;
    m.size = 4;
    m.A = (int *)malloc(sizeof(int)*(m.size*(m.size+1))/2);
    set(&m, 1, 1, 25);
    set(&m, 2, 1, 22);
    set(&m, 2, 2, 45);
    set(&m, 3, 1, 17);
    set(&m, 3, 2, 75);
    set(&m, 3, 3, 24);
    set(&m, 4, 1, 98);
    set(&m, 4, 2, 56);
    set(&m, 4, 3, 91);
    set(&m, 4, 4, 64);

    printf("%d\n\n",get(m, 4, 2));
    Display(m);
    return 0;
}

