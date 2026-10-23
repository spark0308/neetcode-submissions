class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> g;
        vector<int> indegree(numCourses, 0);
        queue<int> q;

        for(vector<int> prqst : prerequisites){
            g[prqst[0]].push_back(prqst[1]);
            indegree[prqst[1]]++;
        }

        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        int finish = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            finish++;
            for(int adj : g[node]){
                indegree[adj]--;
                if(indegree[adj] == 0) q.push(adj);
            }
        }

        if(numCourses == finish) return true;
        return false;
    }
};
