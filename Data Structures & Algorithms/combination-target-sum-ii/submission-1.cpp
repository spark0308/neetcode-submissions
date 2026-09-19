class Solution {
    void backtracking(vector<int>& freq, int target, vector<int>& arr, vector<vector<int>>& ans, int i){
        if(target == 0){
            ans.push_back(arr);
            return;
        }
        if(i > 50 || target < 0) return;

        int nextIndex = 0;

        for(int j = i+1; j<51; j++){
            if(freq[j] > 0){
                nextIndex = j;
                break;
            }
        }

        if(nextIndex > 0) backtracking(freq, target, arr, ans, nextIndex);
        
        if(freq[i] > 0){
            arr.push_back(i);
            freq[i]--;
            backtracking(freq, target - i, arr, ans, i);
            arr.pop_back();
            freq[i]++;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        vector<int> freq(51, 0);

        for(auto x : candidates) freq[x]++;

        backtracking(freq, target, arr, ans, 0);

        return ans;
    }
};
