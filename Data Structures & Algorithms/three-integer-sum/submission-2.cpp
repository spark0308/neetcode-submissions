class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans = vector<vector<int>>();
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i<n-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int target = nums[i] * -1;
            int j = i+1;
            int k = n-1;
            while(j < k){
                if(nums[j] + nums[k] == target){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++; // Skip duplicate values for the left pointer
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--; // Skip duplicate values for the right pointer
                    }
                }
                else if(nums[j] + nums[k] < target) j++;
                else if(nums[j] + nums[k] > target) k--;
            }
        }

        return ans;
    }
};
