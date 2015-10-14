class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap(nums.begin(), nums.begin() + k);
        for (int i = k; i < nums.size(); i++)
            if (heap.top() < nums[i]){
                heap.pop();
                heap.push(nums[i]);
            }

        return heap.top();
    }
};