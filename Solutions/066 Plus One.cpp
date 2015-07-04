class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int nxt = 1;
        for (int i = digits.size() - 1; i >= 0; i--){
            nxt = nxt + digits[i];
            ans.push_back(nxt % 10);
            nxt /= 10;
        }
        while(nxt){
            ans.push_back(nxt % 10);
            nxt /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};