class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        
        for(auto str : strs) 
        {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            
            if(mp.find(sorted) == mp.end()) 
            {
                vector<string> arr;
                arr.push_back(str);
                mp[sorted] = arr;
            }
            else
            {
                mp.at(sorted).push_back(str);
            }
            
        }
        
        for(auto it : mp)
        {
            res.push_back(it.second);
        }  
        
        return res;         
    }
};