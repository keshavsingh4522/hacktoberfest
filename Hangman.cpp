#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
void main()
{
	clrscr();
	int i,t=5,j,d=0,f=0,p;
	char ch,ch2,str1[20],str2[20],str3[20],letter,let[20];
	cout<<"	"<<"	"<<"	"<<"WELCOME TO HANGMAN!!!\n\n";
	cout<<"Enter word(Player 1)";
	gets(str1);
	strupr(str1);
	clrscr();
	cout<<"		";
	
	cout<<"Player 2 have 5 chances to guess the word"<<endl;
	  do
	  {
		cout<<"1.Do you want to guess word\n ";
		cout<<"Enter choice\n";
		cin>>ch;
		if(ch=='1')
		{
			cout<<"Enter word\n";
			gets(str2);
			strupr(str2);
			if(strcmp(str1,str2)==0)
			{
				cout<<"The answer is correct.You won\n";
				break;
			}
			else
			{
				t--;
				cout<<"The answer is not correct.Try again.\n";
				cout<<"Chances left\n"<<t<<endl;
			}
		if(t==0)
		{
			cout<<"You have lost\n";
		}
		
	  }while(t>0)    ;
	cout<<"Thanks for playing!!!";
	getch();
