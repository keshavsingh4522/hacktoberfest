void rotate(int** matrix, int matrixSize, int* matrixColSize){
int temp;
    for(int i=0;i<matrixSize;i++)
    for(int j=0;j< i;j++)
    {   temp= matrix[j][i];
        matrix[j][i]=matrix[i][j];
        matrix[i][j]=temp;
    }
    for(int i=0,j=(matrixSize-1);i<j;i++,j--)
        for(int k=0;k<matrixSize;k++){
            temp= matrix[k][i];
        matrix[k][i]=matrix[k][j];
        matrix[k][j]=temp;
        }

}