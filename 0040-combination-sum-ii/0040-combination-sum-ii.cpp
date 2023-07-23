class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
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
                if (i > start && candidates[i] == candidates[i-1]) {
                    continue;
                }
                temp.push_back(candidates[i]);
                backtrack(res, candidates, temp, target - candidates[i], i+1);
                temp.pop_back();
            }
        }
    }
};