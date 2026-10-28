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

        // Create a dummy node to simplify merging logic
        ListNode* dummy = new ListNode(); // VERY IMPORTANT
        ListNode* merged = dummy; // Pointer to build the merged list

        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        // Iterate through both lists
        while (curr1 && curr2) {
            if (curr1->val == curr2->val) {
                // Add both nodes to the merged list
                merged->next = new ListNode(curr1->val); // VERY IMPORTANT
                merged = merged->next;
                merged->next = new ListNode(curr2->val);
                merged = merged->next;

                // Advance both pointers
                curr1 = curr1->next;
                curr2 = curr2->next;
            } else if (curr1->val < curr2->val) {
                // Add the smaller node from list1
                merged->next = new ListNode(curr1->val);
                merged = merged->next;
                curr1 = curr1->next;
            } else {
                // Add the smaller node from list2
                merged->next = new ListNode(curr2->val);
                merged = merged->next;
                curr2 = curr2->next;
            }
        }

        // Append the remaining nodes of list1, if any
        while (curr1) {
            merged->next = new ListNode(curr1->val);
            merged = merged->next;
            curr1 = curr1->next;
        }

        // Append the remaining nodes of list2, if any
        while (curr2) {
            merged->next = new ListNode(curr2->val);
            merged = merged->next;
            curr2 = curr2->next;
        }

        // Return the merged list (skipping the dummy node)
        return dummy->next;
    }
};
