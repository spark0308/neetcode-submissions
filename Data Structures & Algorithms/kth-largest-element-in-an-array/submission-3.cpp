#include <random>
class Solution {
    int randInd(int left, int right){
        int len = right - left + 1;

        return (rand()%len) + left;
    }
    int pivotSearch(vector<int>& nums, int l, int r, int k){
        int pivotIndex = randInd(l, r);
        int pivot = nums[pivotIndex];
        int p = l;
        swap(nums[pivotIndex], nums[r]);
        for(int i=l; i<r; i++){
            if(nums[i] < pivot){
                swap(nums[p], nums[i]);
                p++;
            }
        }

        swap(nums[p], nums[r]);

        if(p > k) return pivotSearch(nums, l, p-1, k);
        else if (p < k) return pivotSearch(nums, p+1, r, k);

        return nums[p];

    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        return pivotSearch(nums, 0, nums.size()-1, k);
    }
};
