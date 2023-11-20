class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int res = 0;
        int n = garbage.size();
        vector<pair<int, int>> countLastSeen(3, {0, 0});
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < garbage[i].size(); j++) {
                switch(garbage[i][j]) {
                    case 'G':
                        countLastSeen[0] = {i, countLastSeen[0].second+1};
                        break;
                    case 'P':
                        countLastSeen[1] = {i, countLastSeen[1].second+1};
                        break;
                     case 'M':
                        countLastSeen[2] = {i, countLastSeen[2].second+1};
                        break;
                }
            }
        }
        
        for(int i = 0; i < 3; i++) {
            res += countLastSeen[i].second;
            for(int j = 0; j < countLastSeen[i].first; j++) {
                res += travel[j];
            }
        }
        
        return res;
    }
};