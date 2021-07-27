### 863.All-Nodes-Distance-K-in-Binary-Tree

题目链接： [link](https://leetcode.com/problems/design-tic-tac-toe/)

思路：

**Solution 1**

解法1: move操作为O(n)的解法， 当每次落子的时候，去检查当前行，当前列，以及两条对角线

<details>
<summary>solution</summary>

```C++
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
```

</details>


**Solution 2**

解法2: move操作为O(1)的解法， 我们需要给每行/每列/每个对角线做一个计数器。如果是 player1 落子，那么这行/列/对角线加1，反之，如果是 player2 落子，这行/这列/这个对角线 -1.

如果每次 move 以后，有行/列/对角线的计数器达到 n 或者 -n，说明有人获胜。


<details>
<summary>solution</summary>

```C++
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
```

</details>