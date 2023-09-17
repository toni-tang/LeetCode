class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, -1));
        vector<int> dir = {-1, 0, 1, 0, -1};
        queue<pair<int, int>> q;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    q.push({i,j}); 
                    res[i][j] = 0;
                } 
            }
        }
        
        while(!q.empty()) {
            pair<int, int> curr = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int r = curr.first + dir[i];
                int c = curr.second + dir[i+1];
                if(r >= 0 && r < m && c >= 0 && c < n && res[r][c] == -1) {
                    q.push({r, c});
                    res[r][c] = res[curr.first][curr.second] + 1;
                }
            }  
        }
        
        return res;
    }
};