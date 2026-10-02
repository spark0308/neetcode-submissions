class Solution {
    bool isValidPlacement(int x, int y, vector<string> chessboard){
        for(int i=x-1; i>=0; i--){
            if(chessboard[i][y] == 'Q') return false;
            if(chessboard[i][y-(x-i)] == 'Q') return false;
            if(chessboard[i][y+(x-i)] == 'Q') return false;
         }

         return true;
    }

    vector<vector<string>> ans;
    void settleQueens(int& n, int idx, vector<string>& chessboard){
        if(idx == n){
            ans.push_back(chessboard);
            return;
        }

        for(int i=0; i<n; i++){
            if(!isValidPlacement(idx, i, chessboard)) continue;
            chessboard.push_back(string(i, '.') + 'Q' + string(n-i-1, '.'));
            settleQueens(n, idx+1, chessboard);
            chessboard.pop_back();
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard;

        settleQueens(n, 0, chessboard);

        return ans;
    }
};
