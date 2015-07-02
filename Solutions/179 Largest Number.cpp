#include <algorithm>

bool comp(int a, int b){
    return to_string(a)+to_string(b)>to_string(b)+to_string(a);
}

class Solution {
public:
    
    string largestNumber(vector<int> &num) {
        string res = "";
        sort(num.begin(), num.end(), comp);
        if (num[0] == 0) res = "0";
        else 
            for (int i = 0; i<num.size(); i++) res += to_string(num[i]);
        return res;
    }
};