class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if (nums.size() == 0) return ans;
        
        int curmax = nums[0], index = 0;

        for (int i = 1; i < k; i++){
            if (nums[i] >= curmax){
                curmax = nums[i];
                index = i;
            }
        }

        ans.push_back(curmax);

        for (int i = k; i < nums.size(); i++){
            if (nums[i] >= curmax){
                curmax = nums[i];
                index = i;
            }

            if (index <= i - k){
                index = i - k  + 1;
                curmax = nums[index];
                for (int j = index; j <= i; j++){
                    if (nums[j] >= curmax){
                        curmax = nums[j];
                        index = j;
                    }
                }
            }

            ans.push_back(curmax);
        }

        return ans;
    }
};
