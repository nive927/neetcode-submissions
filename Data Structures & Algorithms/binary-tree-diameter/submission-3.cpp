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

    int maxDepth(TreeNode *root) {

        if (root == nullptr) {
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        TreeNode *curr;
        int diameter = 0;
        
        if(root == nullptr) {
            return diameter;
        }

        q.push(root);

        while(!q.empty()) {
            curr = q.front();
            q.pop();

            diameter = max(diameter, maxDepth(curr->left) + maxDepth(curr->right));

            if (curr->left) {
                q.push(curr->left);
            }

            if (curr->right) {
                q.push(curr->right);
            }
        }

        return diameter;
    }
};
