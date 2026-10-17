class Solution {
    int ans;
    vector<vector<bool>> visited;
    void markIslandVisited(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0 || i >= grid.size() || j >= grid[0].size()) return;

        if(grid[i][j] == '0') return;
        if(visited[i][j]) return;

        visited[i][j] = true;

        markIslandVisited(grid, i+1, j);
        markIslandVisited(grid, i-1, j);
        markIslandVisited(grid, i, j+1);
        markIslandVisited(grid, i, j-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        visited.assign(n, vector<bool>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && visited[i][j] == false){
                    ans++;
                    markIslandVisited(grid, i, j);
                }
            }
        }

        return ans;
    }
};
