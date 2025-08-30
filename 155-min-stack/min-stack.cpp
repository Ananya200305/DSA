class MinStack {
public:
    stack<int>st;
    stack<int>minS;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if(minS.empty() || minS.top() >= val){
            minS.push(val);
        }
    }
    
    void pop() {
        if(st.top() == minS.top()){
            minS.pop();
        }

        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minS.top();
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