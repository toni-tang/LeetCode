class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        dfs(rooms, 0, visited);
        
        for(const auto& visit : visited) {
            if(!visit) return false;
        }
        
        return true;
    }
private:
    void dfs(vector<vector<int>>& rooms, int key, vector<bool>& visited) {
        if(visited[key]) return;
        
        visited[key] = true;
        
        for(int i = 0; i < rooms[key].size(); i++) {
            dfs(rooms, rooms[key][i], visited);
        }
    }
};