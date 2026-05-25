class MinStack {
private:
    stack<int> s;
    stack<int> mins;

public:

    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        mins.push(min(val,mins.empty() ? val:mins.top()));
    }
    
    void pop() {
        s.pop();
        mins.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};