class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int res = 0;
        int prev = intervals[0][1];
        
        for(int i = 1; i < intervals.size(); i++) {
            if(prev > intervals[i][0]) {
                prev = min(prev, intervals[i][1]);
                res++;
            } else {
                prev = intervals[i][1];
            }
        }
        
        
        return res;
    }
};