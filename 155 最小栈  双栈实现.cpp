class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> datas;
    stack<int> mins;

    MinStack() {
        
    }
    
    void push(int x) {
       datas.push(x);
       if(mins.empty() || x<=mins.top())
            mins.push(x);
    }
    
    void pop() 
    {
        if(datas.top() == mins.top())
            mins.pop();
        datas.pop();
    }
    
    int top() {
        return datas.top();
    }
    
    int getMin() {
        
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
