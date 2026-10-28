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
    int height(TreeNode* root) {

        if(!root) { return 0; }

        return 1 + max(height(root->left), height(root->right));

    }
    
    bool isBalanced(TreeNode* root) {

        if(!root) { return true; }

        int leftHeight = 0;
        int rightHeight = 0;

        if (root->left) { leftHeight = height(root->left); }
        if (root->right) { rightHeight = height(root->right); }

        if(abs(leftHeight - rightHeight) > 1) { return false; }

        return isBalanced(root->left) && isBalanced(root->right);
        
    }
};
