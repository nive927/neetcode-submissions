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
    void reorderList(ListNode* head) {

        ListNode* sMid = head;
        ListNode* fMid = head; // WHY?

        // find the middle node - sMid once loop completes
        while(fMid != nullptr && fMid->next != nullptr) {
            fMid = fMid->next->next;
            sMid = sMid->next;
        }


        // reverse 2nd half of LL - after the midpoint
        ListNode* curr = sMid->next; 

        // disconnect the first half from the second - VERY IMPORTANT
        sMid->next = nullptr; 

        ListNode* prev = nullptr;
        ListNode* nextNode;

        while(curr != nullptr) {

            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;

        }

        // curr is now nullptr
        // prev is the head of the reversed 2nd half of the list

        ListNode* h2 = prev;
        ListNode* h1 = head;

        ListNode *nxt1, *nxt2;

        while(h2 != nullptr) {

            // store the next nodes
            nxt1 = h1->next;
            nxt2 = h2->next;
            
            // update the next pointers for the reordered list
            h1->next = h2;
            h2->next = nxt1;

            // advance by one pointer for both lists
            h1 = nxt1;
            h2 = nxt2;

        }

    }
};
