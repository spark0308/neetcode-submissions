class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());

        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n-(k-1); i++) ans = temp[i];

        return ans;
    }
};
