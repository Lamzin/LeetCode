class Solution{
public:
    bool isMatch(string s, string p){
        int i = 0, j = 0, p_star = -1, s_last = -1;

        while(i < s.length()){
            if (j < p.length() && p[j] == '?' || s[i] == p[j]){
                i++;
                j++;
            }
            else if (j < p.length() && p[j] == '*'){
                s_last = i;
                p_star = j;
                j++;
            }
            else if (p_star != -1){
                s_last++;
                i = s_last; 
                j = p_star + 1;
            }
            else{
                return false;
            }
        }

        while(j < p.length() && p[j] == '*') j++; 

        return i == s.length() && j == p.length();
    }
};




// class Solution {
// private:
//     vector<vector<char>> dp;
//     string *ss, *pp;
//     int ss_len, pp_len;

//     bool isMatch(int x, int y){
//         char &__dp__ = dp[x][y];
//         if (__dp__ != -1) return __dp__;

//         bool ans = false;
//         if (y < pp_len){
//             if (pp->at(y) == '*'){
//                 ans |= isMatch(x, y + 1);
//                 if (x < ss_len) ans |= isMatch(x + 1, y);
//             }
//             if (x < ss_len && (pp->at(y) == '?' || ss->at(x) == pp->at(y))) ans |= isMatch(x + 1, y + 1);
//         }
//         return __dp__ = ans;
//     }

// public:
//     bool isMatch(string s, string p) {
//         ss = &s; pp = &p;
//         ss_len = s.length(); pp_len = p.length();

//         dp.resize(ss_len + 1, vector<char>(pp_len + 1, -1));
//         dp[ss_len][pp_len] = 1;

//         return isMatch(0, 0);
//     }
// };