/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        unordered_map<Node*, Node*> nodeToCopyMap;
        nodeToCopyMap[nullptr] = nullptr;

        Node* curr = head;

        while(curr != nullptr) {
            Node* newNode = new Node(curr->val);
            nodeToCopyMap[curr] = newNode;
            curr = curr->next;
        }

        Node* copy;

        curr = head;
        while(curr != nullptr) {
            copy = nodeToCopyMap[curr];
            copy->next = nodeToCopyMap[curr->next];
            copy->random = nodeToCopyMap[curr->random];
            curr = curr->next;
        }

        return nodeToCopyMap[head];

        
    }
};
