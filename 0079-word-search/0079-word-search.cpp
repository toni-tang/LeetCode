class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        bool res = false;
    
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) return true;
                }
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int idx) {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || idx == word.size() || board[i][j] != word[idx]) {
            return false;
        }
        
        if(idx == word.size()-1) return true;
    
        board[i][j] = '@';
        
        bool res = dfs(board, word, i+1, j, idx+1) || dfs(board, word, i-1, j, idx+1) || dfs(board, word, i, j+1, idx+1) || dfs(board, word, i, j-1, idx+1);
        
        board[i][j] = word[idx];
        
        return res;
    }
};