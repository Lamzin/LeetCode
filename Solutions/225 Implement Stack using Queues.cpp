class Stack {
private:
    queue<int> *que = new queue<int>();

public:
    // Push element x onto stack.
    void push(int x) {
        queue<int> *new_que = new queue<int>();
        new_que->push(x);
        while(!que->empty()){
            new_que->push(que->front());
            que->pop();
        }
        swap(que, new_que);
    }

    // Removes the element on top of the stack.
    void pop() {
        que->pop();
    }

    // Get the top element.
    int top() {
        return que->front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return que->empty();
    }
};