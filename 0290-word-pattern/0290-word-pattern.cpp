class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, int> mp2;
        stringstream ss(s);
        string word;
        
        for(int i = 0; i < pattern.length(); i++) {
            ss >> word;
            
            if(mp.find(pattern[i]) == mp.end())
            {
                mp[pattern[i]] = word;
                mp2[word]++;
            }
            
            if(mp2[word] > 1 || mp.at(pattern[i]) != word) return false;
        }
        
        return (ss >> word) ? false : true;
    }
};