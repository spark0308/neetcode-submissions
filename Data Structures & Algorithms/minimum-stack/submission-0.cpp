class MinStack {
public:
    stack<int> prim;
    stack<int> minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        prim.push(val);
        if(minStack.empty() || val <= minStack.top()){
            minStack.push(val);
        }
    }
    
    void pop() {
        int primTop = prim.top();
        int minTop = minStack.top();
        if(primTop == minTop) minStack.pop();
        prim.pop();
    }
    
    int top() {
        return prim.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
