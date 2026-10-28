class ListNode {

public:
int val;
ListNode* next;
ListNode* prev;

ListNode() {
    next = nullptr;
    prev = nullptr;
}

ListNode(int v, ListNode* nextNode=nullptr, ListNode* prevNode=nullptr) {
    val = v;
    next = nextNode;
    prev = prevNode;
}

};

class Deque {
public:

    ListNode* head;
    ListNode* tail;

    Deque() {

        head = nullptr;
        tail = nullptr;
        
    }

    bool isEmpty() {

        if(head == nullptr && tail == nullptr) {
            return true;
        }

        return false;

    }

    void append(int value) {

        ListNode* newNode = new ListNode(value);

        if(head == nullptr && tail == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        
    }

    void appendleft(int value) {
        
        ListNode* newNode = new ListNode(value);

        if(head == nullptr && tail == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }

        head->prev = newNode;
        newNode->next = head;
        head = newNode;

    }

    int pop() {

        if(isEmpty()) {
            return -1;
        } else {
            ListNode* toDel = tail;

            if (head == tail) { // Single element case
                head = nullptr;
                tail = nullptr;
            } else {
                tail = toDel->prev;
                tail->next = nullptr;
            }

            int val = toDel->val;
            delete toDel;
            return val;
        }
        
    }

    int popleft() {

        if(isEmpty()) {
            return -1;
        } else {
            ListNode* toDel = head;

            if (head == tail) { // Single element case
                head = nullptr;
                tail = nullptr;
            } else {
                head = toDel->next;
                head->prev = nullptr;
            }


            int val = toDel->val;
            delete toDel;
            return val;
        }
        

    }
};
