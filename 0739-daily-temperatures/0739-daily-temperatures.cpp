class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> res(n);
        
        for(int i = temp.size() - 1 ; i >= 0 ; i--)
        {
            int j = i + 1;
            while(j < temp.size() && temp[j] <= temp[i])
            {
                if(res[j] > 0) j = res[j] + j;
                else j = temp.size();
            }       
            
            if(j < temp.size()) res[i] = j - i;
        } 
        
        return res;
    }
};