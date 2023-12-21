void reverseStack(stack<int> &st) {
    // Write your code here
    if(st.empty()) return;
    int x = st.top();
    st.pop();
    reverseStack(st);
    stack<int>cp;
    while(!st.empty()){
        cp.push(st.top());
        st.pop();
    } 
    st.push(x);
    while(!cp.empty()){
        st.push(cp.top());
        cp.pop();
    }
}
