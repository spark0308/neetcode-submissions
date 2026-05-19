class Solution {
public:
    int binarySearch(int l, int r, vector<int>& nums, int target){
        if(l>r) return -1;
        if(l==r){
            if(nums[l] == target) return l;
            else return -1;
        }

        int mid = (r-l)/2 + l;

        if(nums[mid] == target) return mid;
        if(nums[mid] < target) return binarySearch(mid + 1, r, nums, target);
        if(nums[mid] > target) return binarySearch(l, mid - 1, nums, target);

        return -1;
    }

    int search(vector<int>& nums, int target) {
        return binarySearch(0, nums.size()-1, nums, target);
    }
};
