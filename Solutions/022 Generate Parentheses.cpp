class Solution {
private: 
    string current;
    vector<string> answer;
    int N;

    void dfs(int open){
        if (open < 0) return;
        if (current.length() == N){
            if (open == 0) answer.push_back(current);
            return;
        }

        current.push_back('(');
        dfs(open + 1);
        current.pop_back();

        current.push_back(')');
        dfs(open - 1);
        current.pop_back();
    }


public:
    vector<string> generateParenthesis(int n) {
        N = 2 * n;
        dfs(0);
        return answer;
    }
};




// class Solution {
// private: 
//     vector<string> answer;
//     int N;

//     void dfs(string current, int open){
//         if (open < 0) return;
//         if (current.length() == N){
//             if (open == 0) answer.push_back(current);
//             return;
//         }

//         dfs(current + "(", open + 1);
//         dfs(current + ")", open - 1);
//     }


// public:
//     vector<string> generateParenthesis(int n) {
//         N = 2 * n;
//         dfs("", 0);
//         return answer;
//     }
// };




// class Solution {
// private:
//     unordered_map<int, vector<string>> un_map;

// public:
//     vector<string> generateParenthesis(int n) {
//         if (n <= 0) return vector<string>();
//         if (n == 1) return vector<string>(1, "()");

//         auto it = un_map.find(n);
//         if (it != un_map.end()) return it->second;

//         vector<string> answer;
//         vector<string> tmp = generateParenthesis(n - 1), ttmp;
//         string ss, sss;

//         for (string s : tmp) answer.push_back("(" + s + ")");

//         if (n % 2 == 0){
//             tmp = generateParenthesis(n / 2);
//             for (int i = 0; i < tmp.size(); i++) answer.push_back(tmp[i] + tmp[i]);

//             for (int i = 0; i < tmp.size(); i++){
//                 for (int j = i + 1; j < tmp.size(); j++){
//                     ss = tmp[i] + tmp[j];
//                     sss = tmp[j] + tmp[i];
//                     answer.push_back(ss);
//                     if (ss != sss) answer.push_back(sss);
//                 }
//             }        
//         }

//         for (int i = 1; 2 * i < n; i+=1){
//             tmp = generateParenthesis(i);
//             ttmp = generateParenthesis(n - i);

//             for (auto it = tmp.begin(); it != tmp.end(); it++){
//                 for (auto itt = ttmp.begin(); itt != ttmp.end(); itt++){
//                     ss = *it + *itt;
//                     sss = *itt + *it;
//                     answer.push_back(ss);
//                     if (ss != sss) answer.push_back(sss);
//                 }
//             }
//         }

//         sort(answer.begin(), answer.end());
//         tmp.clear();
//         if (answer.size()) tmp.push_back(answer[0]);
//         for (int i = 1; i < answer.size(); i++)
//             if (answer[i] != answer[i - 1]) tmp.push_back(answer[i]);

//         return un_map[n] = tmp;
//     }
// };