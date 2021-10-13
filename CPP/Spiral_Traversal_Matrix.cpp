// Spiral Traversal of a Matrix.

#include <bits/stdc++.h>
using namespace std;

void inti_code() {
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
}

vector<int> spiral_traverse(vector<vector<int>> &matrix) {
	vector<int> vec;

	int row = matrix.size();
	int column = matrix[0].size();

	int top = 0, down = row - 1, left = 0, right = column - 1, i;

	int dir = 0;
	while (top <= down && left <= right)
	{
		if (dir == 0) {
			for (i = left; i <= right; i++)
				vec.push_back(matrix[top][i]);
			top++;
		} else if (dir == 1) {
			for (i = top; i <= down; i++)
				vec.push_back(matrix[i][right]);
			right--;

		} else if (dir == 2) {
			for (i = right; i >= left; i--)
				vec.push_back(matrix[down][i]);
			down--;

		} else if (dir == 3) {
			for (i = down; i >= top; i--)
				vec.push_back(matrix[i][left]);
			left++;
		}
		dir = (dir + 1) % 4;
	}
	return vec;
}

void print_matrix(vector<vector<int>> &matrix) {

	for (vector<int> one_dim : matrix) {
		for (int val : one_dim) {
			cout << setw(2) << val << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

int main() {
	inti_code();

	int r; cin >> r;
	int c; cin >> c;

	vector<vector<int>> matrix(r, vector<int>(c));  // 2D Array

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> matrix[i][j];
		}
	}

	print_matrix(matrix);

	vector<int> vec = spiral_traverse(matrix);

	cout << "Spiral Traversal : \n";
	for (int val : vec)
		cout << val << " ";

	return 0;
}
