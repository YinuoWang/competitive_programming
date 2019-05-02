struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode node;

int linkedListLength(node *head){
    int result = 0;
    node *cur = head;
    while(cur){
        ++result;
        cur = cur->next;
    }
    return result;
}

struct ListNode* middleNode(struct ListNode* head) {
    int listLength = linkedListLength(head);
    int desiredNode = ((listLength % 2 == 0) ? (listLength/2) + 1 : (listLength+1)/2)-1;
    node *cur = head;
    while(desiredNode){
        cur = cur->next;
        --desiredNode;
    }
    return cur;
}