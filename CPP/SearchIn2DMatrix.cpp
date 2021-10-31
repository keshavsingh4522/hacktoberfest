#include<bits/stdc++.h>
using namespace std;

bool findInMatrix(int x, vector<vector<int>> &arr){

  int low = 0;
  int high = arr.size()-1;
  int mid;
  
  while(low <= high){
      mid = (low + high)/2;
      
      if(x >= arr[mid][0] && x <= arr[mid][arr[mid].size()]){
          for(int i = 0; i < arr[mid].size(); i++){
              if(x == arr[mid][i]){
                  // cout << "Yes" << endl;
                  // exit(0);
                  return true;
              }
          }
      }
      if(x < arr[mid][0]){
          high = mid-1;
      }
      if(x > arr[mid][arr[mid].size()]){
          low = mid+1;
      }
  }
  // cout << "No" << endl;
  return false;
}

int main(){
  int t, x, m, n;
  cin >> t;
  for(int  i = 0; i < t; i++){
    cin >> x >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    for(int a = 0; a < m; a++)
      for(int b = 0; b < n; b++){
        cin >> arr[a][b];
      }
      cout << findInMatrix(x, arr);
  }
  return 0;
}
