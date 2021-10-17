//A code to find e^x using taylor series
#include <iostream>
using namespace std;
// Function to find e^x
float e(float x, float n){
	static float P=1,F=1;
	if(n==0)
		return 1;
	else
		{
			float r;
			r = e(x,n-1);
			P *= x;
			F *= n;
			return r + P/F;			
			}	
}
//Driver code
int main(){
	cout<<e(4,15);
  return 0;
}
