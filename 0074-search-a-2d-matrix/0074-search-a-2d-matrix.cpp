class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(), c = matrix[0].size();
      
        int top = 0, bot = r - 1, row = 0;
        while(top <= bot) 
        {
            row = top + (bot - top) / 2;
            if(target > matrix[row][c-1])
            {
                top = row + 1;
            }
            else if(target < matrix[row][0])
            {
                bot = row - 1;
            }
            else
            {
                break;
            }
        }
        
        int L = 0, R = c - 1;
        while(L <= R) 
        {
            int mid = L + (R - L) / 2;
            if(target > matrix[row][mid]) 
            {
                L = mid + 1;    
            }
            else if(target < matrix[row][mid])
            {
                R = mid - 1;
            }
            else 
            {
                return true;
            }
        }
        
        return false;
    }
};