#include<bits/stdc++.h>
using namespace std;

void sum(int ind,vector<string> &ds,vector<string> &arr,int n,vector<vector<string>>&ans )
{

	ans.push_back(ds);
	for(int i=ind;i<arr.size();i++){
	ds.push_back(arr[i]);
	sum(i+1,ds,arr,n,ans);
	ds.pop_back();

	}
	
}
int main()
{
	int n,rank;
	cin>>n>>rank;
	string str;
	cin>>str;
	vector<string> arr;
    stringstream ss(str);
 
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        arr.push_back(substr);
    }
    // for(auto it:arr)
    // 	cout<<it<<" ";
	int count=0;
	vector<string > ds;
	vector<vector<string>>ans;
	sum(0,ds,arr,n,ans);
	for(auto it:ans)
	{
		for(auto s:it)
			cout<<s<<" ";
		cout<<endl;
	}
	
}