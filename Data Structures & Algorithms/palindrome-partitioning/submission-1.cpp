class Solution {
    vector<vector<string>> ans;
    bool isPalindrome(string s){
        int l = 0;
        int r = s.size() - 1;

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

        string pali = "";
        for(int i=idx; i<s.size(); i++){
            pali = pali + s[i];
            if(isPalindrome(pali)){
                palis.push_back(pali);
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
