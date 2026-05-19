class Solution {
public:
    int binarySearch(int l, int r, vector<int>& nums, int target){
        if(l>r) return -1;
        if(l==r){
            if(nums[l] == target) return l;
            else return -1;
        }

        int mid = (r-l)/2 + l;

        int leftAns = binarySearch(l, mid, nums, target);
        int rightAns = binarySearch(mid+1, r, nums, target);

        return max(leftAns, rightAns);

    }

    int search(vector<int>& nums, int target) {
        return binarySearch(0, nums.size()-1, nums, target);
    }
};
