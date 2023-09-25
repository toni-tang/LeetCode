class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int m = tri.size();
        for(int i = 1; i < m; i++) {
            int n = tri[i].size();
            for(int j = 0; j < n; j++) {
                if(0 < j && j < n-1) {
                    tri[i][j] = min(tri[i-1][j], tri[i-1][j-1]) + tri[i][j];
                }
                else if(j == 0) {
                    tri[i][j] = tri[i-1][j] + tri[i][j];
                }
                else if (j == n-1) {
                    tri[i][j] = tri[i-1][j-1] + tri[i][j];
                }
            }
        }
        
        int res = INT_MAX;
        
        for(int j = 0; j < tri[m-1].size(); j++) {
            res = min(res, tri[m-1][j]);
        }
        
        return res;
    }
};