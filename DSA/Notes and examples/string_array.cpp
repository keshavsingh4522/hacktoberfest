#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str[20];
	int n;	
	cin>>n;
	cin.get();
	
	for(int i=0;i<n;i++)
	getline(cin,str[i]);
	
	//sorting string
	
	sort(str,str+n);
	
	for(int i=0;i<n;i++)
	cout<<str[i]<<endl;
	return 0;
}
