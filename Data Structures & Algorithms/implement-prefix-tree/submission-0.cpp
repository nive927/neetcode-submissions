
// mug this up - you need to know how to do this from scratch!!!!!!!!
// to solve other problems you will need this!!!!!!!!
class TrieNode {

public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;

};


class PrefixTree {
public:

    TrieNode* root;

    PrefixTree() {

        root = new TrieNode();
        
    }
    
    void insert(string word) {

        TrieNode* currNode = root;

        for(auto c: word) {
            if(currNode->children.find(c) == currNode->children.end()) {
                currNode->children[c] = new TrieNode();
            }

            currNode = currNode->children[c];
        }

        currNode->endOfWord = true;
        
    }
    
    bool search(string word) {

        TrieNode* currNode = root;

        for(auto c: word) {

            if(currNode->children.find(c) == currNode->children.end()) {
                return false;
            } else {
                currNode = currNode->children[c];
            }

        }

        if (currNode->endOfWord == true) {
            return true;
        } else {
            return false;
        }
        
    }
    
    bool startsWith(string prefix) {

        TrieNode* currNode = root;

        for(auto c: prefix) {
            if (currNode->children.find(c) == currNode->children.end()) {
                return false;
            }
        
            currNode = currNode->children[c];
        }

        return true;
        
    }
};
