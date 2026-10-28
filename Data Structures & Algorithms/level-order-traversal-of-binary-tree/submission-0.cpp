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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        // Iterative solution: BFS
        vector<vector<int>> bfs;
        deque<TreeNode*> q;

        // you need to first insert the root
        if (root != NULL) { q.push_back(root); }

        while(!q.empty()) {

            // you need to restrict how much of the queue you are traversing
            // you only need to pop until one level is completed
            // so you need to set the length you are going to cover inside the queue
            // this way you won't pop nodes on another level
            int window = q.size(); 

            // Populate the order for each level
            vector<int> currLevel;

            for(int i=0; i<window; i++) {

                // store the current node & pop it from the FRONT
                TreeNode* currNode = q.front();
                q.pop_front();

                // populate the level
                currLevel.push_back(currNode->val);

                // push the left and right children if they exist
                // NOTE: because of setting length before the second loop,
                // they will not be iterated in this order
                if (currNode->left != NULL) { q.push_back(currNode->left); }
                if (currNode->right != NULL) { q.push_back(currNode->right); }

            }

            // save the currLevel into the final bfs traversal vector
            bfs.push_back(currLevel);

        }

        return bfs;

    }
};
