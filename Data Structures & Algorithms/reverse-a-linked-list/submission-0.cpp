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
    ListNode* reverseList(ListNode* head) {


        ListNode* currNode = head;
        ListNode* prev = nullptr;
        ListNode* temp;

        while(currNode) {

            temp = currNode->next;
            currNode->next = prev;
            prev = currNode;
            currNode = temp;
        }

        return prev;

        
    }
};
