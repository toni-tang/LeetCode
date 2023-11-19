class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> s;
        unordered_map<int, int> mp;
        
        for(auto& n : nums) {
            mp[n]++;
            s.insert(n);
        }
        
        priority_queue<int> pq(s.begin(), s.end());
        
        int res = 0;
        while(pq.size() != 1) {
            int curr = pq.top(); pq.pop();
            mp[pq.top()] += mp[curr];
            res += mp[curr];
        }
        
        return res;
    }
};