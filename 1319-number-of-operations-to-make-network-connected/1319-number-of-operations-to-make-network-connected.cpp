class Solution {
public:
    vector<int> parent;
    int find(int x) {
        return parent[x] == x ? x : find(parent[x]);
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        
        parent.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        int redundant = 0;
        int groups = 0;
        for(int i = 0; i < m; i++) {
            int x = find(connections[i][0]);
            int y = find(connections[i][1]);
            if(x != y) {
                parent[y] = x;
            }
            else {
                redundant++;
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(i == find(i)) groups++;
        }
        
        cout << redundant << " " << groups << endl;
        
        return redundant >= groups-1 ? groups - 1 : -1;
    }
};