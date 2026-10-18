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
                    visited[i][j] = true;
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;

                        q.pop();

                        // visited[x][y] = true;
                        area++;

                        if(x+1 < n && grid[x+1][y] == 1 && !visited[x+1][y]){q.push({x+1, y}); visited[x+1][y] = true; }
                        if(x-1 >= 0 && grid[x-1][y] == 1 && !visited[x-1][y]){ q.push({x-1, y}); visited[x-1][y] = true; }
                        if(y+1 < m && grid[x][y+1] == 1 && !visited[x][y+1]){ q.push({x, y+1}); visited[x][y+1] = true; }
                        if(y-1 >= 0 && grid[x][y-1] == 1 && !visited[x][y-1]){ q.push({x, y-1}); visited[x][y-1] = true; }
                    }

                    maxAreaOfIsland = max(maxAreaOfIsland, area);
                }
            }
        }

        return maxAreaOfIsland;
    }
};
