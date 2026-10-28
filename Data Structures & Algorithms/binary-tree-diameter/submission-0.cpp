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
        int diameter = 0;
        diameterDFS(root, diameter); // recursion counter - retains value
        return diameter;
    }

    int diameterDFS(TreeNode *root, int& diameter) { // very important to adress the variable

        if(root == nullptr) {
            return 0;
        }

        int leftDiameter = diameterDFS(root->left, diameter);
        int rightDiameter = diameterDFS(root->right, diameter);

        diameter = max(diameter, leftDiameter + rightDiameter);

        return 1 + max(leftDiameter, rightDiameter);
    }
};
