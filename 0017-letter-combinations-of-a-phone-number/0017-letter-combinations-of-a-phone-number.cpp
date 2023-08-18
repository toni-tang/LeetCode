class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> res;
        string temp;
        for(int i = 0; i < digits.size(); i++) {
            backtrack(digits, res, temp, i, mp);
        }
        return res;
    }
    
private:
    void backtrack(string& digits, vector<string>& res, string& temp, int start, map<char, string> mp) {
        if(temp.size() == digits.size()) {
            res.push_back(temp);
            return;
        }
        
        for(int j = 0; j < mp[digits[start]].size(); j++) {
            temp.push_back((mp[digits[start]])[j]);
            backtrack(digits, res, temp, start+1, mp);
            temp.pop_back();
        }
    }
};