class RotateMatrix {
  
    static void rotate(int matrix[][]) {
      
        //swapping
        for(int i=0; i<matrix.length; i++) {
            for(int j= i; j<matrix[i].length; j++) {
                int temp= matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        
        //interchanging the rows to get output matrix
        for(int i=0; i<matrix.length/2; i++) {
            for(int j=0; j<matrix[i].length; j++) {
                int temp= matrix[i][j];
                matrix[i][j]= matrix[matrix.length-i-1][j];
                matrix[matrix.length-i-1][j]= temp;
            }
        }
    }
}
