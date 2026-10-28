class ListNode {
    public:
    int val;
    ListNode* next;

    ListNode() {
        // val = 0;
        next = nullptr;
    }

    ListNode(int x) {
        val = x;
        next = nullptr;
    }

    ListNode(int x, ListNode* node) {
        val = x;
        next = node;
    }
};

class LinkedList {
public:
    
    ListNode* head;
    ListNode* tail;

    LinkedList() {

        head = nullptr; // if you use the constructor there will be a dummy node
        tail = head; // important

    }

    int get(int index) {

        ListNode* curr = head;

        for(int i=0; i<index && curr != nullptr; i++) {
            curr = curr->next;
        }

        if(curr == nullptr) { return -1;}

        return curr->val;

    }

    void insertHead(int val) {

        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;  

        if (tail == nullptr) { // If the list was empty, update tail
            tail = head;
        }      
    }
    
    void insertTail(int val) {

        ListNode* newNode = new ListNode(val);

        if (tail == nullptr) { // If the list is empty, update head and tail
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    bool remove(int index) {

        if (head == nullptr) return false; // Handle empty list

        // Special case: Removing the head
        if (index == 0) {
            ListNode* nodeToDel = head;
            head = head->next; // Move head to the next node
            if (nodeToDel == tail) { // If the head is also the tail
                tail = nullptr;
            }
            delete nodeToDel;
            return true;
        }

        // Traverse to the node just before the one to delete
        ListNode* curr = head;
        for (int i = 0; i < index - 1 && curr != nullptr; i++) {
            curr = curr->next;
        }

        // If out of range or no node to delete
        if (curr == nullptr || curr->next == nullptr) return false;

        // Delete the node
        ListNode* nodeToDel = curr->next;
        curr->next = nodeToDel->next;

        // Update tail if the deleted node was the tail
        if (nodeToDel == tail) {
            tail = curr;
        }

        delete nodeToDel;
        return true;

    }

    vector<int> getValues() {

        vector<int> values;

        ListNode* curr = head;

        while(curr != nullptr) {
            values.push_back(curr->val);
            curr = curr->next;
        }

        return values;
        
    }
};
