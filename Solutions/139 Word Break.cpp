class Solution {
private:
    map<string, bool> cache;
    unordered_set<string> *Dict;

    bool wordBreak(string s){
        if (cache.find(s) != cache.end()) return cache[s];

        if (Dict->count(s)) return cache[s] = true;
        for (int i = 1; i < s.length(); i++){
            string left = s.substr(0, i);
            if (Dict->count(left) && wordBreak(s.substr(i, s.length() - i))) return cache[s] = true;
        }

        return cache[s] = false;
    }

public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        Dict = &wordDict;
        return wordBreak(s);
    }
};