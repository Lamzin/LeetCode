class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;

        int l = nums[0], r = nums[0];
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == r + 1) r++;
            else{
                if (l == r)
                    ans.push_back(to_string(l));
                else
                    ans.push_back(to_string(l) + "->" + to_string(r));
                l = r = nums[i];
            }
        }
    
        if (l == r)
            ans.push_back(to_string(l));
        else
            ans.push_back(to_string(l) + "->" + to_string(r));

        return ans;
    }
};