class MyStack {
public:
    queue<int> q;

    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
        int sz = q.size();
        for (int i = 1; i < sz; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
