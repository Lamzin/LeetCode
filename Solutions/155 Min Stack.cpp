class MinStack {
protected:
    stack<pair<int, int>> st;

public:
    void push(int x) {
        if (st.size() == 0 || x < st.top().second)
            st.push(make_pair(x, x));
        else
            st.push(make_pair(x, st.top().second));
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;   
    }
};