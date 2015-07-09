class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int maxIndex = 0, curIndex;
        vector<int> dist(nums.size());
        queue<int> que;

        que.push(0);
        dist[0] = 1;


        while(!que.empty()){
            curIndex = que.front();
            que.pop();
            for(int i = maxIndex + 1; i <= nums[curIndex] + curIndex && i < nums.size(); i++){
                que.push(i);
                dist[i] = dist[curIndex] + 1;
            }
            maxIndex = max(maxIndex, nums[curIndex] + curIndex);
        }

        return dist[nums.size() - 1] - 1;
    }
};