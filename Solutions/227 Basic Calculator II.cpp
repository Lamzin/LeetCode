class Solution {
public:
    int calculate(string s) {
        stack<char> st_symb;
        stack<int> st_value;
        int cur_value = 0, prev_value = 0, left_operand, right_operand;

        s = '(' + s + ')';
        for (int i = 0; i < s.length(); i++){
            if (s[i] >= '0' && s[i] <= '9'){
                prev_value = 1;
                cur_value = cur_value * 10 + s[i] - '0';
                continue;
            }
            else if (prev_value){
                st_value.push(cur_value);
                prev_value = 0;
                cur_value = 0;
            }

            if (s[i] == ' ') continue;
            else if (s[i] == '(') st_symb.push('(');
            else if (s[i] == ')'){
                while (st_symb.size() && st_symb.top() != '('){
                    right_operand = st_value.top(); st_value.pop();
                    left_operand = st_value.top(); st_value.pop();
                    if (st_symb.top() == '*') st_value.push(left_operand * right_operand);
                    else if (st_symb.top() == '/') st_value.push(left_operand / right_operand);
                    else if (st_symb.top() == '+') st_value.push(left_operand + right_operand);
                    else if (st_symb.top() == '-') st_value.push(left_operand - right_operand);
                    st_symb.pop();
                }
                st_symb.pop();
            }
            else if (s[i] == '*' || s[i] == '/'){
                while (st_symb.size() && (st_symb.top() == '*' || st_symb.top() == '/')){
                    right_operand = st_value.top(); st_value.pop();
                    left_operand = st_value.top(); st_value.pop();
                    if (st_symb.top() == '*') st_value.push(left_operand * right_operand);
                    else if (st_symb.top() == '/') st_value.push(left_operand / right_operand);

                    st_symb.pop();
                }
                
                st_symb.push(s[i]);
            }
            else if (s[i] == '+' || s[i] == '-'){
                while (st_symb.size() && st_symb.top() != '('){
                    right_operand = st_value.top(); st_value.pop();
                    left_operand = st_value.top(); st_value.pop();
                    if (st_symb.top() == '*') st_value.push(left_operand * right_operand);
                    else if (st_symb.top() == '/') st_value.push(left_operand / right_operand);
                    else if (st_symb.top() == '+') st_value.push(left_operand + right_operand);
                    else if (st_symb.top() == '-') st_value.push(left_operand - right_operand);

                    st_symb.pop();
                }

                st_symb.push(s[i]);
            }

        }

        return st_value.top();
    }
};