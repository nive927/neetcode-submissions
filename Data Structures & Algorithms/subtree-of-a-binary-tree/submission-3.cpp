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

    bool isSameTree(TreeNode* first, TreeNode* second) {

        if(!first && second || first && !second) { return false; }

        if(!first && !second) { return true; }

        if(first->val != second->val) { return false; }

        return isSameTree(first->left, second->left) && isSameTree(first->right, second->right);

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(!root && !subRoot) { return true; }

        if(!root && subRoot || root && !subRoot) { return false; }

        if(isSameTree(root, subRoot)) { return true; }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
    }
};


























// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {

//         if (p == nullptr && q == nullptr) {
//             return true;
//         }

//         if ((p != nullptr) && (q != nullptr) && (p->val == q->val)) {
//             return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//         }

//         return false;
//     }

//     bool isSubtree(TreeNode* root, TreeNode* subRoot) {

//         // if ((root == nullptr) && (subRoot == nullptr)) {
//         //     return true;
//         // }

//         // if ((root != nullptr) && (subRoot == nullptr)) {
//         //     return true;
//         // }

//         if (subRoot == nullptr) {
//             return true;
//         }

//         if (root == nullptr) {
//             return false;
//         }

//         if (isSameTree(root, subRoot)) {
//             return true;
//         }

//         return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
//     }
// };
