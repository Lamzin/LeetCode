class Solution {
private:
    map<string, vector<string>> cache;
    unordered_set<string> *Dict;

    vector<string> wordBreak(string s){
        if (cache.find(s) != cache.end()) return cache[s];

        vector<string> result;

        if (Dict->count(s)) result.push_back(s);

        string left;
        for (int i = 1; i < s.length(); i++){
            left += s[i - 1];
            if (Dict->count(left)){
                vector<string> right = wordBreak(s.substr(i, s.length() - i));
                combine(left, right, result);
            }
        }

        return cache[s] = result;
    }

    void combine(string left, vector<string> &right, vector<string> &result){
        for (auto it = right.begin(); it != right.end(); it++){
            result.push_back(left + " " + *it);
        }
    }

public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        Dict = &wordDict;
        return wordBreak(s);
    }
};


// class Solution {
// private:
//     map<string, vector<string>> cache;

// public:
//     vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
//         if (cache.count(s)) return cache[s];

//         vector<string> result;
//         if (wordDict.count(s)) result.push_back(s);
//         for (int i = 1; i < s.length(); i++){
//             vector<string> left, right;

//             left  = wordBreak(s.substr(0, i), wordDict);
//             right = wordBreak(s.substr(i, s.length() - i), wordDict);

//             for (auto i = left.begin(); i != left.end(); i++)
//                 for (auto j = right.begin(); j != right.end(); j++)
//                     result.push_back(*i + " " + *j);
//         }

//         return cache[s] = result;
//     }
// };



// class Solution {
// private:
//     unordered_set<string> *Dict;
//     vector<string> result;
//     vector<int> index_begin;
//     int index_end, next; 
//     string *ss;
//     vector<vector<int>> *dp;

//     int next_exist(int position, int len = 0){
//         if ((*dp)[position][len] != -1) return (*dp)[position][len];

//         for(int pos_end = position + 1 + len; pos_end <= ss->length(); pos_end++){
//             if (Dict->find(string(*ss, position, pos_end - position)) != Dict->end()){
//                 return (*dp)[position][len] = pos_end;
//             }
//         }
//         return (*dp)[position][len] = 0;
//     }

// public:
//     vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
//         if (s.length() == 0) return vector<string>();

//         Dict = &wordDict;
//         ss = &s;
//         dp = new vector<vector<int>>(s.length() + 5, vector<int>(s.length() + 5, -1));

//         if (next = next_exist(0) != 0){
//             index_end = next;
//             index_begin.push_back(0);
//         }

//         while(index_end){
//             if (index_end == s.length()){
//                 index_begin.push_back(index_end);
//                 string curr = string(s, 0, index_begin[1]);
//                 for (int i = 1; i < index_begin.size() - 1; i++){
//                     curr += " " + string(s, index_begin[i], index_begin[i + 1] - index_begin[i]);
//                 }
//                 index_begin.pop_back();
//             }

//             if ((next = next_exist(index_end)) != 0){
//                 index_begin.push_back(index_end);
//                 index_end = next;
//             }
//             else{
//                 while(index_end && (next = next_exist(index_begin.back(), index_end - index_begin.back())) == 0){
//                     index_end = index_begin.back();
//                     index_begin.pop_back();
//                 }

//                 if (index_end){
//                     index_end = next;
//                 }
//             }

//         }

//         return result;
//     }
// };