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

    int diameterOfBinaryTree(TreeNode* root) {

        // NOTE: you completed this using iterative BFS and height check
        // learn the dfs method for quick coding

        if(!root) { return 0; }

        queue<TreeNode*> q;

        q.push(root);

        int currMax = 0;

        while(!q.empty()) {

            TreeNode* currNode = q.front();
            q.pop();

            int leftHeight = height(currNode->left);
            int rightHeight = height(currNode->right);

            currMax = max(currMax, leftHeight + rightHeight);

            if (currNode->left) { q.push(currNode->left); }
            if (currNode->right) { q.push(currNode->right); }

        }

        return currMax;

    }

    int height(TreeNode* root) {

        if(!root) { return 0; }

        return 1 + max(height(root->left), height(root->right));

    }   

};
