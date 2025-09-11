class MinStack {
public:
    stack<int>st;
    stack<int>MinS;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if(MinS.empty() || MinS.top() >= val) MinS.push(val);
    }
    
    void pop() {
        if(st.top() == MinS.top()){
            MinS.pop();
        }

        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return MinS.top();
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