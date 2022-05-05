class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    
    // stack<int> s;
    
    MyStack() {
        
    }
    
    void push(int x) {
        if(q1.empty())
            q2.push(x);
        else
            q1.push(x);
        
        // cout << x << " " << q2.size() << endl;
    }
    
    int pop() {
        int x;
        if(q2.empty())
        {
            int n = q1.size(), i=0;
            while(i<n-1)
            {
                q2.push(q1.front());
                q1.pop();
                i++;
            }
            x = q1.front();
            q1.pop();
        }
        else
        {
            int n = q2.size(), i=0;
            while(i<n-1)
            {
                q1.push(q2.front());
                q2.pop();
                i++;
            }
            x = q2.front();
            q2.pop();
        }
        // cout << "Popped: " << x << endl;
        return x;
    }
    
    int top() {
        int x;
        if(q2.empty())
        {
            int n = q1.size(), i=0;
            while(i<n-1)
            {
                q2.push(q1.front());
                q1.pop();
                i++;
            }
            x = q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        else
        {
            int n = q2.size(), i=0;
            // cout << "n: " << n << endl;
            while(i<n-1)
            {
                q1.push(q2.front());
                cout << q2.front() << endl;
                q2.pop();
                i++;
            }
            x = q2.front();
            cout << q2.size() << endl;
            q1.push(q2.front());
            q2.pop();
        }
        return x;
    }
    
    bool empty() {
        if(q1.empty() && q2.empty())
            return true;
        return false;
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