#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

void Genpwd()
{
    srand(time(NULL));
    int choice, temp=0, len, c, i, temp2=0;
    string num="1234567890";
    string alpha="aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVxXyYzZ";
    string spclchar="!@#$%^&*()_-+[]{};:,.//||\\";
    cout<<"\nEnter length of your password : ";
    cin>>len;
    cout<<"\n\tWhat should your password contain : "<<endl;
    cout<<"\tEnter all the choice in sequence(e.g 123)"<<endl;
    cout<<"\t->(1)Number                         "<<endl;
    cout<<"\t->(2)Alphabets                      "<<endl;
    cout<<"\t->(3)Special Characters             "<<endl;
    cin>>choice;
    if(choice<10)
    {
        switch(choice)
        {
        case 1:
            cout<<"\n\tYOUR_PASSWORD : ";
            for(i=0; i<len; i++)
            {
                temp=rand()%num.length();
                cout<<num[temp];
            }
            break;
        case 2:
            cout<<"\n\tYOUR_PASSWORD : ";
            for(i=0; i<len; i++)
            {
                temp=rand()%alpha.length();
                cout<<alpha[temp];
            }
            break;
        case 3:
            cout<<"\n\tYOUR_PASSWORD : ";
            for(i=0; i<len; i++)
            {
                temp=rand()%spclchar.length();
                cout<<spclchar[temp];
            }
            break;
        }
        cout<<"\n\n\t->(1) Regenerate"<<endl;
        cout<<"\t->(2) Exit"<<endl;
        cin>>c;
        if(c==1)
        {
            Genpwd();
        }
        else
        {
            exit(0);
        }
    }
    else if(choice>10 && choice<100)
    {
        switch(choice)
        {
        case (12):
            cout<<"\n\tYOUR_PASSWORD : ";
            for(i=0; i<len; i++)
            {
                temp2=rand()%2;
                switch (temp2)
                {
                case 0:
                    temp=rand()%alpha.length();
                    cout<<alpha[temp];
                    break;
                case 1:
                    temp=rand()%num.length();
                    cout<<num[temp];
                    break;
                }
            }
            break;
        case (13):
            cout<<"\n\tYOUR_PASSWORD : ";
            for(i=0; i<len; i++)
            {
                temp2=rand()%2;
                switch (temp2)
                {
                case 0:
                    temp=rand()%spclchar.length();
                    cout<<spclchar[temp];
                    break;
                case 1:
                    temp=rand()%num.length();
                    cout<<num[temp];
                    break;
                }
            }
            break;
        case (23):
            cout<<"\n\tYOUR_PASSWORD : ";
            for(i=0; i<len; i++)
            {
                temp2=rand()%2;
                switch (temp2)
                {
                case 0:
                    temp=rand()%alpha.length();
                    cout<<alpha[temp];
                    break;
                case 1:
                    temp=rand()%spclchar.length();
                    cout<<spclchar[temp];
                    break;
                }
            }
            break;
        }
        cout<<"\n\n\t->(1) Regenerate"<<endl;
        cout<<"\t->(2) Exit"<<endl;
        cin>>c;
        if(c==1)
        {
            Genpwd();
        }
        else
        {
            exit(0);
        }
    }
    else
    {
        cout<<"\n\tYOUR_PASSWORD : ";
        for(i=0; i<len; i++)
        {
            temp2=rand()%3;
            switch (temp2)
            {
            case 0:
                temp=rand()%alpha.length();
                cout<<alpha[temp];
                break;
            case 1:
                temp=rand()%num.length();
                cout<<num[temp];
                break;
            case 2:
                temp=rand()%spclchar.length();
                cout<<spclchar[temp];
                break;
            }
        }
        cout<<"\n\n\t->(1) Regenerate"<<endl;
        cout<<"\t->(2) Exit"<<endl;
        cin>>c;
        if(c==1)
        {
            Genpwd();
        }
        else
        {
            exit(0);
        }
    }
}
int main()
{
    int n, len;
    cout<<" \t\t _________________________"<<endl;
    cout<<"\t\t|RANDOM PASSWORD GENERATOR|"<<endl;
    cout<<"\t\t `````````````````````````"<<endl;
    cout<<"\t\t->(1)Generate Password   "<<endl;
    cout<<"\t\t->(2)Exit                "<<endl;
    cin>>n;
    switch (n)
    {
    case 1:
        Genpwd();
        break;
    case 2:
        exit(0);
        break;
    default:
        cout<<"Invalid Input"<<endl;
        break;
    }
    return 0;
}
