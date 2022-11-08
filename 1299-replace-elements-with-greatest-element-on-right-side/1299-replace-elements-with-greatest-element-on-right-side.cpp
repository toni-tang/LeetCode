class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> res;
        int maxNum;
        
        for(int i = 0; i < arr.size()-1; i++)
        {
            maxNum = arr[i + 1]; 
            
            for(int j = i + 1; j <= arr.size()-1; j++)
            {
                maxNum = max(maxNum, arr[j]);
            }

            res.push_back(maxNum);
        }
        res.push_back(-1);
        
        return res;
    }
};