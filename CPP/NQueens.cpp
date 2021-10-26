#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> result;
bool isPossibleToPlace(vector<vector<int>> &board, int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1)
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }
    for (int j = col, i = row; j >= 0 && i < board.size(); i++, j--) {
        if (board[i][j] == 1)
            return false;
    }
    return true;
}

bool solveNQueenUntil(vector<vector<int>> &board, int col) {
    int n = board.size();
    if (col == n) {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1)
                    v.push_back(make_pair(i, j));
            }
        }
        result.push_back(v);
        return true;
    }
    bool result = false;
    for (int i = 0; i < n; i++) {
        if (isPossibleToPlace(board, i, col)) {
            //marking place as 1 to track further
            board[i][col] = 1;
            // recurrsively calling solveNQueenUntil function to check path
            result = solveNQueenUntil(board, col + 1) || result;
            //backtracking by setting current element again to 0.
            board[i][col] = 0;
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (solveNQueenUntil(board, 0)) {
        sort(result.begin(), result.end());
        for (auto vec : result) {
            sort(vec.begin(), vec.end());
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (binary_search(vec.begin(), vec.end(), make_pair(i, j)))
                        cout << "1 ";
                    else
                        cout << "0 ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}
