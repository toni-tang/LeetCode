class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        
        for(int i = 0; i < r; i++) {
            dfs(board, i, 0);
            dfs(board, i, c-1);
        }
        
        for(int i = 0; i < c; i++) {
            dfs(board, 0, i);
            dfs(board, r-1, i);
        }
        
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(board[i][j] == 'F') {
                    board[i][j] = 'O';
                }
                else {
                    if(board[i][j] == 'O') {
                        board[i][j] = 'X';
                    }
                }
            }
        }
        
    }
private:
    void dfs(vector<vector<char>>& board, int i, int j) {
        if(i < 0 || j < 0 || i > board.size()-1 || j > board[0].size()-1) {
            return;
        }
        
        if(board[i][j] != 'O') return;
        
        board[i][j] = 'F';
        
        dfs(board, i+1, j);
        dfs(board, i-1, j);
        dfs(board, i, j+1);
        dfs(board, i, j-1);
    }
};