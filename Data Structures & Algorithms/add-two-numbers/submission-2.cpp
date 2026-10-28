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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* res = new ListNode(-1);

        int carry = 0;
        int sum = 0;
        int total = 0;
        ListNode *curr1 = l1;
        ListNode *curr2 = l2;
        ListNode *ans = res;
        while(curr1 && curr2) {

            total = curr1->val + curr2 -> val + carry;
            carry = (total > 9) ? 1 : 0;
            sum = (total % 10);

            ans->next = new ListNode(sum);
            

            ans = ans->next;
            curr1 = curr1 -> next;
            curr2 = curr2 -> next;

        }

        while(curr1) {
            total = curr1->val + carry;
            carry = (total > 9) ? 1 : 0;
            sum = (total % 10);

            ans->next = new ListNode(sum);
            ans = ans->next;
            curr1 = curr1->next;
        }

        while(curr2) {
            total = curr2->val + carry;
            carry = (total > 9) ? 1 : 0;
            sum = (total % 10);

            ans->next = new ListNode(sum);
            ans = ans->next;
            curr2 = curr2->next;
        }

        if(carry) {
            ans->next = new ListNode(1);
        }

        return res->next;
        
    }
};
