class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int, int>> stk;
        vector<int> res(temp.size());
        
        for(int i = 0; i < temp.size(); i++) {
            while(!stk.empty() && temp[i] > stk.top().first) {
                res[stk.top().second] = i - stk.top().second;
                stk.pop();
            }
            
            stk.push(make_pair(temp[i], i));
        }
        
        return res;
    }
};