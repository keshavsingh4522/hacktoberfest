#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> possibility(18, vector<int>(18, 0));
void findPathForRat(vector<vector<int>> &v, int row, int col) {
    int n = v.size();
    if (row == n - 1 && col == n - 1) {
        // arrived to last position
        possibility[row][col] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << possibility[i][j] << " ";
        }
        cout << endl;
        //backtracking again
        possibility[row][col] = 0;
        return;
    }
    // checking for invalid indices or if path is possible or not i.e. value is 0 then return 
    //and if it is marked as possible then we again reached at that position.
    //so to avoid time for visiting node again I return from here
    if (row == -1 || row == n || col == -1 || col == n || v[row][col] == 0 || possibility[row][col] == 1) {
        return;
    }
    possibility[row][col] = 1;
    // mark position as possible
    // go in up, down, left and right direction
    findPathForRat(v, row - 1, col);
    findPathForRat(v, row + 1, col);
    findPathForRat(v, row, col - 1);
    findPathForRat(v, row, col + 1);
    // after exploring all directions mark position as 0 and start backtracking
    possibility[row][col] = 0;
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    }
    // starting from first position
    findPathForRat(v, 0, 0);
    return 0;
}
