class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0;
        int i;
        
        for(auto n : nums)
        {
            mp[n]++;
        }
        
        for(auto n : nums) 
        {
            if(mp.find(n-1) == mp.end())
            {
                for(i = n; mp.find(i) != mp.end(); i++);
                res = max(res, i - n);
            }
        }
        
        return res;
    }
};