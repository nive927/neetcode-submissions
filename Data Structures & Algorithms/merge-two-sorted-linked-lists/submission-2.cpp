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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // NOTE: you need to remember how to start the merge head
        // you need to remember to advance the pointers - if you forget, you get the stderr error

        ListNode *mergedHead = new ListNode(0);
        ListNode *h1 = list1, *h2 = list2, *merged = mergedHead;
        ListNode *temp;
        
        while(h1 != nullptr && h2 != nullptr) {

            if(h1->val <= h2->val) {
                temp = new ListNode(h1->val);
                merged->next = temp;
                h1 = h1->next;
            } else if(h1->val > h2->val) {
                temp = new ListNode(h2->val);
                merged->next = temp;
                h2 = h2->next;
            }

            merged = merged->next;

        }

        while (h1 != nullptr) {
            temp = new ListNode(h1->val);
            merged->next = temp;
            merged = merged->next;
            h1 = h1->next;
        }

        while(h2 != nullptr) {
            temp = new ListNode(h2->val);
            merged->next = temp;
            merged = merged->next;
            h2 = h2->next;
        }

        return mergedHead->next;

    }
};
