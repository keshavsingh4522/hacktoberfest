
#include<iostream>
using namespace std;
void printMaxActivities(int s[], int f[], int n){
	int i, j;

	cout <<"Following activities are selected "<< endl;

	i = 0;
	cout <<" "<< i;


	for (j = 1; j < n; j++){
		if (s[j] >= f[i]){
			cout <<" " << j;
			i = j;
		}
	}
}
int main(){
	// int s[] = {1, 3, 0, 5, 8, 5};
	// int f[] = {2, 4, 6, 7, 9, 9};
	int n ;
	cout<<"Enter the Length ";
	cin>>n;
	int s[n];
	int f[n];
	for(int i = 0 ;i<n;i++){
		cout<<"Enter the start time";
		cin>>s[i];
	}
	for(int i = 0 ;i<n;i++){
		cout<<"Enter the Finish time";
		cin>>f[i];
	}

	// int n = sizeof(s)/sizeof(s[0]);
	printMaxActivities(s, f, n);
	return 0;
}

