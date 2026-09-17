class Solution {
    void combinate(vector<int>& nums, int i, vector<int> &arr, vector<vector<int>> &combinations){
        if(i == nums.size()){
            combinations.push_back(arr);
            return;
        }

        combinate(nums, i+1, arr, combinations);
        arr.push_back(nums[i]);
        combinate(nums, i+1, arr, combinations);
        arr.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> combinations;
        vector<int> arr;
        combinate(nums, 0, arr, combinations);

        return combinations;
    }
};
