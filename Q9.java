import java.util.Scanner;
class Q9
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter any string");
        String s=sc.nextLine().toUpperCase();
        int l=s.length();
        for(char y='A';y<='Z';y++)
        {
            int c=0;
            for(int x=0;x<=l-1;x++)
            {
                char ch=s.charAt(x);
                if(ch==y)
                {
                    c++;
                }
            }
            if(c!=0)
            {
                System.out.println(y+"\t"+c);
            }
        }
    }
}

            