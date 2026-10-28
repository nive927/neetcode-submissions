class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // vars
        int ans = 1;

        // edge case optimization: early exit
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }

        // build the adj list
        // logic: for length of word k, we will use * to replace that letter in each level
        // MEMO this part: you are pushing the word by creating the patterns using that word
        // hot: *ot, h*t, ho*
        // val: key1, key2, key3
        // O(n*m)
        unordered_map<string, vector<string>> g;
        wordList.push_back(beginWord); // NOTE: important
        for(auto word: wordList) {
            for(int i=0; i<word.size(); i++) {
                string pattern = word.substr(0, i) + "*" + word.substr(i+1);
                g[pattern].push_back(word);
            }
        }

        // perform level-order bfs (shortest path)
        queue<string> q;
        unordered_set<string> visited;

        q.push(beginWord);
        visited.insert(beginWord);

        while(!q.empty()) {

            int qsize = q.size();

            for(int i=0; i<qsize; i++) {
                string curr = q.front();
                q.pop();

                if(curr == endWord) {
                    return ans;
                }

                for(int j=0; j<curr.size(); j++) {
                    string pattern = curr.substr(0, j) + "*" + curr.substr(j+1);
                    for(auto nei: g[pattern]) {

                        if(visited.find(nei) == visited.end()) {
                            q.push(nei);
                            visited.insert(nei);
                        }

                    }
                }

            }
            
            ans++;

        }

        // not found in graph
        return 0;
        
    }
};
