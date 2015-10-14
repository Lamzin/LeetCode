class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if (s.length() < 10) return result;

        int count[1048576] = {0}, current = 0, value[256];
        value['A'] = 0; value['C'] = 1; value['G'] = 2; value['T'] = 3;

        for (int i = 0; i < 9; i++) current = current << 2 | value[s[i]];
        for (int i = 9; i < s.length(); i++){
            current = (current << 2 | value[s[i]]) & 0xfffff;
            count[current] = min(count[current] + 1, 3);
            if (count[current] == 2) result.push_back(s.substr(i - 9, 10));
        }

        return result;
    }
};