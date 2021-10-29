#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int r;
    char name[10];
    float m1,m2,m3,t,p;

    // Time to say who your are
    cout<<"*****************"<<endl;
    cout<<"Enter your Name : ";
    cin>>name;
    cout<<"*****************"<<endl;
    cout<<"Enter your Roll number : ";
    cin>>r;

    // Time to enter mark's
    cout<<"*****************"<<endl;
    cout<<"Enter your mark for 1st Subject : ";
    cin>>m1;
    cout<<"*****************"<<endl;
    cout<<"Enter your mark for 2nd Subject : ";
    cin>>m2;
    cout<<"*****************"<<endl;
    cout<<"Enter your mark for 3rd Subject : ";
    cin>>m3;

    //Find the total marks
    t=m1+m2+m3;

    //Find the total percentage
    p=(t/300)*100;
    cout<<"*****************"<<endl;
    cout<<"*Student Detail*"<<endl;
    cout<<"*****************"<<endl;
    cout<<"_________________"<<endl;
    cout<<"Name : "<<name<<endl;
    cout<<"Roll Number : "<<r<<endl;
    cout<<"Total Mark : " <<t<<endl;
    cout<<"Total Percentage : "<<p<<endl;

    //Time to assign grade according to there %
    if (p>90)
    {
        cout<<"_________________"<<endl;
        cout<<"Grade : A"<<endl;
        cout<<"*****************"<<endl;
    }
    else if (p>70)
    {
        cout<<"_________________"<<endl;
        cout<<"Grade : B"<<endl;
        cout<<"*****************"<<endl;
    }
    else if (p>50)
    {
        cout<<"_________________"<<endl;
        cout<<"Grade : C"<<endl;
        cout<<"*****************"<<endl;
    }
    else
    {
        cout<<"_________________"<<endl;
        cout<<"Grade = D"<<endl;
        cout<<"*****************"<<endl;
    }
    getch();
    return 0;
}
