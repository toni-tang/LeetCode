class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<float> s;
        int L = 0, R = nums.size()-1;
        
        sort(nums.begin(), nums.end());
        while(L < R)
        {
            float avg = ((float)nums[L++] + (float)nums[R--]);
            s.insert(avg);
        }
        
        return s.size();
        
        //Time: O(n log n)
        //Space: O(n)
    }
};