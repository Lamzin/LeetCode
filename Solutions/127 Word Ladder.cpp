class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {

        queue<pair<string, int> > que;
        if (wordDict.find(beginWord) == wordDict.end()){
            return -1;
        }        

        que.push(make_pair(beginWord, 1));
        wordDict.erase(beginWord);

        while (!que.empty()){

            auto front = que.front();
            que.pop();

            if (front.first == endWord) return front.second;

            for (int i = 0; i < front.first.length(); i++){
                string tmp = front.first;
                for (char j = 'a'; j <= 'z'; j++){
                    tmp[i] = j;
                    if (wordDict.find(tmp) != wordDict.end()){
                        que.push(make_pair(tmp, front.second + 1));
                        wordDict.erase(tmp);
                    }
                }
            }

        }

        return 0;

    }
};