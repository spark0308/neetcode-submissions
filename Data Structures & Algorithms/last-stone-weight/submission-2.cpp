class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for(auto x: stones) heap.push(x);

        while(heap.size() > 1){
            int x = heap.top();
            heap.pop();
            int y = heap.top();
            heap.pop();
            int remain = abs(x-y);

            if(remain > 0){
                heap.push(remain);
            }
        }
        
        return heap.size() == 1 ? heap.top() : 0;
    }
};
