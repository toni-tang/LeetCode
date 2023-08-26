class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto n : nums) {
            pq.push(n);
        }
        
        int res = 0;
        while(k--) {
            res = pq.top(); pq.pop();
        }
        
        return res;
    }
};