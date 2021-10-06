/*Given numRows = 5,

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]*/

public class PascalTriangle
{
    public int[][] solve(int A)
    {
        int[][] B=new int[A][A];
        for(int i=0;i<A;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if (i == j || j == 0) 
                    B[i][j] = 1; 
                else
                    B[i][j] = B[i-1][j-1] + B[i-1][j]; 
            }
        }
        return B;
    }
}