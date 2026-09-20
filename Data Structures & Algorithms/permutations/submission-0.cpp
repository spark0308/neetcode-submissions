class Solution {
    vector<vector<int>> permutations;
    void backtracking(vector<int>& nums, map<int, bool>& added, vector<int>& temp, int i){
        if(temp.size() == nums.size()){
            permutations.push_back(temp);
            return;
        }
        if(i >= nums.size()) return;

        if(!added[nums[i]]){
            added[nums[i]] = true;
            temp.push_back(nums[i]);
            backtracking(nums, added, temp, 0);
            added[nums[i]] = false;
            temp.pop_back();
        }

        backtracking(nums, added, temp, i + 1);
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        map<int, bool> added;
        vector<int> temp;
        backtracking(nums, added, temp, 0);

        return permutations;
    }
};
