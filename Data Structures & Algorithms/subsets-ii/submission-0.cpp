class Solution {
    vector<vector<int>> subsets;
    void backtracking(vector<int>& nums, vector<int>& temp, int idx){
        subsets.push_back(temp);

        for(int i=idx; i<nums.size(); i++){
            if(i > idx && nums[i] == nums[i-1]) continue;

            temp.push_back(nums[i]);
            backtracking(nums, temp, i + 1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        backtracking(nums, temp, 0);

        return subsets;
    }
};
