class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        queue<int> q;

        for(vector<int> edge : edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n);

        int ans = 0;

        for(int i=0; i<n; i++){
            if(visited[i]) continue;

            q.push(i);
            visited[i] = true;
            ans++;

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(int adj : g[node]){
                    if(visited[adj]) continue;

                    q.push(adj);
                    visited[adj] = true;
                }
            }
        }

        return ans;

    }
};
