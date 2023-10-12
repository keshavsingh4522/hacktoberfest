class Solution {
    public void solveSudoku(char[][] board) {
        backtrack(board, 0, 0);
    }

        boolean backtrack(char[][] board, int i, int j) {
        int m = 9, n = 9;
        if (j == n) {
            
            return backtrack(board, i + 1, 0);
        }
        if (i == m) {
            
            return true;
        }

        if (board[i][j] != '.') {
            
            return backtrack(board, i, j + 1);
        } 

        for (char ch = '1'; ch <= '9'; ch++) {
            
            if (!isValid(board, i, j, ch))
                continue;
            
            board[i][j] = ch;
            
            if (backtrack(board, i, j + 1)) {
                return true;
            }
            board[i][j] = '.';
        }
        
        return false;
    }

    boolean isValid(char[][] board, int r, int c, char n) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == n) return false;
            if (board[i][c] == n) return false;
            if (board[(r/3)*3 + i/3][(c/3)*3 + i%3] == n)
                return false;
        }
        return true;
    }
}
