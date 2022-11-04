class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};
        
        sort(nums.begin(), nums.end());
        
        if(nums[0] > 0) return {};
        
        unordered_map<int, int> mp;
        vector<vector<int>> res;
        
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]] = i;
        }
    
        for(int i = 0; i < nums.size()-2; i++)
        {
            if(nums[i] > 0) break;
            
            for(int j = i + 1; j < nums.size()-1; j++)
            {
                int target = -(nums[i] + nums[j]);
                
                if(mp.count(target) && mp.find(target)->second > j)
                {
                    res.push_back({nums[i], nums[j], target});
                }
                
                j = mp.find(nums[j])->second;
            }
            
            i = mp.find(nums[i])->second;
        }
        
        return res;
    }
};