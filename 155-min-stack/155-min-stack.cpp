class MinStack {
public:
    stack<int> s;
    stack<int> temp;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(temp.empty())
            temp.push(val);
        else{
            if(val <= temp.top())
                temp.push(val);
        }
    }
    
    void pop() {
        if(s.top() == temp.top())
            temp.pop();
        s.pop();
    }
    
    int top() {
      return  s.top();
    }
    
    int getMin() {
        return temp.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */