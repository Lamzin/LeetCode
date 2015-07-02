class Solution {
public:
    bool isValid(string s) {
        stack <int> st;
        int tmp;
        
        for (int i = 0; i < s.length(); i++){
            if (s[i] == ')'){
                if (st.size() == 0 || st.top() != '(') return false;
                st.pop();
            }
            else if (s[i] == ']'){
                if (st.size() == 0 || st.top() != '[') return false;
                st.pop();
            }
            else if (s[i] == '}'){
                if (st.size() == 0 || st.top() != '{') return false;
                st.pop();
            }
            else
                st.push(s[i]);
        }
        
        return st.size() == 0;
    }
};