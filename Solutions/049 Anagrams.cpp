class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string, int> srt;

        for (int i = 0; i < strs.size(); i++){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());

            if (srt.find(tmp) == srt.end()){
                srt[tmp] = result.size();
                result.push_back(vector<string>());
            }

            result[srt[tmp]].push_back(strs[i]);

        }

        for (int i = 0; i < result.size(); i++){
            sort(result[i].begin(), result[i].end());
        }

        return result;
    }
};