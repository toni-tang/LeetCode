class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0; // Edge case
        sort(intervals.begin(), intervals.end()); // Sort intervals by starting value
        int res = 0; // Keeps tracks of removals
        int prev = intervals[0][1]; // Keeps track of previous end point;
        
        for(int i = 1; i < intervals.size(); i++) {
            if(prev > intervals[i][0]) { // Check if intervals are overlapping
                prev = min(prev, intervals[i][1]); // Take the one with the smallest value because it has a less chance of overlapping with another interval;
                res++; // Increment removal
            } else {
                prev = intervals[i][1]; // Else update to next interval if no overlap
            }
        }
        
        
        return res;
    }
};