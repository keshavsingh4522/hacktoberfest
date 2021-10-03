#include<bits/stdc++.h>
using namespace std;

class Knapsack_G 
{
    public:
    double weight[3];
    double benefit[3];
    double ratio[3];
    double W;
    Knapsack_G() 
    {   int nItems;
    	cout<<"Enter the number of objects: ";
    	cin>>nItems;
    	cout<<"Enter the object's weights\n";
    	for (int i = 0; i<nItems; ++i) 
    		cin>>weight[i];
    	cout<<"Enter the object's profits\n";
    	for (int i = 0; i<nItems; ++i) 
    		cin>>benefit[i];
    	for (int i = 0; i<nItems; ++i) 
    		ratio[i] = (double)benefit[i] / weight[i]; 
    	cout<<"Enter the Capacity of the knapsack: ";
    	cin>>W;
    	cout<<"All values are taken\n";
    	for (int i = 0; i<nItems; ++i) 
    		cout<<"Weight"<<i+1<<" "<<weight[i]<<" "<<"benefit"<<i+1<<" "<<benefit[i]<<" "<<"ratio"<<i+1<<" "<<ratio[i]<<" "<<endl;
        cout<<"capacity "<<W<<endl;
    }

    int getNext()
    {
    	double highest = 0;
    	int index = -1;
    	for (int i = 0; i<(sizeof(benefit)/sizeof(benefit[0])); ++i) 
    	{
    		if (ratio[i] >highest) 
    		{
    			highest = ratio[i];
    			index = i;      
    		}
    	} 
    	return index;
    }
    
    void fill()
    {
    	double cW = 0; //current weight
    	double cB = 0; //current benefit 
    	cout<<"\n Objects  considered: ";
    	while (cW<W) 
    	{
    		int item = getNext();        //next highest ratio
    		if (item == -1) {
    			//No items left
    			break;
            }
        	cout<<(item+1)<<" ";
        	if (cW + weight[item] <= W)
    		{
    		    cW += weight[item];
        		cB += benefit[item];
        		//mark as used for the getNext() (ratio) function
    			ratio[item] = 0;
            }
    		else 
            {
        		cB += (ratio[item] * (W - cW));
        		cW += (W - cW);
        		break;  //the knapsack is full
            }
        }
    	cout<<"\nThe Optimal Solution i.e. Max Benefit = " << cB ;
    }
};


int main() {
		Knapsack_G fk;
		fk.fill();
}
