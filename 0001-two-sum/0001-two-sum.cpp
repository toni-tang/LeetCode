class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i < nums.size(); i++) {
            int res = target - nums[i];
            
            for(int i = 0; i < nums.size(); i++) 
            {
                int numToFind = target - nums[i];

                if(mp.find(numToFind) != mp.end())
                {
                    return { mp[numToFind], i };
                }

                mp[nums[i]] = i;
            }
        }
        
        return {};
    }
};