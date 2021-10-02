import java.util.Scanner;
class SaddlePoint
{
    public static void main(String[]args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter n");
        int n = sc.nextInt();
        
        int ar[][] = new int[n][n];
        int i = 1,a=0,b=n-1;
        while(a<=b)
        {
            for(int x =a ; x<=b ; x++)
            {
                for(int y =a ; y<=b ; y++)
                {
                    ar[x][y]=i++;
                }
            }
        }
        for(int x = 0 ; x<n ; x++)
        {
            for(int y = 0 ; y<n ; y++)
            {
                System.out.println(ar[x][y]+"\t");
            }
        }
    }
}
