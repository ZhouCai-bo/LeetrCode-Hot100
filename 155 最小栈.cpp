class MinStack {
public:
    /** initialize your data structure here. */
    struct node
    {
        int value;
        node *prev;
    };
    node *head, *tail;
    int size = 0, min = 0;
    MinStack() {
        
    }
    
    void push(int x) {
        if(size == 0)
        {
            head = tail = new node();
            head->prev = nullptr;
            head->value = x;
            size++;
            min = x;
            return;
        }

        node *temp = new node();
        temp->value = x;
        temp->prev = tail;
        tail = temp;
        size++;
        if(x<min)
            min = x;
    }
    
    void pop() 
    {
        if(tail->value == min && size>1)
        {
            node *temp = tail;
            min = temp->prev->value;
            while(temp=temp->prev)
            {
                //min = 0;
                //return;
                if(temp->value<min)
                {
                    min = temp->value;
                }
            }
        }
        node *temp = tail;
        tail = tail->prev;
        delete temp;
        size--;
    }
    
    int top() {
        return tail->value;
    }
    
    int getMin() {
        
        return min;
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
