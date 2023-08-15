class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i < nums.size(); i++) {
            int res = target - nums[i];
            
            if(mp.find(res) != mp.end())
            {
                return { mp[res], i };
            }

            mp[nums[i]] = i;
        }
        
        return {};
    }
};