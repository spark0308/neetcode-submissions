class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        pair<int, int> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 0){
                    queue<pair<int, int>> q;
                    q.push({i,j});

                    while(!q.empty()){
                        auto [x, y] = q.front();
                        q.pop();

                        int currDis = grid[x][y];

                        for(auto [dx, dy] : dir){
                            int nx = x + dx;
                            int ny = y + dy;
                            if(nx >= grid.size() || ny >= grid[0].size() || nx < 0 || ny < 0 || grid[nx][ny] == -1) continue;

                            if(grid[nx][ny] <= currDis + 1) continue;

                            grid[nx][ny] = currDis + 1;

                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
};
