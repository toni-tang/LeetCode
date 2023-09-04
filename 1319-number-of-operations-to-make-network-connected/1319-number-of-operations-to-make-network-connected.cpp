class Solution {
public:
    void dfs(vector<bool>& visited, vector<vector<int>>& adj, int i) {
        visited[i] = true;
        for(auto j : adj[i]) {
            if(!visited[j]) {
                dfs(visited, adj, j);
            } 
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {  
        if(connections.size() < n-1) {
            return -1;
        }
        
        vector<vector<int>> adj(n);
        for(auto v : connections) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
       
        int groups = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(visited, adj, i);
                groups++;
            }
        }
        
        return groups - 1;
    }
};