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

    TreeNode* invertTree(TreeNode* root) {

        if(root == nullptr) {
            return nullptr;
        }

        TreeNode* newNode = new TreeNode(root->val);

        newNode->left = invertTree(root->right);
        newNode->right = invertTree(root->left);

        return newNode;

    }





















    // TreeNode* invertTree(TreeNode* root) {

    //     // NOTE: you don't figure out how to return the values
    //     // you get the recursion call logic correctly

            // // NOTE: do bfs or dfs if you don't remember recursive

        // for recursive you need to create a new node to return

    //     if (!root) {
    //         return nullptr;
    //     }

    //     TreeNode* node = new TreeNode(root->val);

    //     node->left = invertTree(root->right);
    //     node->right = invertTree(root->left);

    //     return node;
    // }
};
