class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        
        char hash[256];
        for(int i = 0; i < 256; i++) hash[i] = -1;
        
        for (int i = 0; i < t.length(); i++){
            if (hash[t[i]] == -1) hash[t[i]] = s[i];
            else if (hash[t[i]] != s[i]) return false;
        }
        
        for(int i = 0; i < 256; i++) hash[i] = -1;
        for (int i = 0; i < t.length(); i++){
            if (hash[s[i]] == -1) hash[s[i]] = t[i];
            else if (hash[s[i]] != t[i]) return false;
        }
        
        return true;
    }
};