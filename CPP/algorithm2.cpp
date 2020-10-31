//@sidhartha8011
// c++ program for binary search Using STL
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int i, size, key;
	vector<int> arr;
	cout << "enter the size of the array";
	cin >> size;
	arr.resize(size);
	cout << "enter the elements of the array";
	for (i = 0;i < size;i++)
		cin >> arr[i];
	cout << "enter a element to search";
	cin >> key;
	sort(arr.begin(), arr.end());
	if (binary_search(arr.begin(), arr.end(), key))
		cout << "found";
	else
		cout << "not found";
	return 0;
}