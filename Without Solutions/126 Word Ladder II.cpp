struct node{
        bool terminal;
        int go[26];

        node(){
            terminal = false;
            for (int i = 0; i < 26; i++) go[i] = -1;
        }
};


class Trie(){
    vector<node> nodes;

public:
    Trie(){
        nodes.push_back(node());
    }

    void add(const string &s){
        int ind = 0;
        for (char ch : s){
            int &go = nodes[ind].go[ch - 'a'];
            if (go == -1){
                go = nodes.size();
                nodes.push_back(node());
            }
            ind = nodes[ind].go[ch - 'a'];
        }
        nodes[ind].terminal = 1;
    }

    vector<string> next(const string &s){
        vector<string> res;

        for (int k = 0; k < s.length(); k++){
            int ind = 0;
            for (int i = 0; i < k && ind != -1; i++) ind = nodes[ind].go[s[i] - 'a'];
            if (ind == -1) continue;

            string s_next = s;
            for (int i = 0; i < 26; i++){
                ind_next = ind;
                ind_next = nodes[ind_next].go[i];
                for (int j = k + 1; j < s.length() && ind_next != -1; j++){
                    if (nodes[ind_next].terminal){
                        s_next[k] = i + 'a';
                        res.push_back(s_next);
                        s_next[k] = s[k];
                    }

                    ind_next = nodes[ind_next].go[s[j] - 'a'];
                }
            }

        }

        return res;
    }

};


class Solution {
private:
    Trie trie;
    make_trie(unordered_set<string> &wordList){
        for (string s : wordList) trie.add(s);
    }


public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        unordered_map<string, int> used;
        vector<pair<string, int>> que;
        vector<vector<string>> ans;

        swap(beginWord, endWord);

        if (wordList.count(beginWord) == 0 || wordList.count(endWord) == 0) return ans;
        if (beginWord == endWord) return vector<vector<string>>(1, vector<string>(1, beginWord));

        make_trie(wordList);

        que.push_back(make_pair(beginWord, -1));
        used[beginWord] = 0;

        for (int i = 0, len = 100000; i < que.size(); i++){
            if (que[i].first == endWord){
                vector<string> curr;
                int j = i;
                while (j != -1){
                    curr.push_back(que[j].first);
                    j = que[j].second;
                }

                if (curr.size() <= len){
                    len = curr.size();
                    ans.push_back(curr);
                }
                else break;
            }
            else{

                auto next_arr = trie.next(que[i].first);

                for (string next : next_arr){
                    if (wordList.count(next) && (!used.count(next) || used[next] > i)){
                        if (next != endWord && !used.count(next)) used[next] = que.size();
                        que.push_back(make_pair(next, i));
                    }
                }
                
            }

        }

        return ans;
    }
};