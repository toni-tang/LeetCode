class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int n = intervals.size();
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        
        for(int i = 0; i < n; i++) {
            if(res.back()[1] >= intervals[i][0]) {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else {
                res.push_back(intervals[i]);
            }
        }
        
        return res;
    }
};