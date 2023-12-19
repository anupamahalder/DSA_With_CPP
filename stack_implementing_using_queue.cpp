class MyStack {
private:
	queue<int>q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        queue<int>newQ;
        int val;
        while(!q.empty()){
            int k = q.front();
            q.pop();
            if(q.empty()){
                val = k;
                break;
            }
            newQ.push(k);
        }
        q = newQ;
        return val;
    }
    
    int top() {
        queue<int>newQ;
        int val;
        while(!q.empty()){
            int k = q.front();
            q.pop();
            if(q.empty()){
                val = k;
            }
            newQ.push(k);
        }
        q = newQ;
        return val;
    }
    
    bool empty() {
        return q.size()==0;
    }
};
