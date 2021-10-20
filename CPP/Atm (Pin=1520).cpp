#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;
int main()
{int pin=1520,amount=1000,p,c,w,d;
char transaction='y';
pass:
cout<<"\nEnter Your Secret Account Pin :";
cin>>p;
Sleep(1000);
cout<<endl<<"Loading";
Sleep(1000);
cout<<".";
Sleep(700);
cout<<".";
Sleep(1000);
cout<<".....";
Sleep(400);
cout<<"........100% Completed";
system("cls");
while(transaction=='y'||transaction=='Y')
{
if(p==pin)
{system("cls");
cout<<"\n\n\n******Welcome To ATM Sercice******"<<endl;
cout<<"Press \n 1:Check Balance \n 2:Withdraw Balance\n 3:Deposit Balance\n 4:Quit\n";
cout<<"Enter Choice:_";
c=getch();
switch(c)
{
case('1'):
cout<<"\n\n\nYour Current Balance is Rs:"<<amount<<endl;
break;
case('2'):
	do{
	cout<<"\n\nEnter Rupees to Withdraw Rs:";
	cin>>w;
	if(w%100!=0)
	cout<<"\n\nEnter Rs in Multiple of 100";
     else if(amount-w<500)
     cout<<"\n \t\t\t\tInsifficent Balance Try Again";
     }while(amount-w<500);
    {amount=amount-w;
    cout<<"\n\n\n Your Reamaining Balance is Rs:"<<amount;}
    
    break;
case('3'):
   {	cout<<"\nEnter Rupees to Deposit Rs:";
	cin>>d;
	amount=amount+d;
	cout<<"\n\n \tYour Balance After Deposit is Rs:"<<amount;}
	break;
case('4'):
    cout<<"\n\n\n \t\t******Thanks For Using Our Services******\n";
	break;
	default:
	{	cout<<"\n \n \nWrong Choice"<<endl;Beep(100,2);}
	}   
	
	cout<<endl<<"------------------------\nPress Y to Continue \n\tOr\nPress N to Quit"<<"\n------------------------";
	transaction=getch(); 


}
	else
{cout<<"\n\n\n\n\t\t****************** Wrong Password *******************"<<endl<<endl<<endl;
Sleep(3000);
system("cls");
goto pass;}
Sleep(1000);
}
system("cls");
Sleep(1000);
cout<<endl<<"Quiting";
Sleep(1000);
cout<<".";
Sleep(700);
cout<<".";
Sleep(1000);
cout<<".....";
Sleep(400);
cout<<"........100% Completed";
system("cls");
Beep(100,2);


}	

