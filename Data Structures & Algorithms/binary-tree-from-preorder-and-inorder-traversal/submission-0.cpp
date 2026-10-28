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

    int preIdx = 0;
    int inIdx = 0;

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int limit) {

        // complete tree processing
        if(preIdx >= preorder.size()) {
            return nullptr;
        }

        // complete left subtree
        if(inorder[inIdx] == limit) {
            inIdx++;
            return nullptr;
        }

        // create the root for the current index
        TreeNode* root = new TreeNode(preorder[preIdx++]);
        root->left = dfs(preorder, inorder, root->val);
        root->right = dfs(preorder, inorder, limit);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        // preorder = [1,2,3,4], inorder = [2,1,3,4]
        return dfs(preorder, inorder, INT_MAX);


    }
};
