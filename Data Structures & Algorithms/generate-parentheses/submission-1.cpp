class Solution {
    vector<string> paranthesis;
    void backtrack(int n, string s, int open, int close){
        if(open < close) return;
        if(n == 0){
            if(open == close) paranthesis.push_back(s);
            return;
        }

        backtrack(n-1, s + "(", open+1, close);
        backtrack(n-1, s + ")", open, close +1);
    }
public:
    vector<string> generateParenthesis(int n) {
        backtrack(2*n, "", 0, 0);

        return paranthesis;
    }
};
