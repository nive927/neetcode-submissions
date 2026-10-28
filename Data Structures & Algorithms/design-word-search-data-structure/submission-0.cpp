class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord;

    TrieNode() {
        this->endOfWord = false;
    }
};

class PrefixTree {
public:
    TrieNode *root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        for (auto c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for (auto c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for (auto c : prefix) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
};

class WordDictionary {
public:
    TrieNode *root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *curr = root;
        for (auto c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, this->root);
    }

private:
    bool dfs(string& word, int index, TrieNode* curr) {
        if (index == word.size()) {
            return curr->endOfWord; // even if there is a match, it should be a word ending
        }

        char c = word[index];

        if (c == '.') {
            for (auto& [key, child] : curr->children) {
                if (dfs(word, index + 1, child)) {
                    return true;  // Early stopping
                }
            }
            return false;
        } else {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            return dfs(word, index + 1, curr->children[c]);
        }
    }
};
