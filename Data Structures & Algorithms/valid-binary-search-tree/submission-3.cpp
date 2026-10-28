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
    bool isValidBST(TreeNode* root) {

        // check for BST conditions using iteration - BFS
        // BST condition: left_child < root < right_child

        if(root == nullptr) {
            return true;
        }

        queue<tuple<TreeNode*, long, long>> q;
        q.push(make_tuple(root, LONG_MIN, LONG_MAX));

        while(!q.empty()) {

            auto [node, left, right] = q.front();
            q.pop();

            if(!(node->val > left && node->val < right)) {
                return false;
            }

            if(node->left != nullptr) {
                q.push(make_tuple(node->left, left, node->val));
            }

            if(node->right != nullptr) {
                q.push(make_tuple(node->right, node->val, right));                
            }


        }      

        return true;

    }
};


