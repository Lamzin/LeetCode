class Solution {
protected:
    string arr[10];


    string _digits;
    vector<string> result;
  
    void dp(int pos, int index, string current){
        // what_is(pos);
        // what_is(index);
        // what_is(current);

        if (pos >= (int)_digits.length()){
            if (index == 0){
                result.push_back(current);  
                // what_is(result.size());
            }
            return;
        }
        if (pos != -1 && index >= arr[_digits[pos] - '0'].length()) return;
        if (pos != -1) current += arr[_digits[pos] - '0'][index];

        for (int i = 0; i < 4; i++)
            dp(pos + 1, i, current);
    }

public:
  
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return vector<string>();

        arr[0] = " ";
        arr[1] = "";
        arr[2] = "abc";
        arr[3] = "def";
        arr[4] = "ghi";
        arr[5] = "jkl";
        arr[6] = "mno";
        arr[7] = "pqrs";
        arr[8] = "tuv";
        arr[9] = "wxyz";
        result.clear();

        _digits = digits;
        // what_is(_digits);
        dp(-1, 0, string());
        return result;
    }
};
