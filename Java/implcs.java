public class Imp_lcs {          //-------------------------------------1

public static void main (String[] args) {
    String X = "AGGTAB";       //--------------------------------------2
    String Y = "GXTXAYB";      //--------------------------------------2

    int m = X.length();        //--------------------------------------3 
    int n = Y.length();        //--------------------------------------3
 
    lcs_method(X, Y, m, n);

} 

static void lcs_method (String X, String Y, int m, int n) {   //-------4

int [][] arr = new int [m+1] [n+1];  //------------------------------5.a

for (int i = 0; i<=m; i++) {         //---------------------------- ---5.b
    for (int j = 0; j<=n; j++) {     //--------------------------------5.b
  
        if (i==0 || j==0){           //--------------------------------5.c.i
            arr [i][j] = 0;  
        }

        else if (X.charAt(i-1) == Y.charAt(j-1)) {    //---------------5.c.ii
            arr[i][j] = arr[i-1][j-1] + 1; 
        }

        else {
            arr [i][j] = Math.max(arr[i-1][j], arr[i][j-1]);  //-------5.c.iii
        }

}
}

int index = arr[m][n];               //--------------------------------5.d  
int print = index;

char[] LCS = new char[index+1];      //--------------------------------5.e
LCS[index] = '\u0000';  // to set the terminating default value for character array

int i = m;
int j = n;

while (i>0 && j > 0){

    if (X.charAt(i-1) == Y.charAt(j-1)){        //---------------------5.f.i
        LCS[index-1] = X.charAt(i-1);
        i--;
        j--;
        index--;
    }

    else if (arr[i-1][j] > arr[i][j-1])         //---------------------+5.d
        i--;
    else
        j--;       
}

System.out.print( "\n\nLCS of the sequence " +X+ " and sequence " +Y+ " is :  ");
   for (int k=0; k < print; k++)               //---------------------+5.g
   System.out.print( LCS[k]);
   System.out.print( "\n\n" );
}


}
