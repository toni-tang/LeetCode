class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int res = 0;
        
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });
        
        for(int i = 0; i < boxTypes.size(); i++) {
            while(boxTypes[i][0] > 0 && truckSize > 0) 
            {
                res += boxTypes[i][1];
                boxTypes[i][0]--;
                truckSize--;
            }
        }
        
        return res;
    }
};