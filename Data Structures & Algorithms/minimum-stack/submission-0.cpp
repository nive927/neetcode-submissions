class MinStack {
public:

    stack<int> stacker;
    stack<int> minStack;

    MinStack() {

        // nothing to initialize
        
    }
    
    void push(int val) {

        stacker.push(val);
        if(minStack.empty()) {
            minStack.push(val);
        } else {
            int temp = min(val, minStack.top());
            minStack.push(temp);
        }
        
    }
    
    void pop() {

        stacker.pop();
        minStack.pop();
        
    }
    
    int top() {

        return stacker.top();
        
    }
    
    int getMin() {

        return minStack.top();
                
    }
};
