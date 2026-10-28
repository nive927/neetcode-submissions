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

        // NOTE: simple logic but you keep screwing up the init & if conditions for the looping
        // Read well - you only need the fast pointer for the check!
        // if condition only tracks fast pointer - don't bother checking slow

        ListNode *slow = head, *fast = head;

        while(fast && fast->next) {

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        }

        return false;
        
    }
};
