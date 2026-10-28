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
    bool hasCycle(ListNode* head) {

        // NOTE: simple logic but you keep screwing up the if condition for the looping
        // Read well!

        if (!head) { return false; }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast -> next) {

            slow = slow->next;

            fast = fast->next->next;

            if(slow == fast) { return true; }
        }

        return false;
        
    }
};
