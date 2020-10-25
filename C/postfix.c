// @Agarwal-Kritik
// Postfix Evaluation Using C

#include <stdio.h>
#define size = 50
int s[size];
int top = -1;
push(int elem)
{
      s[++top] = elem;
}
int pop()
{
      return (s[top--]);
}
void main()
{
      char P[50], c;
      int i = 0, OP1, OP2;
      printf("\nEnter the Postfix Expression : ");
      scanf(" %s", P);
      while ((ch = P[i++]) != ' ')
      {
            if (isdigit(ch))
                  s[++top] = (ch -‘0’);
            else
            {
                  op2 = pop();
                  op1 = pop();
                  switch (ch)
                  {
                  case '+':
                        s[++top] = (op1 + op2);
                        break;
                  case '-':
                        s[++top] = (op1 - op2);
                        break;
                  case '*':
                        s[++top] = (op1 * op2);
                        break;
                  case '/':
                        push(op1 / op2);
                        break;
                  }
            }
      }
      printf("\n Given Postfix Expn: %s", pofx);
      printf("\n Result after Evaluation: %d", s[top]);
}