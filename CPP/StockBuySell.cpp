#include <bits/stdc++.h> 
using namespace std;  
void stockBuySell(int price[], int n) 
{ 
	
	if (n == 1) 
		return; 
	int i = 0, profit = 0;
	while (i < n - 1) 
    { 
		while ((i < n - 1) && (price[i + 1] <= price[i])) 
			i++; 
		if (i == n - 1) 
			break; 
		int buy = i++; 
        profit -= price[buy];
		while ((i < n) && (price[i] >= price[i - 1])) 
			i++; 
		int sell = i - 1; 
        profit += price[sell];
		cout << "Buy on day: " << buy 
			<< "\t Sell on day: " << sell << endl; 
	} 
    cout<<"\nPROFIT: "<<profit;
} 
int main() 
{ 
	int n;
    cin>>n;
    int *price = new int[n];
    for(int i = 0; i < n; ++i)
        cin>>price[i]; 
	stockBuySell(price, n); 
    delete []price;
	return 0; 
} 

