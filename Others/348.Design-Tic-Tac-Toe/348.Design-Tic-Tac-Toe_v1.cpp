class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        board.assign(n, vector<int>(n, 0));
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
    // time complexity: O(n)
    int move(int row, int col, int player) {
        board[row][col] = player;
        // check this row and this col
        if (isValidRow(row, player) || isValidCol(col, player)) {
            return player;
        }
        
        // check diagonal
        if (row == col && isValidDiagonal(player)) {
            return player;
        }
        
        // check anti-diagonal
        if (row == n-col-1 && isValidAntiDiagonal(player)) {
            return player;
        }
        
        return 0;
    }
    
    // check this row 
    bool isValidRow(int row, int player) {
        for (int j = 0; j < n; ++j) {
            if(board[row][j] != player) {
                return false;
            }
        }
        return true; 
    }
    
    // check this col 
    bool isValidCol(int col, int player) {
        for (int j = 0; j < n; ++j) {
            if(board[j][col] != player) {
                return false;
            }
        }
        return true; 
    }
    
    // check this diagonal 
    bool isValidDiagonal(int player) {
        for (int j = 0; j < n; ++j) {
            if(board[j][j] != player) {
                return false;
            }
        }
        return true; 
    }
    
    // check this anti-diagonal 
    bool isValidAntiDiagonal(int player) {
        for (int r = 0; r < n; ++r) {
            if(board[r][n-r-1] != player) {
                return false;
            }
        }
        return true; 
    }
    
    
    vector<vector<int>> board;
    int n;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */