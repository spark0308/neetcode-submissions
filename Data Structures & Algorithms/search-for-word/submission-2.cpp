class Solution {
    bool isValidCell(int i, int j, vector<vector<bool>> visited){
        int n = visited.size();
        int m = visited[0].size();

        if(i < 0 || j < 0) return false;
        if(i >= n || j >= m) return false;

        if(visited[i][j]) return false;

        return true;
    }

    bool traverse(vector<vector<char>>& board, string word, string str, int i, int j, vector<vector<bool>>& visited, int n){
        if(!isValidCell(i, j, visited)) return false;

        visited[i][j] = true;
        str = str + board[i][j];
        n--;
        if(n == 0){
            if(str.contains(word)) return true;
            visited[i][j] = false;
            return false;
        }

        if(traverse(board, word, str, i, j-1, visited, n)) return true;
        if(traverse(board, word, str, i, j+1, visited, n)) return true;
        if(traverse(board, word, str, i-1, j, visited, n)) return true;
        if(traverse(board, word, str, i+1, j, visited, n)) return true;

        visited[i][j] = false;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                if(traverse(board, word, "", i, j, visited, word.size())) return true;
            }
        }

        return false;
    }
};
