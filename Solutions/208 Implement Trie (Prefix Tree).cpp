class TrieNode {
public:
    // Initialize your data structure here.
    int terminal;
    TrieNode* edge[26];   
    TrieNode(){
        terminal = false;
        for (int i = 0; i < 26; i++) edge[i] = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        auto node = root;
        for (int i = 0; i < word.length(); i++){
            if (node->edge[word[i] - 'a'] == NULL){
                node->edge[word[i] - 'a'] = new TrieNode();
            }
            node = node->edge[word[i] - 'a'];
        }    
        node->terminal = 1;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        auto node = root;
        for (int i = 0; i < word.length(); i++){
            if (node->edge[word[i] - 'a'] == NULL) return false;
            node = node->edge[word[i] - 'a'];
        }
        return node->terminal;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        auto node = root;
        for (int i = 0; i < prefix.length(); i++){
            if (node->edge[prefix[i] - 'a'] == NULL) return false;
            node = node->edge[prefix[i] - 'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");