class Solution {
public:
    vector<int> parent;
    int find(int x) {
        return parent[x] == x ? x : find(parent[x]);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        
        int res = 0;
        for(int i = 1; i <= n; i++) {
            int x = find(i);
            for(int j = 1; j <= n; j++) {
                if(i != j && isConnected[i-1][j-1] == 1) {
                    int y = find(j);
                    if(x != y) {
                        cout << parent[y] << " " << x << endl;
                        parent[y] = x;
                    }
                }
            }
        }
        
            for(int i = 1; i <= n; i++) {
                 if(i == find(i)) res++;
            }    
        
        return res;
    }
};