class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int minAb = INT_MAX;
        vector<vector<int>> res;
        
        for(int i = 0; i < arr.size()-1; i++) 
        {
             minAb = min(abs(arr[i]-arr[i+1]), minAb);
        }
        
        for(int i = 0; i < arr.size()-1; i++) 
        {
            if(abs(arr[i]-arr[i+1]) == minAb)
            {
                res.push_back({ arr[i], arr[i+1] });
            }    
        }
        
        return res;
    }
};