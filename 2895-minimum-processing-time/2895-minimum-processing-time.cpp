class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        sort(processorTime.begin(), processorTime.end(), greater<int>());
        
        int res = 0;
        for(int i = 0; i < tasks.size(); i++) {
            res = max(res, tasks[i] + processorTime[i/4]);
        }
        
        return res;
    }
};