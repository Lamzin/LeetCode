class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if (strs.size() == 0) return ans;
        int i, j;
        bool push = true;
        
        for (i = 0; push; i++){
            if (strs[0].length() <= ans.length()) push = false;
            
            if (push)
                for (j = 1; j < strs.size(); j++){
                    if (strs[j].length() <= ans.length() || strs[j][ans.length()] != strs[0][ans.length()])
                        push = false;
                }
            if (push) ans += strs[0][ans.length()];
        }
        
        return ans;
    }
};