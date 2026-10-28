class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int idx = -1;  // Index of word ending here
    int refs = 0;  // How many words still go through here
};

class PrefixTree {
public:
    TrieNode* root;

    PrefixTree() {
        root = new TrieNode();
    }

    void insert(const string& word, int wordIndex) {
        TrieNode* curr = root;
        curr->refs++;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
            curr->refs++;
        }
        curr->idx = wordIndex;
    }
};

class Solution {
public:
    vector<string> res;
    PrefixTree* trie = new PrefixTree();

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            trie->insert(words[i], i);
        }

        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[0].size(); ++c) {
                dfs(board, trie->root, r, c, words);
            }
        }

        return res;
    }

    void dfs(vector<vector<char>>& board, TrieNode* node, int r, int c, vector<string>& words) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == '*') {
            return;
        }

        char currChar = board[r][c];
        if (node->children.find(currChar) == node->children.end()) {
            return;
        }

        TrieNode* nextNode = node->children[currChar];

        if (nextNode->idx != -1) {
            res.push_back(words[nextNode->idx]);
            nextNode->idx = -1;  // prevent duplicate addition
            nextNode->refs--;
            if (nextNode->refs == 0) {
                node->children.erase(currChar);  // prune dead branch
                return;
            }
        }

        board[r][c] = '*';  // Mark visited

        dfs(board, nextNode, r + 1, c, words);
        dfs(board, nextNode, r - 1, c, words);
        dfs(board, nextNode, r, c + 1, words);
        dfs(board, nextNode, r, c - 1, words);

        board[r][c] = currChar;  // Unmark visited
    }
};
