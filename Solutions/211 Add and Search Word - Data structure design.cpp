class WordDictionary {
protected:

    struct node {
        int terminal;
        node *next[26];
        node() {
            terminal = 0;
            for (int i = 0; i < 26; i++) next[i] = NULL;
        }
    } *head;

public:

    WordDictionary(){
        head = new node();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        if (head == NULL) head = new node();

        node *current = head;
        for (int i = 0; i < word.length(); i++){
            if (current->next[word[i] - 'a'] == NULL){
                current->next[word[i] - 'a'] = new node();
            }
            current = current->next[word[i] - 'a'];
        }
        current->terminal = 1;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        queue <pair<node*, int> > que;
        que.push(make_pair(head, 0));

        while (!que.empty()){
            pair<node*, int> top = que.front();
            que.pop();

            if (top.second == word.length() && top.first->terminal == 1){
                return true;
            }

            if (top.second < word.length()){
                if (word[top.second] == '.'){
                    for (int i = 0; i < 26; i++){
                        if (top.first->next[i] != NULL){
                            que.push(make_pair(top.first->next[i], top.second + 1));
                        }
                    }
                }
                else{
                    if (top.first->next[word[top.second] - 'a'] != NULL){
                        que.push(make_pair(top.first->next[word[top.second] - 'a'], top.second + 1));
                    }
                }
            }
        }

        return false;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");