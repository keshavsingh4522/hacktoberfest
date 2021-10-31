#include<bits/stdc++.h>
using namespace std;

int main()
{

	vector<int> v = {2,5,1,6,2,8,10};
	for(auto it = v.begin(); it!=v.end();it++)
	{
		cout<<(*it)<<" ";
	}

	cout<<endl;

	int N;cin>>N;
	vector<pair<int,int>> v_p;
	for(auto i=0;i<N;i++)
	{	
		int n;cin>>n;
		for(auto j=0;j<n;j++)
		{
			int x,y;cin>>x>>y;
			v_p.push_back({x,y});
		}
	}

	for(auto it=v_p.begin();it!=v_p.end();it++)
		cout<<(it->first)<<" "<<(it->second)<<"\n";
	return 0;
}