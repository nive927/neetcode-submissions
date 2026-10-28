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

class Solution {
public:

    int maxDepth(TreeNode* root) {

        // NOTE: you got the recursion logic and code right but you didn't understand how 

        if(!root) { return 0; }
        
        int currMaxDepth = max(maxDepth(root->left), maxDepth(root->right));

        return 1 + currMaxDepth;
    }
};
