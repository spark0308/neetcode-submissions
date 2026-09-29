class Solution {
    vector<vector<string>> ans;
    bool isPalindrome(string s, int l, int r){
        while(l<=r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }

        return true;
    }

    void backtrack(string& s, int idx, vector<string>& palis){
        if(idx >= s.size()){
            ans.push_back(palis);
            return;
        }
        for(int i=idx; i<s.size(); i++){
            if(isPalindrome(s, idx, i)){
                palis.push_back(s.substr(idx, i-idx+1));
                backtrack(s, i+1, palis);
                palis.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> palis;
        backtrack(s, 0, palis);

        return ans;
    }
};
