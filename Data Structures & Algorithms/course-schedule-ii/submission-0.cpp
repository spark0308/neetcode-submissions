class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> g;
        vector<int> indegree(numCourses);
        queue<int> q;
        vector<int> topoOrder;

        for(vector<int> pre : prerequisites){
            g[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            topoOrder.push_back(node);

            for(int adj : g[node]){
                indegree[adj]--;
                if(indegree[adj] == 0) q.push(adj);
            }
        }

        if (numCourses == topoOrder.size()) return topoOrder;

        return {};
    }
};
