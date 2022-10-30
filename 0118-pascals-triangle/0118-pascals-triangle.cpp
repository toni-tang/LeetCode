class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res; //Initalize 2D array
        
        for(int i = 0; i < numRows; i++) {
            res.push_back(vector<int>(i+1,1)); // Push an array of size i+1 with values of all 1's
            for(int j = 1; j < i; j++) // Loop through previous array
                res[i][j] = res[i-1][j-1] + res[i-1][j]; // Add pairs of numbers from previous array
        }

        return res;
    }
};