class Solution {
    void combinate(vector<int> &nums, vector<int> &arr, int target, vector<vector<int>> &ans, int sum, int i){
        if(sum == target) ans.push_back(arr);
        if(i >= nums.size() || sum >= target) return;

        
        arr.push_back(nums[i]);
        combinate(nums, arr, target, ans, sum + nums[i], i);
        arr.pop_back();
        
        combinate(nums, arr, target, ans, sum, i+1);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        combinate(nums, arr, target, ans, 0, 0);

        return ans;
    }
};
