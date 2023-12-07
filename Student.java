import java.util.Scanner;
class Student
{
    String name;
    int age,m1,m2,m3,maximum;
    double average;
    public Student(String n,int ag,int a,int b,int c,int max,double avg)
    {
        name=n;
        age=ag;
        m1=a;
        m2=b;
        m3=c;
        maximum=max;
        average=avg;
    }
    public void input()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter name");
        name=sc.nextLine();
        System.out.println("Enter age");
        age=sc.nextInt();
        System.out.println("Enter marks in subject 1");
        m1=sc.nextInt();
        System.out.println("Enter marks in subjext 2");
        m2=sc.nextInt();
        System.out.println("Enter marks in subject 3");
        m3=sc.nextInt();
    }
    public void compute()
    {
        if(m1>=m2&&m1>=m3)
        {
            maximum=m1;
        }
        else if(m2>=m3&&m2>=m1)
        {
            maximum=m2;
        }
        else
        {
            maximum=m3;
        }
        average=(m1+m2+m3)/3.0;
    }
    public void display()
    {
        System.out.println("NAME\t"+name);
        System.out.println("Age\t"+age);
        System.out.println("MARKS 1\t"+m1);
        System.out.println("MARKS 2\t"+m2);
        System.out.println("MARKS 3\t"+m3);
        System.out.println("MAXIMUM\t"+maximum);
        System.out.println("AVERAGE\t"+average);
    }
    public static void main(String args[])
    {
        Student ob=new Student("Ansh Jaiswal",16,75,80,85,0,0.0);
        ob.compute();
        ob.display();
        System.out.println();
        ob.input();
        ob.compute();
        ob.display();
    }
}