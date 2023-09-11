class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        vector<vector<int>> res;
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(dfsA(heights, i, j, heights[i][j]) && dfsP(heights, i, j, heights[i][j])) {
                    res.push_back({i, j});
                }
            }
        }
        
        return res;
    }
private:
    bool dfsA(vector<vector<int>>& heights, int i, int j, int prev) {
        if(i < 0 || j < 0 || i > heights.size()-1 || j > heights[0].size()-1 || heights[i][j] > prev || heights[i][j] == -1) {
            return false;
        }
        
        if(i == heights.size()-1 && j >= 0 && j <= heights[0].size()-1) {
            return true;
        }
        
        if(j == heights[0].size()-1 && i >= 0 && i <= heights.size()-1) {
            return true;
        }
        
        int val = heights[i][j];
        heights[i][j] = -1;
        
        bool res = dfsA(heights, i+1, j, val) || dfsA(heights, i, j+1, val) || dfsA(heights, i-1, j, val) || dfsA(heights, i, j-1, val);
        
        heights[i][j] = val;
        
        return res;
    }
    
    bool dfsP(vector<vector<int>>& heights, int i, int j, int prev) {
        if(i < 0 || j < 0 || i > heights.size()-1 || j > heights[0].size()-1 || heights[i][j] > prev || heights[i][j] == -1) {
            return false;
        }
        
        if(i == 0 && j >= 0 && j <= heights[0].size()-1) {
            return true;
        }
        
        if(j == 0 && i >= 0 && i <= heights.size()-1) {
            return true;
        }
        
        int val = heights[i][j];
        heights[i][j] = -1;
      
        bool res = dfsP(heights, i+1, j, val) || dfsP(heights, i, j+1, val) || dfsP(heights, i-1, j, val) || dfsP(heights, i, j-1, val);
        
        heights[i][j] = val;
        
        return res;
    }
};