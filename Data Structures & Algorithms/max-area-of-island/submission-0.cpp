class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int maxAreaOfIsland = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    queue<pair<int, int>> q;
                    
                    int area = 0;
                    q.push({i, j});
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;

                        q.pop();

                        if(grid[x][y] == 0 || visited[x][y]) continue;

                        visited[x][y] = true;
                        area++;

                        if(x+1 < n) q.push({x+1, y});
                        if(x-1 >= 0) q.push({x-1, y});
                        if(y+1 < m) q.push({x, y+1});
                        if(y-1 >= 0) q.push({x, y-1});
                    }

                    maxAreaOfIsland = max(maxAreaOfIsland, area);
                }
            }
        }

        return maxAreaOfIsland;
    }
};
