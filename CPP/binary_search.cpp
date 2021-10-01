// Program to search for a given a number in a sorted vector using binary search
#include <iostream>
#include <vector>

using namespace std;

// Where n is the number you want to find and arr is the vector you search in
int bin_search(int n, vector<int>vec){
    // L and R will be the boundaries of the search
    int L = 0;
    int R = vec.size() - 1 / 2;
    
    while(L <= R){
        // half will be the floor of L + R / 2
        int half =  (L + R) / 2;

        if(vec[half] < n){
            L = half + 1;
        }

        else if(vec[half] > n) {
            R = half - 1;
        }

        else{
            return half;
        }
    }

    // the function returns -1 if the number is not present in the vector
    return -1;
}

int main() {
    vector<int> test_vec = {1, 4, 7, 10, 12, 15};
    int test_number;
    cin >> test_number;
    cout << bin_search(test_number, test_vec);
}