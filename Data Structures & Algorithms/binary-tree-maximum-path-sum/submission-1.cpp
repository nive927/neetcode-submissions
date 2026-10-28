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
    int maxPathSum(TreeNode* root) {

        // init: assume root in maxPathSum (max(res, pathSum) will overwrite later if false)
        int res = root->val;
        dfs(root, res);
        return res;

    }

    // don't forget to pass by reference!!!
    int dfs(TreeNode* root, int& res) {

        if(root == nullptr) {
            return 0;
        }

        // Find the max val on the left and the right:
        // this makes sense when you think about the leaf
        // and work upwards - iPad notes has details
        int leftMax = max(dfs(root->left, res), 0);
        int rightMax = max(dfs(root->right, res), 0);

        res = max(res, leftMax + root->val + rightMax);

        // you need to return the side that has the maxPath so far
        // to propagate up
        return root->val + max(leftMax, rightMax);

    }
};
