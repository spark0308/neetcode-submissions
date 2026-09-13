class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ans = 0;
        priority_queue<int> pq;

        for(auto x: nums) pq.push(x);

        for(int i=0; i<k; i++){
            ans = pq.top();
            pq.pop();
        } 

        return ans;
    }
};
