class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int qsize = q.size();
        int val;
        while(qsize>1){
            q.push(q.front());
            q.pop();
            qsize--;
        }
        val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        int qsize = q.size();
        int val;
        while(qsize--){
            val = q.front();
            q.push(val);
            q.pop();
        }
        return val;
    }
    
    bool empty() {
        return q.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
