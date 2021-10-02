#include <stdio.h> 
#include <stdlib.h> 
  
int a[4] = { 1, 1, 0, 0 }; 
int b[4] = { 0, 1, 0, 1}; 
int i, x; 
void AND()
    {
      for (i = 0; i < 4; i++)
     {   x = a[i] * b[i]; 
        printf("\n %d AND %d = %d",a[i], b[i], x); 
      } 
    }

void OR()
{   
    for (i = 0; i < 4; i++)
    { 
         if (a[i] + b[i] > 0) 
            x = 1; 
         else
          x = 0; 
  
        printf("\n %d OR %d = %d", 
               a[i], b[i], x); 
    } 
}

void NOT()
{
    for (i = 0; i < 4; i++) 
    { 
        if (a[i] == 0) 
            x = 1; 
        else
            x = 0; 
        printf("\n  NOT %d = %d", a[i], x); 
    } 
}


main()
{   int ch;
    while(1)
    {
    printf(" \npress 1 for displaying AND gate truth table\n");
    printf(" press 2 for displaying OR gate truth table\n");
    printf(" press 3 for displaying NOT gate truth table\n");
    printf(" press 4 for exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        AND();
        break;
        case 2:
        OR();
        break;
        case 3:
        NOT();
        break;
        case 4:
        exit(0);
        break;
        
    }
}
}
