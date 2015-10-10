class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        if (haystack.length() == 0) return -1;

        string s = needle + "#" + haystack;        
        vector<int> phi(s.length(), 0);
        int tmp;

        for (int i = 1; i < s.length(); i++){
            tmp = phi[i - 1];
            while(tmp && s[tmp] != s[i]){
                tmp = phi[tmp - 1];
            }

            phi[i] = (s[tmp] == s[i]) ? tmp + 1 : 0;
        }

        for (int i = needle.length(); i < s.length(); i++){
            if (phi[i] == needle.length())
                return i - 2 * needle.length();
        }

        return -1;

    }
};