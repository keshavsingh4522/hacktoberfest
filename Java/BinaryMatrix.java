//coded by shreeyachatzz
//Shreeya Chatterji
/*Accept MX8 as dimensions of a 2dimensional array. Fill up the array with the binary conversion of M no. Of decimal number .Print the column nos. Which are having maximum number of 1’s in it.
If the converted binary number is not comprising of 8 bits eg for 8 it is 1000 fill it up with 00001000.*/
import java.util.*;
public class Q1a
{
    static int arr[][]= new int[100][100]; static int decimal[]= new int[10]; static int bin[]= new int [10];//declaring the arrays as global variables
    static int ww[]= new int[100];
    static int bi,s, c,q, M;//more global variables
    static Scanner st= new Scanner(System.in);//calling scanner class
    void Q1a()//default constructor
    {
        //giving zero as default variables for all the arrays        
        for(int i=0;i<10;i++)
        {
            bin[i]=0;
            ww[i]=0;
        }
        for(int i=0;i<10;i++)
        {
            decimal[i]=0;
        }
        for(int i=0; i<100; i++)
        {
            for(int j=0; j<100; j++)
            {
                arr[i][j]= 0;
            }
        }
        bi=c=s=M=q=0;// giving zero as default variables for the given global values
    }

    void display2D()//displaying the main 2D array
    {

        for(int i=0; i<M; i++)
        {
            for(int j=0; j<8; j++)
            {
                System.out.print(arr[i][j]+" ");
            }
            System.out.println("");
        }

    }

    int toBinary(int n)//converting to binary using recursion
    {
        
        if(n>0)
        {
            int d= n%2;//getting remainder after dividing by 2
            s= s+ d*(int)Math.pow(10,q++);
            toBinary(n/2);//the function calls itself again but this time the value it sends is the quotient of n/2 
        }
        return s;// retuning the binary form of the number
    }

    int To8bitBin(int k)//to find the number of zeroes to be inserted and extracting the digits of the binary number in an array 1407010104397 
    {
        int l=0; int d=0;
        for(int i=k; i>0 ;i=i/10)//to find the length of the current binary number
        {            
            l=l+1;
        }    
        d=l-1;
        for(int i=k;i>0; i=i/10)//inserting each digit of the binary number in the array ww[]
        {
          ww[d]= i%10;
          d--;
        }
        return(l);// retuning the length of the binary number
    } 
    
    int CountOne(int n)// to count the number of ones in column n
    {
        int s=0;// initialising s
        for(int i=0;i<M;i++)//to run through the column
        {
            int k= arr[i][n];
            if(k==1)
            {
                s=s+1;//updating s if the number in the particular cell of the array is 1
            }
        }
        return(s);// retuning the number of s in n
    }

    public static void main(String args[])//main method 
    {
        Scanner sc= new Scanner (System.in);//Calling Scanner class
        Q1a obj= new Q1a();//creating object
        System.out.println("Enter the value for M for the array of dimensions Mx8");
        M= sc.nextInt();//accepting M as input
        int op=M;int i=0;int p=0;//initialising variables
        int mnarr[]= new int[100];//array to store the number of the columns having the maximum number of 1s
        System.out.println("Enter the value of M decimal numbers");
        for(i=0; i<M;i++)//accepting the values from the user
        {
            int t= sc.nextInt();
            decimal[i]= t;
        }
        //filling the array with the corresponding binary values of the decimal numbers entered
        for(i=0;i<M;i++)
        {
            p= decimal[i];
            bi=c=0;
            s=0;q=0;//to ensure that the values of s and q are zero for each iteration
            int t= obj.toBinary(p);            
            bin[i]=t;            
        }        
        //now we fill the double dimension array that we actually require
        System.out.println("The 2D array of Mx8 containing the binary values of the entered decimal numbers");
        for( i=0; i<M; i++)
        {
            for (int j=0; j<8; j++)
            {
                int k= bin[i];
                int f= obj.To8bitBin(k);                
                if(j>=(8-f))
                {
                    for (int t=0; t<f; t++)
                    {
                        arr[i][j]= ww[t];
                        j++;
                    }
                }
                else
                {
                    //because the array arr is already initialized with zero in all the cells
                }

            }
        }
        obj.display2D();           
        int one[]= new int[100];//array stores the number of ones in each column
        for(i=0;i<8;i++)
        {
            one[i]= obj.CountOne(i);//storing the number of zeroes iin the columns
        }
        int max=one[0]; int mn=0;
        for(i=0; i<8; i++)
        {
            if(max<one[i])//comparing each element with the present maximum element to find the max number of zeroes and in whoch column
            {
                max= one[i];
                mn=i;
            }                
        }
        int k=0;
        for(i=0; i<8; i++)
        {
            if(max==one[i])//to check the number of columns which have the max number of zeroes
            {
                mnarr[k]= i;//the array stores the number of the columns having the max number of elements
                k++;//updating loop variable
            }                
        }
        //printing the number of the columns having the maximum number of 1s and the maximum number of zeroes that are present in them
        System.out.print("The column with the maximum number of 1s is/are: ");
        for( i=0; i<k;i++)
        {
            if(i== k-1)
            System.out.print((mnarr[i]+1)+" ");
            else
            System.out.print((mnarr[i]+1)+", ");
        }
        System.out.print("and the number of 1s in them/it is "+max);      
    }
}
/*
(1)OUTPUT:
Enter the value for M for the array of dimensions Mx8
5
Enter the value of M decimal numbers
1
2
3
4
5
The 2D array of Mx8 containing the binary values of the entered decimal numbers
0 0 0 0 0 0 0 1 
0 0 0 0 0 0 1 0 
0 0 0 0 0 0 1 1 
0 0 0 0 0 1 0 0 
0 0 0 0 0 1 0 1 
The column with the maximum number of 1s is/are: 8 and the number of 1s in it is 3

(2)OUTPUT:
Enter the value for M for the array of dimensions Mx8
5
Enter the value of M decimal numbers
0
1
2
3
7
The 2D array of Mx8 containing the binary values of the entered decimal numbers
0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 1 
0 0 0 0 0 0 1 0 
0 0 0 0 0 0 1 1 
0 0 0 0 0 1 1 1 
The column with the maximum number of 1s is/are: 7, 8 and the number of 1s in it is 3
*/ 
