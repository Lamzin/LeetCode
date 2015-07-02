class Solution {
public:
    bool isPalindrome(string s) {
        string ss;
        for (int i = 0; i < s.length(); i++){
            if (s[i] >='a' && s[i] <= 'z') ss += s[i];
            else if (s[i] >='A' && s[i] <= 'Z') ss += s[i] - 'A' + 'a';
            else if (s[i] >= '0' && s[i] <= '9') ss += s[i];
        }
        
        for (int i = 0; 2*i < ss.length(); i++)
            if (ss[i] != ss[ss.length() - 1 - i]) return false;
            
        return true;
    }
};