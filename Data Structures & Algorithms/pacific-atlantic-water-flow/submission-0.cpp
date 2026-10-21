class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        pair<int, int> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> possibility(n, vector<int>(m, 0));

        queue<pair<int, int>> q;
        q.push({0, 0});
        possibility[0][0] += 1;
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(auto [dx, dy] : dir){
                int nx = x + dx;
                int ny = y + dy;
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(possibility[nx][ny] == 1) continue;
                if(ny != 0 && nx != 0 && heights[nx][ny] < heights[x][y] ) continue;
                possibility[nx][ny] += 1;
                q.push({nx, ny});
            }
        }

        q.push({n-1, m-1});
        possibility[n-1][m-1] += 2;
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(auto [dx, dy] : dir){
                int nx = x + dx;
                int ny = y + dy;
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(possibility[nx][ny] >= 2) continue;
                if(ny != m-1 && nx != n-1 && heights[nx][ny] < heights[x][y] ) continue;
                possibility[nx][ny] += 2;
                q.push({nx, ny});
            }
        }

        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(possibility[i][j] == 3) ans.push_back({i, j});
            }
        }

        return ans;
    }
};
