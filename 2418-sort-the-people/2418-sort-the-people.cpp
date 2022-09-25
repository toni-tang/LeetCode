class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int,string> mp;
        vector<string> res;
        
        for(int i = 0; i < names.size(); i++)
        {
            mp[heights[i]] = names[i];
        }
        
        sort(heights.begin(), heights.end(), greater<int>());
        
        for(int i = 0; i < heights.size(); i++)
        {
            res.push_back(mp[heights[i]]);
        }
        
        return res;
    }
};