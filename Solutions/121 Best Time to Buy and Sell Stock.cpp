class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        int ans = 0, curMin = prices[0];
        for (int i = 1; i < prices.size(); i++){
            ans = max(ans, prices[i] - curMin);
            curMin = min(curMin, prices[i]);
        }

        return ans;
    }
};