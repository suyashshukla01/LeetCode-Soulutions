class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char ch) {

        for (int j = 0; j < 9; j++) {
            if (board[row][j] == ch)
                return false;
        }

        for (int i = 0; i < 9; i++) {
            if (board[i][col] == ch)
                return false;
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == ch)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board, int row, int col) {

        if (row == 9)
            return true;

        if (col == 9)
            return solve(board, row + 1, 0);

        if (board[row][col] != '.')
            return solve(board, row, col + 1);

        for (char ch = '1'; ch <= '9'; ch++) {

            if (isSafe(board, row, col, ch)) {

                board[row][col] = ch;

                if (solve(board, row, col + 1))
                    return true;

                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};