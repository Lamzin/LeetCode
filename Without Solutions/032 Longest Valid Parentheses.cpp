class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack <int> st;

        for (int i = 0; i < (int)s.length(); i++){
            if (s[i] == ')' && !st.empty() && s[st.top()] == '('){
                s[i] = s[st.top()] = '0';
                st.pop();
            }
            else{
                st.push(i);
            }
        }

        int cur = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '0') cur++;
            else{
                ans = max(ans, cur);
                cur = 0;
            }
        }
        ans = max(ans, cur);


        return ans;
    }
};
