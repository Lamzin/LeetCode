class Solution {
public:
    string minWindow(string s, string t){
        string answer;
        int t_count[256], current_count[256];
        for (int i = 0; i < 256; i++) t_count[i] = current_count[i] = 0;
        for (int i = 0; i < t.length(); t_count[t[i++]]++);

        int left = 0, current_equals = 0, full_equals = 0;
        for (int i = 0; i < 256; i++) full_equals += t_count[i] > 0;

        for (int i = 0; i < s.length(); i++){
            current_count[s[i]]++;
            if (current_count[s[i]] == t_count[s[i]]) current_equals++;

            for (int j = left; j < i && (t_count[s[j]] == 0 || current_count[s[j]] > t_count[s[j]]); j++){
                current_count[s[j]]--;
                left++;
            }

            if (current_equals == full_equals && (answer.length() == 0 || i - left + 1 < answer.length()))
                answer = s.substr(left, i - left + 1);
        }
          
        return answer;
    }
};