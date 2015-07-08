class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int l, r;
        stack <int> value;
        for (int i = 0; i < tokens.size(); i++){
            if (tokens[i] == "+"){
                r = value.top();
                value.pop();
                l = value.top();
                value.pop();
                value.push(l + r);
            }
            else if (tokens[i] == "-"){
                r = value.top();
                value.pop();
                l = value.top();
                value.pop();
                value.push(l - r);
            }
            else if (tokens[i] == "*"){
                r = value.top();
                value.pop();
                l = value.top();
                value.pop();
                value.push(l * r);
            }
            else if (tokens[i] == "/"){
                r = value.top();
                value.pop();
                l = value.top();
                value.pop();
                value.push(l / r);
            }
            else{
                value.push(stod(tokens[i]));
            }
        }

        return value.top();
    }
};