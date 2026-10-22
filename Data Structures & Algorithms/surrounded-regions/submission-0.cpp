class Solution {
public:
    void solve(vector<vector<char>>& board) {
        pair<int, int> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> q;

        int n=board.size();
        int m=board[0].size();
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O'){
                board[i][0] = '#';
                q.push({i, 0});
            }
            if(board[i][m-1] == 'O'){
                board[i][m-1] = '#';
                q.push({i, m-1});
            }
        }
        for(int i=0; i<m; i++){
            if(board[0][i] == 'O'){
                board[0][i] = '#';
                q.push({0, i});
            }
            if(board[n-1][i] == 'O'){
                board[n-1][i] = '#';
                q.push({n-1, i});
            }
        }

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(auto [dx, dy] : dir){
                int nx = x + dx;
                int ny = y + dy;

                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(board[nx][ny] == 'X' || board[nx][ny] == '#') continue;

                board[nx][ny] = '#';
                q.push({nx, ny});
            }
        }


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
        
    }
};
