class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res; //Return Array
        vector<int> temp; // Backtrack Array
        sort(nums.begin(), nums.end()); // Sort
        backtrack(res, temp, nums, 0); // Backtrack
        return res; 
    }
private:
    void backtrack(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int start) {
        res.push_back(temp); //Pushes temp onto res
        for(int i = start; i < nums.size(); i++)
        {
            temp.push_back(nums[i]); //Push numbers to array
            backtrack(res, temp, nums, i + 1); // Backtrack to get other subsets
            temp.pop_back(); //Pops last element to backtrack again
        }
    }
};