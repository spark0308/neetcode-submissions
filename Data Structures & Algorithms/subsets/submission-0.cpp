class Solution {
    void combinate(vector<int>& nums, int i, vector<int> arr, vector<vector<int>> &combinations){
        if(i == nums.size()){
            combinations.push_back(arr);
            return;
        }

        combinate(nums, i+1, arr, combinations);
        arr.push_back(nums[i]);
        combinate(nums, i+1, arr, combinations);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> combinations;
        combinate(nums, 0, {}, combinations);
        // combinate(nums, 0, {nums[0]}, combinations);

        return combinations;
    }
};
