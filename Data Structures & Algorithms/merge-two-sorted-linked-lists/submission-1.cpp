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

        ListNode* merged = new ListNode(); // val(0), next(nullptr)
        ListNode* mergedHead = merged;

        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        ListNode* newNode;

        // construct merged based on list1 and list2
        while (curr1 != nullptr && curr2 != nullptr) {
            if(curr1->val <= curr2->val) {
                newNode = new ListNode(curr1->val);
                merged->next = newNode;
                curr1 = curr1->next;
            } else {
                newNode = new ListNode(curr2->val);
                merged->next = newNode;
                curr2 = curr2->next;
            }
            merged = merged->next;
        }

        // add remaining in list1 to merged 
        while(curr1 != nullptr) {
            newNode = new ListNode(curr1->val);
            merged->next = newNode;
            merged = merged->next;
            curr1 = curr1->next;
        }

        // add remaining in list2 to merged 
        while(curr2 != nullptr) {
            newNode = new ListNode(curr2->val);
            merged->next = newNode;
            merged = merged->next;
            curr2 = curr2->next;
        }

        if (mergedHead->next == nullptr) {
            return nullptr;
        }

        // return after skipping the dummy head
        return mergedHead->next;

    }
};
