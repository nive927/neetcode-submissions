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

    void dfs(TreeNode* root, int &count, int maxVal) {

        if(root == nullptr) {
            return;
        }

        // if(root->left == nullptr && root->right == nullptr) {

        // }

        maxVal = max(root->val, maxVal);
        count += (root->val >= maxVal) ? 1 : 0;

        dfs(root->left, count, maxVal);
        dfs(root->right, count, maxVal);

    }

    int goodNodes(TreeNode* root) {
     
        int countGoodNodes = 0;
        dfs(root, countGoodNodes, root->val);
        return countGoodNodes;

    }
};
