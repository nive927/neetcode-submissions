class PrefixTree {
public:

    class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        bool endOfWord;

        TrieNode() {
            endOfWord = false;
        }
    };

    TrieNode *root;
    PrefixTree() {

        root = new TrieNode();
        
    }
    
    void insert(string word) {

        TrieNode *curr = root;
        for(auto c: word) {
            if(curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->endOfWord = true;
        
    }
    
    bool search(string word) {

        TrieNode *curr = root;
        for(auto c: word) {
            if(curr->children.find(c) == curr->children.end()) {
                return false;
            }

            curr = curr->children[c];
        }

        if(curr->endOfWord) {
            return true;
        }

        return false;
        
    }
    
    bool startsWith(string prefix) {

        TrieNode *curr = root;
        for(auto c: prefix) {
            if(curr->children.find(c) == curr->children.end()) {
                return false;
            }

            curr = curr->children[c];
        }

        return true;
        
    }
};
