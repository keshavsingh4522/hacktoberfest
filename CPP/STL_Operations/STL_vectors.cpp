#include<bits/stdc++.h>
using namespace std;

//vector is a dynamic array i.e, the size of the vector can be changed
//according to the input or not...
void printVector(vector<int> v)
{
	cout<<v.size()<<"\n";
	for(int i=0;i<v.size();++i)
		cout<<v[i]<<" ";
}

int main()
{
	//basic syntac of a vector
	vector<int> v; //int-data type, v-name of the vector;
	int n; cin>>n; 
	for(int i=1;i<=n;++i)
		v.push_back(i);
	
	printVector(v);

	return 0;
}