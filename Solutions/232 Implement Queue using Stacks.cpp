class Queue {
private:
    stack<int> *st = new stack<int>();

public:
    // Push element x to the back of queue.
    void push(int x) {
        stack<int> *new_st = new stack<int>();
        while(!st->empty()){
            new_st->push(st->top());
            st->pop();
        }
        st->push(x);
        while(!new_st->empty()){
            st->push(new_st->top());
            new_st->pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        st->pop();
    }

    // Get the front element.
    int peek(void) {
        return st->top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return st->empty();
    }
};