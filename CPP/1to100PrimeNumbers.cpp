#include <iostream>
using namespace std;
///Main Function
int main()
{
     int i,j,count=0;

      //Print prime number between 1 to 100
      cout<<"print prime number between 1 to 100\n";

      //For loop for printing values between 1 to 100
         for(i=2;i<=100;i++)
           {
             for(j=1;j<=i;j++)
               {
                   if(i%j==0)
                   count++;

               }
            if(count==2)
          cout<<" "<<i;
        count=0;
           }
return 0;
}