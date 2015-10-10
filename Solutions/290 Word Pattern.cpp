class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> dict1;
        map<string, char> dict2;

        str += ' '; // thus we split all word =)
        string current;
        int cnt = 0;
        for (int i = 0; i < str.length(); i++){
            if (cnt > pattern.length()) return false;

            if (str[i] == ' '){
                auto it1 = dict1.find(pattern[cnt]);
                auto it2 = dict2.find(current);

                if (it1 == dict1.end() && it2 == dict2.end()){
                    dict1[pattern[cnt]] = current;
                    dict2[current] = pattern[cnt];
                }
                else if (it1 == dict1.end() || it2 == dict2.end() || dict1[pattern[cnt]] != current || dict2[current] != pattern[cnt]) 
                    return false;

                current = "";
                cnt++;
            }
            else
                current += str[i];
        }

        if (cnt != pattern.length()) return false;

        return true;
    }
};