/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if(root == nullptr) {
            return "N";
        }

        string serial = "";

        // start bfs
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            auto node = q.front();
            q.pop();

            if(node == nullptr) {
                serial += "N,";
            } else {
                serial += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }

        }

        return serial;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        stringstream ss(data);
        string word;

        getline(ss, word, ',');
        if(word == "N") {
            return nullptr;
        }

        TreeNode *root = new TreeNode(stoi(word));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            auto node = q.front();
            q.pop();

            // handle left child
            getline(ss, word, ',');
            if(word != "N") {
                node->left = new TreeNode(stoi(word));
                q.push(node->left);
            }

            // handle right child
            getline(ss, word, ',');
            if(word != "N") {
                node->right = new TreeNode(stoi(word));
                q.push(node->right);
            }

        }

        return root;
        
    }
};
