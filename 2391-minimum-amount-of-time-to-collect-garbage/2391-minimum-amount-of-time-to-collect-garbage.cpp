class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int res = 0;
        int n = garbage.size();
        vector<int> lastSeen(3, 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < garbage[i].size(); j++) {
                switch(garbage[i][j]) {
                    case 'G':
                        lastSeen[0] = i;
                        break;
                    case 'P':
                        lastSeen[1] = i;
                        break;
                     case 'M':
                        lastSeen[2] = i;
                        break;
                }
                res++;
            }
        }
        
        for(int i = 1; i < travel.size(); i++) {
            travel[i] += travel[i-1];
        }
        
        
        for(int i = 0; i < 3; i++) {
            if(lastSeen[i] > 0) res += travel[lastSeen[i]-1];
        }
        
        return res;
    }
};