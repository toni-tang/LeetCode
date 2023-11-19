class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> degrees(numCourses, 0);
        
        for(auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            degrees[edge[0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            cout << degrees[i] << " ";
            if(degrees[i] == 0) {
                q.push(i);
                n--;
            }
        }
        
        while(!q.empty()) {
            int curr = q.front(); q.pop();
            
            for(auto& neighbor : adj[curr]) {
                degrees[neighbor]--;
                if(degrees[neighbor] == 0) {
                    q.push(neighbor);
                    n--;
                }
            }
        }
        
        return n == 0;
    }
};