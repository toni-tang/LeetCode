class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res = INT_MAX;
        
        if(matrix[0].size() == 1) {
            for(auto n : matrix[0]) {
                res = min(res, n);
            }
            
            return res;
        }
        
        for(int r = 1; r < matrix.size(); r++) {
            for(int c = 0; c < matrix[r].size(); c++) {
                if(c > 0 && c < matrix[r].size()-1) {
                    matrix[r][c] += min(matrix[r-1][c-1], min(matrix[r-1][c], matrix[r-1][c+1]));
                }
                else if(c == 0) {
                    matrix[r][c] += min(matrix[r-1][c], matrix[r-1][c+1]);
                }
                else if(c == matrix[r].size()-1) {
                    matrix[r][c] += min(matrix[r-1][c-1], matrix[r-1][c]);
                }
            }
        }
        
        for(auto n : matrix[matrix.size()-1]) {
            res = min(res, n);
        }
        
        return res;
        
        // Time: O(3*m*n);
        // Space: O(1);
    }

};