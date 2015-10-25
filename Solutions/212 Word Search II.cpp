struct node{
    int terminal, parent, go[26];
    node(){
        parent = -1;
        terminal = false;
        for (int i = 0; i < 26; i++) go[i] = -1;
    }
};


class Trie{
public:
    vector<node> nodes;
    
    Trie(){
        nodes.push_back(node());
    }

    void add(const string &s){
        int ind = 0;
        for (int i = 0; i < s.length(); i++){
            int &nxt = nodes[ind].go[s[i] - 'a'];
            if (nxt == -1){
                nxt = nodes.size();
                nodes.push_back(node());
                nodes[nxt].parent = ind;
            }
            ind = nxt;
        }
        nodes[ind].terminal = 1;
    }

};


class Solution {
private:
    int n, m;
    Trie trie;
    vector<string> result;
    vector<vector<char>> *Board, used;
    string current_word;

    bool check(int x, int y, int index_in_trie){
        return x >= 0 && x < n && y >= 0 && y < m && !used[x][y]
            && trie.nodes[index_in_trie].go[(*Board)[x][y] - 'a'] != -1;
    }

    void dfs(int x, int y, int index_in_trie){
        current_word.push_back((*Board)[x][y]);
        used[x][y] = 1;


        index_in_trie = trie.nodes[index_in_trie].go[(*Board)[x][y] - 'a'];
        if (trie.nodes[index_in_trie].terminal){
            trie.nodes[index_in_trie].terminal = 0;
            result.push_back(current_word);
        }


        if (check(x + 1, y, index_in_trie)) dfs(x + 1, y, index_in_trie);
        if (check(x - 1, y, index_in_trie)) dfs(x - 1, y, index_in_trie);
        if (check(x, y + 1, index_in_trie)) dfs(x, y + 1, index_in_trie);
        if (check(x, y - 1, index_in_trie)) dfs(x, y - 1, index_in_trie);


        current_word.pop_back();
        used[x][y] = 0;
    }


public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.size() == 0 || board[0].size() == 0) return vector<string>();
        n = board.size();
        m = board[0].size();
        Board = &board;
        used.resize(n, vector<char>(m, 0));

        for (string s : words) trie.add(s);


        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (check(i, j, 0)) dfs(i, j, 0);

        return result;
    }
};