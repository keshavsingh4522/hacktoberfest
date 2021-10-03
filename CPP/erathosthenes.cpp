#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
using namespace std;
void prime_numbers(int n);
int main()
{
 int n;
 std::cout<<"Enter the number"<<std::endl;
 std::cin>>n;
 prime_numbers(n);	
}

void prime_numbers(int n)
{
 
	bool  prime[n+1];
	memset(prime,true,sizeof(prime));

	int i;
	int j;
	for(i=2;i*i<=n;i++)
	{
	
		for(j=2*i; j<=n;j=j+i)
		{
		   prime[j]=false;
		}
	}
	int count=0;
   
	cout<<"Prime numbers are"<<std::endl;

	for(int i=2;i<=sizeof(prime)-1;i++)
	{
	      

		if(prime[i]==true)
		
		{
		
		count++;
		
		std::cout<<" "<<i;
		}	
          
		
	 }
        cout<<std::endl;
	cout<<"The count of  prime numbers is "<<count<<std::endl;



}

