class Solution {
private:
    vector<vector<string>> result;
    vector<string> current;
    vector<int> index_begin;
    int index_end;
    string *ss;
    vector<vector<int>> *dp, *dp_exist;


    bool is_palindrome(int l, int r){
        if ((*dp)[l][r] != -1) return (*dp)[l][r];
        for (int i = l; i <= l + (r - l) / 2; i++){
            if ((*ss)[i] != (*ss)[r - i + l]) return (*dp)[l][r] = false;
        }

        return (*dp)[l][r] = true;
    }

    bool next_palindrome_exist(){
        int &__dp_exist = (*dp_exist)[index_end][index_begin.back()];
        if (__dp_exist != -1){
            if (__dp_exist) index_end = __dp_exist;      
            return __dp_exist;
        }

        for (int i = index_end; i < ss->length(); i++){
            if (is_palindrome(index_begin.back(), i)){
                index_end = i + 1;
                return __dp_exist = i + 1;
            }
        }

        return __dp_exist = false;
    }

public:
    vector<vector<string>> partition(string s) {
        if (s.length() == 0) return vector<vector<string>>();

        dp = new vector<vector<int>>(s.length(), vector<int>(s.length(), -1));
        dp_exist = new vector<vector<int>>(s.length() + 5, vector<int>(s.length() + 5, -1));

        ss = &s;
        index_begin.push_back(0);
        index_end = 1;

        while(index_end){
            if (index_end == s.length()){
                current.clear();
                index_begin.push_back(index_end);
                for (int i = 0; i < index_begin.size() - 1; i++){
                    current.push_back(string(s, index_begin[i], index_begin[i + 1] - index_begin[i]));
                }
                index_begin.pop_back();
                result.push_back(current);
            }

            if (index_end < s.length()){
                index_begin.push_back(index_end);
                index_end++;
            }
            else{
                while(index_end && !next_palindrome_exist()){
                    index_end = index_begin.back();
                    index_begin.pop_back();
                }
            }
        }

        return result;
    }

};