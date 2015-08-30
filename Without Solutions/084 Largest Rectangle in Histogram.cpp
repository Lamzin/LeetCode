class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        int ans = 0, last = 0, i = 0;
        stack <int> st;

        while (i < height.size()){
            if (st.empty() || height[st.top()] <= height[i]) st.push(i++);
            else{
                last = st.top();
                st.pop();
                ans = max(ans, height[last] * (st.empty() ? i : i - st.top() - 1));
            }
        }

        return ans;
    }
};
