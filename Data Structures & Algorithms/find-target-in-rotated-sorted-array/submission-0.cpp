class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = nums.size()-1;
        int leastInd = 0;

        while(left <= right){
            if(nums[left] < nums[right]){
                if(nums[leastInd] > nums[left]) leastInd = left;
                break;
            }

            int mid = (right-left)/2 + left;

            if(nums[leastInd] > nums[mid]) leastInd = mid;

            if(nums[mid] >= nums[left]) left = mid + 1; 

            else    right = mid - 1;
        }

        cout << leastInd<<endl;

        left = 0;
        right =  nums.size() - 1;

        while(left <= right){
            int mid = (right-left/2) + left;

            int searchInd = (mid + leastInd)%n;

            if(nums[searchInd] == target) return searchInd;
            else if(target > nums[searchInd]) left = mid + 1;
            else right = mid - 1;

        }

        return -1;
    }
};
