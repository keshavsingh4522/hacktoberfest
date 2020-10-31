//@Ankush9954
//Snake And Ladder using C++.
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

  void draw_line(int n, char ch);
  void board();
  void gamescore(char name1[], char name2[], int p1, int p2);
  void play_dice(int &score);

  void main()
    {
      clrscr();
      int player1=0, player2=0, lastposition;
      char player1name[80], player2name[80];
      randomize();
      draw_line(50, '=');
      cout<<"\n\n\n\n\t\tSNAKE LADDER GAME\n\n\n\n";
      draw_line(50, '=');
      cout<<"\n\n\nEnter Name of Player 1 =";
      gets(player1name);
      cout<<"\n\n\nEnter Name of Player 2 =";
      gets(player2name);
      while(player1<=100&&player2<=100)
	{
	  board();
	  gamescore(player1name,player2name,player1,player2);
	  cout<<"\n\n--->"<<player1name<<" Now yourTurn>>Press any key to play";
	  getch();
	  lastposition=player1;
	  play_dice(player1);
	  if(player1<lastposition)
	    cout<<"\n\n\aOops!! Snake found !! You are at position "<<player1<<"\n";
	  else if(player1>lastposition+6)
	    cout<<"\n\nGreat!! You got a ladder!! You are at position "<<player1<<"\n";
	  #include<iostream.h>
	  cout<<"\n\n--->"<<player2name<<" Now yourTurn>>Press any key to play";
	  getch();
	  lastposition=player2;
	  play_dice(player2);
	  if(player2<lastposition)
	    cout<<"\n\n\aOops!! Snake found !! You are at position "<<player2<<"\n";
	  else if(player2>lastposition+6)
	    cout<<"\n\nGreat!! You got a ladder!! You are at position "<<player2<<"\n";
	  getch();
	}
      clrscr();
      cout<<"\n\n\n";
      draw_line(50,'+');
      cout<<"\n\n\t\tRESULT\n\n";
      draw_line(50,'+');
      cout<<endl;
      gamescore(player1name, player2name, player1, player2);
      cout<<"\n\n\n";
      if(player1>=100)
	cout<<player1name<<" !!You are the winner\n\n";
      else if(player2>=100)
	cout<<player2name<<" !!You are the winner\n\n";
      draw_line(50,'+');
      getch();
    }
  void draw_line(int n, char ch)
    {
      for(int i=0;i<n;i++)
	cout<<ch;
    }
  void board()
    {
      clrscr();
      cout<<"\n\n";
      draw_line(50,'-');
      cout<<"\n\t\tSNAKE AT POSITION\n";
      draw_line(50,'-');
      cout<<"\n\tFrom 98 to 28,95 to 24,92 to 51,83 to 19,73 to 1,69 to 33,64 to 36,59 to 17,55 to 7,52 to 11,48 to 9,46 to 5,44 to 22\n\n";
      draw_line(50,'-');
      cout<<"\n\n\tLADDER AT POSITION\n";
      draw_line(50,'-');
      cout<<"\n\tFrom 8 to 26,21 to 82,43 to 77,50 to 91,62 to 96,66 to 87,80 to 100\n\n";
      draw_line(50,'-');
      cout<<endl;
    }
  void gamescore(char name1[],char name2[],int p1,int p2)
    {
      cout<<"\n";
      draw_line(50,'-');
      cout<<"\n\t\tGAME STATUS\n";
      draw_line(50,'-');
      cout<<"\n\t--->"<<name1<<"is at position "<<p1<<endl;
      cout<<"\n\t--->"<<name2<<"is at position "<<p2<<endl;
      draw_line(50, '_');
      cout<<endl;
    }
  void play_dice(int &score)
    {
      int dice;
      dice=random(6)+1;
      cout<<"\nYou got "<<dice<<"Point!! ";
      score=score+dice;
      cout<<"Now you are at position "<<score;
      switch(score)
	{
	  case 98:
	    score=28;
	    break;
	  case 95:
	    score=24;
	    break;
	  case 92:
	    score=51;
	    break;
	  case 73:
	    score=1;
	    break;
	  case 69:
	    score=33;
	    break;
	  case 64:
	    score=36;
	    break;
	  case 59:
	    score=17;
	    break;
	  case 55:
	    score=7;
	    break;
	  case 52:
	    score=11;
	    break;
	  case 48:
	    score=9;
	    break;
	  case 46:
	    score=5;
	    break;
	  case 44:
	    score=22;
	    break;
	  case 8:
	    score=26;
	    break;
	  case 21:
	    score=82;
	    break;
	  case 43:
	    score=77;
	    break;
	  case 50:
	    score=91;
	    break;
	  case 54:
	    score=93;
	    break;
	  case 62:
	    score=96;
	    break;
	  case 66:
	    score=87;
	    break;
	  case 80:
	    score=100;
	    break;
	}
    }