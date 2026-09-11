class KthLargest {
    priority_queue<int> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) pq.push(nums[i]);
        this->k = k;
    }
    
    int add(int val) {
        pq.push(val);
        priority_queue<int> temp;

        temp = pq;

        for(int i=0; i<k; i++){
            if(i == k-1) return temp.top();
            temp.pop();
        }

        return -1;
    }
};
