class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> dir = {-1, 0, 1, 0, -1};
        
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        
        int steps = 0;
        while(!q.empty()) {
            ++steps;
            int s = q.size();
            while(s--) {
                pair<int, int> p = q.front(); q.pop();
                
                for(int i = 0; i < 4; i++) {
                    int r = p.first + dir[i];
                    int c = p.second + dir[i+1];
                    
                    if(r >= 0 && r < m && c >= 0 && c < n) {
                        if(grid[r][c] == 0) {
                            grid[r][c] = steps;
                            q.push({r,c});
                        }
                    }
                }
            }
        }
                 
        return steps == 1 ? -1 : steps - 1;
    }
};