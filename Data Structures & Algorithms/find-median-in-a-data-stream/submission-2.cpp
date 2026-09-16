class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> upper_heap;
    priority_queue<int> lower_heap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(lower_heap.empty() || num <= lower_heap.top()) lower_heap.push(num);
        else upper_heap.push(num);

        if(std::abs((int)lower_heap.size() - (int)upper_heap.size()) > 1){
            if(upper_heap.size() > lower_heap.size()){
                lower_heap.push(upper_heap.top());
                upper_heap.pop();
            }
            else{
                upper_heap.push(lower_heap.top());
                lower_heap.pop();
            }
        }
    }
    
    double findMedian() {
        if(lower_heap.size() == upper_heap.size()){
            return (double)(lower_heap.top() + upper_heap.top())/2;
        }
        else if(lower_heap.size() > upper_heap.size()) return lower_heap.top();
        else return upper_heap.top();
    }
};
