#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > generateMatrix(int A) {
    vector<vector<int> >arr;
    vector<int>ap(A);
    for(int i=0; i<A; i++) arr.push_back(ap);
    int st=0, end=A-1, stcol=0, endcol=A-1, num=1;

    if(A==1){
        arr[0][0]=1; return arr;
    }

    while(st<=end || stcol<=endcol){
        for(int i=stcol; i<=endcol; i++)
        {
            arr[st][i] = num;
            num++;
        }
        st++;
        for(int i=st; i<=end; i++)
        {
            arr[i][endcol] = num;
            num++;
        }
        endcol--;
        for(int i=endcol; i>=stcol; i--)
        {
            arr[end][i] = num;
            num++;
        }
        end--;
        for(int i=end; i>=st; i--)
        {
            arr[i][stcol] = num;
            num++;
        }
        stcol++;
    }
    return arr;
}

void print(vector<vector<int> >v)
{
	for(int i=0; i<v.size(); i++)
	{
		for(int j=0; j<v[i].size(); j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int A;
	cout<<"Enter the size of spiral matrix to be generated: ";
	cin>>A;
	print(generateMatrix(A));
}
