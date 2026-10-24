class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> g;
        vector<bool> visited(n, false);
        queue<int> q;
        int visitedCount = 0;

        for(vector<int> edge : edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        q.push(0);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            visited[node] = true;
            visitedCount++;

            for(int adj : g[node]){
                if(visited[adj]) continue;
                q.push(adj);
            }
        }
        
        // cout<<n<<" "<<visitedCount<<endl;
        if(n == visitedCount) return true;
        return false;
    }
};
