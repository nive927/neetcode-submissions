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
using Node = ListNode;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        Node* curr = head;
        Node* prev = nullptr;
        Node* temp;

        while(curr != nullptr) {

            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;

    }
};
