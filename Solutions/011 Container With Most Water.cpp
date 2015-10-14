class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, result = 0, __min;

        while(left <= right){
            __min = min(height[left], height[right]);
            result = max(result, (right - left) * __min);
            if (height[left] == __min) left++;
            else right--;
        }

        return result;
    }
};