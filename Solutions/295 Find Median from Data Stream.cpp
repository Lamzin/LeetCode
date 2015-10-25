class MedianFinder {
private:
    priority_queue<int> left_part;
    priority_queue<int, vector<int>, greater<int>> right_part;


public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (left_part.size() == 0) left_part.push(num);
        else{
            if (num <= left_part.top()) left_part.push(num);
            else right_part.push(num);
        }

        if (left_part.size() == right_part.size() + 2){
            right_part.push(left_part.top());
            left_part.pop();
        }
        else if (left_part.size() < right_part.size()){
            left_part.push(right_part.top());
            right_part.pop();
        }

    }

    // Returns the median of current data stream
    double findMedian() {
        if (left_part.size() == 0) return 0.0f;
        return ((left_part.size() + right_part.size()) % 2) 
                ? left_part.top() : (left_part.top() + right_part.top()) / 2.0f;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();