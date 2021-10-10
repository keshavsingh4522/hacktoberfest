#include <iostream>  
using namespace std;  
int main()  
{  
  int n, i, flag=0;  
  cout << "Enter the Number to check Prime: ";  
  cin >> n;    
  for(i = 2; i <= n; i++)  
  {  
    if(n % i == 0)  
    {  
      cout<<"Number is not Prime."<<endl;  
      flag=1;  
      break;  
    }  
  }  
  if (flag==0)  
  cout << "Number is Prime."<<endl;  
  return 0;  
}  
