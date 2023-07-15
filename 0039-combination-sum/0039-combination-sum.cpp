class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(res, candidates, temp, target, 0);
        return res;
    }

private:
    void backtrack(vector<vector<int>>& res, vector<int>& candidates, vector<int>& temp, int target, int start) {
        if(target < 0) {
            return;
        }
        else if(target == 0) {
            res.push_back(temp);
            return;
        } 
        else {
            for(int i = start; i < candidates.size(); i++) {
                temp.push_back(candidates[i]);
                backtrack(res, candidates, temp, target - candidates[i], i);
                temp.pop_back();
            }
        }
    }
};