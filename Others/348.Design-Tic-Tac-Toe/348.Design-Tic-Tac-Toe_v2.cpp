class TicTacToe {
public:
    
    vector<int> rows, cols;
    int n;
    int diagonal = 0, antiDiagonal = 0;
    
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows.assign(n, 0);
        cols.assign(n, 0);
        this->n = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (player == 1) {
            rows[row] += 1;
            cols[col] += 1;
            if (row == col) diagonal++;
            if (row == n-col-1) antiDiagonal++;
        } else if (player == 2) {
            rows[row] -= 1;
            cols[col] -= 1;
            if (row == col) diagonal--;
            if (row == n-col-1) antiDiagonal--;
        }
        if (rows[row] == n || rows[row] == -n || cols[col] == n || cols[col] == -n 
            || diagonal == n || diagonal == -n || antiDiagonal == n || antiDiagonal == -n) {
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */