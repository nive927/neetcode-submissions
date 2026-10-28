/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    struct Compare {
        bool operator() (ListNode *n1, ListNode *n2) {
            return n1->val > n2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if (lists.empty()) {
            return nullptr;
        }

        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        for(auto lHead: lists) {

            if(lHead != nullptr) {
                minHeap.push(lHead);
            }

        }

        ListNode* result = new ListNode();
        ListNode* curr = result;

        while(!minHeap.empty()) {
            ListNode *topNode = minHeap.top();
            minHeap.pop();
            if(topNode->next != nullptr) {
                minHeap.push(topNode->next);
            }
            curr->next = topNode;
            curr = curr->next;
        }


        return result->next;

        
    }
};
