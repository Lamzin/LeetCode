class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        
        int hash[256], ans = 0, index = -2, i;
        for (int i = 0; i < 256; i++) hash[i] = -1;
        
        for (i = 0; i < s.length(); i++){
            if (hash[s[i]] > index){
                if (i - index - 1 > ans) ans = i - index - 1;
                index = hash[s[i]];
            }
            
            hash[s[i]] = i;
        }
        if (i - index - 1> ans) ans = i - index - 1;
        
        return ans;
    }
};