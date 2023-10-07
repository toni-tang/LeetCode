class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int res = 0;
        vector<int> prev = intervals[0];
        
        for(int i = 1; i < intervals.size(); i++) {
            if(prev[1] > intervals[i][0]) {
                prev[1] = min(prev[1], intervals[i][1]);
                res++;
            } else {
                prev = intervals[i];
            }
        }
        
        
        return res;
    }
};