#include<iostream> 
#include<vector>
#include<climits> 

using namespace std; 
  
int kadane(vector<int> &a) 
{ 
	int n=a.size(),msf=INT_MIN,meh=0;
  	
  	for(int i=0;i<n;i++)
  	{
  		meh+=a[i];
  		if(msf<meh)
  			msf=meh;
  		if(meh<0)
  			meh=0;
  	}
  	return msf; 
} 

int main() 
{ 
	cout<<"\nEnter the size of the array : ";
	int n;
	cin>>n;
	cout<<"\nEnter the elements of the array : ";
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	int ans=kadane(a);
	cout<<"\nMaximum Sub-array sum found in the array is : "<<ans<<endl;

	return 0;
}
