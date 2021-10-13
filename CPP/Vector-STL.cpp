#include <iostream>
#include <vector> // for using a special container called vector
#include <algorithm> // for using function `sort`

using namespace std;

// function for printing vector
void printVector(vector<int>);

int main(){
  
  // push_back example
  vector<int> myvector;
  int myint;

  cout << "Please enter some integers (enter 0 to end):\n";

  do {
    cin >> myint;
    myvector.push_back (myint);
  } while (myint);

  cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
  
  printVector(myvector);
  
  // printing vector in reverse direction
  cout << "\nPrinting numbers present in myvector in reverse direction\n";
  for(auto it = myvector.rbegin(); it != myvector.rend(); ++it) cout << (*it) << " ";
  cout << endl;
  
  // sorting vector in ascending (non - decreasing order)
  cout << "\nPrinting numbers present in myvector in ascending (non - decreasing order)\n";
  sort(myvector.begin(), myvector.end());
  printVector(myvector);
  
  // sorting vector in descending (decreasing) order
  cout << "\nPrinting numbers present in myvector in descending (decreasing) order\n";
  sort(myvector.begin(), myvector.end(), greater<int>());
  printVector(myvector);
  
  return 0;
}

// defining printVector function
void printVector(vector<int> v){
  for(auto it = v.begin(); it != v.end(); ++it) cout << (*it) << " ";
  cout << endl;
}
