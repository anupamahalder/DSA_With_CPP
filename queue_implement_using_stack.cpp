// Implement Queue using Stack
class MyQueue {
    private:
        stack<int>st;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        stack<int>newSt;
        int val;
        while(!st.empty()){
            int k = st.top();
            st.pop();
            if(st.empty()){
                val = k;
                break;
            }
            newSt.push(k);
        }
        while(!newSt.empty()){
            st.push(newSt.top());
            newSt.pop();
        }
        return val;
    }
    
    int peek() {
        stack<int>newSt;
        int val;
        while(!st.empty()){
            int k = st.top();
            st.pop();
            if(st.empty()){
                val = k;
            }
            newSt.push(k);
        }
        while(!newSt.empty()){
            st.push(newSt.top());
            newSt.pop();
        }
        return val;
    }
    
    bool empty() {
        return st.empty();
    }
};
