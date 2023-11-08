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
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'F') board[i][j] = 'O';
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int r, int c) {
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) {
            return;
        }
        
        if(board[r][c] != 'O') return;
        if(board[r][c] == 'O') board[r][c] = 'F';
        
        dfs(board, r+1, c);
        dfs(board, r-1, c);
        dfs(board, r, c+1);
        dfs(board, r, c-1);
    }
};